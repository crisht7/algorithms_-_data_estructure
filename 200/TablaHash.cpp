#include "TablaHash.h"

/**
 * @brief Constructor de la clase TablaHash.
 * 
 * Inicializa una instancia de la clase TablaHash, establece el número de elementos
 * en la tabla como cero y ajusta el tamaño inicial de la tabla utilizando la constante TAMANIO_INICIAL.
 *
 * @param None
 * 
 * @return None
 */
TablaHash::TablaHash(){
    numeroElementos = 0;
    tabla.resize(TAMANIO_INICIAL);
}

/**
 * @brief Expande la tabla hash actual, duplicando su tamaño y reorganizando los elementos.
 * 
 * @param None
 * 
 * @return None
 */ 
void TablaHash::expandirTabla() {
    int newSize = tabla.size() * 2;
    vector<list<Elemento>> newTable(newSize);

    for (const auto& bucket : tabla) {
        for (const Elemento& elemento : bucket) {
            int newIndex = hash(elemento.clave, newSize);
            newTable[newIndex].push_back(elemento);
        }
    }

    tabla = move(newTable);
}

/**
 * Función de hash DJB2, que según nuestra investigación es de las mejores para calcular hashs de strings.
 * Utiliza una combinación de desplazamientos y sumas para lograr una dispersión efectiva.
 * 
 * @param cadena La cadena de entrada para calcular el hash.
 * 
 * @param size Tamaño de la tabla de dispersión.
 * 
 * @return Valor hash calculado para la cadena.
 */
unsigned int TablaHash::hash(string cadena, int size) {
    unsigned int hash = 5381;

    for (char caracter : cadena) {
        hash = ((hash << 5) + hash) + static_cast<unsigned int>(caracter);
    }

    return hash % size;
}

/**
 * @brief Inserta un nuevo elemento en la tabla hash.
 * 
 * Inserta un nuevo elemento en la tabla hash. Si la carga de la tabla
 * supera el umbral del FACTOR_CARGA la tabla se expande utilizando la función "expandirTabla" para evitar
 * colisiones excesivas y mantener un rendimiento eficiente.
 * 
 * @param key Clave del elemento a insertar.
 * @param valor Valor asociado a la clave.
 * 
 * @return None
 */
void TablaHash::insertar(string key, int valor) {
    if (static_cast<double>(numeroElementos) / tabla.size() > FACTOR_CARGA) {
        expandirTabla();
    }
    int indice = hash(key, tabla.size());
    if(!existeClave(key)){
        tabla[indice].push_back(Elemento(key, valor));
        numeroElementos++;
    }
}

/**
 * @brief Devuelve el valor asociado a una clave.
 * 
 * @param key Clave a verificar.
 * 
 * @return Valor asociado a la clave, devuelve FALTA_COINCIDENCIA si no se encuentra.
 */ 
int TablaHash::buscar(string key) {
    int indice = hash(key, tabla.size());
    for (const Elemento& elemento : tabla[indice]) {
        if (elemento.clave == key) {
            return elemento.valor;
        }
    }
    return FALTA_COINCIDENCIA; 
}

/**
 * @brief Verifica si una clave está presente en la tabla hash.
 * 
 * @param key Clave a verificar.
 * 
 * @return Devuelve `true` si la clave está presente en la tabla, de lo contrario, devuelve `false`.
 */ 
bool TablaHash::existeClave(const string& key) {
    int indice = hash(key, tabla.size());
    for (const Elemento& elemento : tabla[indice]) {
        if (elemento.clave == key) {
            return true;
        }
    }
    return false; 
}

/**
 * @brief Elimina un elemento de la tabla hash dado su clave.
 * 
 * @param key Clave del elemento a eliminar.
 * 
 * @return None
 */
void TablaHash::borrar(string key) {
    int indice = hash(key, tabla.size());
    auto it = tabla[indice].begin();
    while (it != tabla[indice].end()) {
        if (it->clave == key) {
            it = tabla[indice].erase(it);
            numeroElementos--;
            return;
        } else {
            ++it;
        }
    }
}

/**
 * @brief Elimina todos los elementos de la tabla hash.
 * 
 * @param None
 * 
 * @return None
 */
void TablaHash::vaciar() {
    for (auto& cubeta: tabla)
    {
        cubeta.clear();
    }
    numeroElementos = 0;
}

/**
 * @brief Obtiene el número de elementos en la tabla hash.
 * 
 * @return Número de elementos en la tabla hash.
 */
int TablaHash::getTamanio(){
    return numeroElementos;
}