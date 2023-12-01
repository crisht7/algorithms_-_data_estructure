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
    tablaJuanagrama.resize(TAMANIO_INICIAL);
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
    vector<set<string>> newTable(newSize);
    vector<set<string>> nuevaJuanagrama(newSize);

    for (const auto& cubeta : tabla) {
        for (const string& stringActual : cubeta) {
            int newIndex = hash(stringActual, newSize);
            newTable[newIndex].insert(stringActual);
        }
    }

    for (const auto& cubeta : tablaJuanagrama) {
        for (const string palabra: cubeta) {
            int newIndex = hashJuanagrama(palabra, newSize);
            nuevaJuanagrama[newIndex].insert(palabra);
        }
    }
    
    tabla = move(newTable);
    tablaJuanagrama = move(nuevaJuanagrama);
}

/**
 * @brief Encuentra el juanagrama de una palabra.
 * 
 * Utiliza el hash de la palabra original para acceder a la lista de posibles anagramas
 * y encuentra el juanagrama.
 * 
 * @param palabra La palabra para la cual se busca un juananagrama.
 * 
 * @return Un string que representa un juanagrama de la palabra dada, o una cadena vacía si no se encuentra ninguno.
 */
string TablaHash::encontrarJuanagrama(const string& palabra){ //const para que no se modifique con el sort
    ///es una buena práctica para no alterar la original
    string palabraCopia = palabra;
    
    //ordenamos los carácteres de la palabra
    sort(palabraCopia.begin(), palabraCopia.end());

    int indice = hashJuanagrama(palabra, tabla.size());

    for(const string& palabra: tablaJuanagrama[indice]){
            string palabraActual;
            palabraActual = palabra;

            string copiaPalabra;
            copiaPalabra = palabraActual;

            //ordena los caracteres de la palabra candidata
            sort(palabraActual.begin(), palabraActual.end());

            //compara las palabras ordenadas
            if (palabraActual == palabraCopia) {
                return copiaPalabra;
            }
    }

    //si no se encuentra
    return "";
    
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
    unsigned int hash = VALOR_INICIAL_HASH;

    for (char caracter : cadena) {
        hash = ((hash << BASE_HASH) + hash) + static_cast<unsigned int>(caracter);
    }

    return hash % size;
}

/**
 * @brief Función de hash para palabras en el contexto de búsqueda de anagramas.
 * 
 * Utiliza la técnica de suma de valores ASCII de los caracteres de la cadena combinada con su potencia.
 * 
 * @param cadena La cadena de entrada para calcular el hash.
 * 
 * @param size Tamaño de la tabla de dispersión.
 * 
 * @return Valor hash calculado para la cadena en el rango [0, size-1].
 */
unsigned int TablaHash::hashJuanagrama(string cadena, int size) {
    unsigned int hash = 0;

    for (char caracter : cadena) {
        hash += pow(getValorCaracter(caracter), 2);
    }

    return hash % size;
}

/*
 * @brief Función hash para la tabla juanagrama.
 *
 * Hace una combinación de suma ascii con potencia para un mejor rendimiento.
 * 
 * @param
*/

/**
 * @brief Función para obtener valor de caracter teniendo en cuenta aquellos con doble byte.
 * 
 * @param caracter Caracter a calcular su valor.
 * 
 * @return Valor del caracter
 */
unsigned int TablaHash::getValorCaracter(char caracter){
    if (caracter=='\xC3' || caracter=='\xBC' || caracter=='\x9C' || caracter=='\xB1' || caracter=='\x91'){
        return VALOR_CARACTERES_DOBLE_BYTE; //devuelvo esta constante cuando es un caracter con dos bytes
    }
    else{
        return caracter;
    }
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
void TablaHash::insertar(string palabra) {
    if (static_cast<double>(numeroElementos) / tabla.size() > FACTOR_CARGA) {
        expandirTabla();
    }
    int indice = hash(palabra, tabla.size());
    int indiceJuanagrama = hashJuanagrama(palabra, tabla.size());

    if(!existePalabra(palabra)){
        tabla[indice].insert(palabra);
        tablaJuanagrama[indiceJuanagrama].insert(palabra);
        numeroElementos++;
    }
}

/**
 * @brief Verifica si una palabra está presente en la tabla hash.
 * 
 * @param key Clave a verificar.
 * 
 * @return Devuelve `true` si la clave está presente en la tabla, de lo contrario, devuelve `false`.
 */ 
bool TablaHash::existePalabra(const string& palabra) {
    int indice = hash(palabra, tabla.size());
    for (const string& palabraActual : tabla[indice]) {
        if (palabraActual == palabra) {
            return true;
        }
    }
    return false; 
}

/**
 * @brief Elimina un elemento de la tabla
 * 
 * @param key Elemento a eliminar.
 * 
 * @return None
 */
void TablaHash::borrar(string palabra) {
    int indice = hash(palabra, tabla.size());
    int numEliminados = tabla[indice].erase(palabra);
    if(numEliminados!=0){
        numeroElementos--;
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