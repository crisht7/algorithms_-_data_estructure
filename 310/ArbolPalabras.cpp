#include "ArbolPalabras.h"

/**
 * @brief Constructor de la clase NodoTrie.
 * 
 * Inicializa un nodo del árbol Trie con un caracter específico.
 * 
 * @param c Caracter que representa el nodo.
 */
NodoTrie::NodoTrie(char c){
    caracter = c;
    esFinPalabra = false;
}

/**
 * @brief Destructor de la clase NodoTrie.
 */
NodoTrie::~NodoTrie() {
    for (auto& par : hijos) {
        delete par.second;
    }
}

/**
 * @brief Constructor de la clase ArbolTrie.
 * 
 * Inicializa un árbol Trie creando un nodo raíz con un carácter nulo.
 */
ArbolTrie::ArbolTrie() {
    raiz = new NodoTrie(CARACTER_NULO);
}

/**
 * @brief Destructor de la clase ArbolTrie.
 */
ArbolTrie::~ArbolTrie() {
    delete raiz;  // Llama al destructor de la raíz, que a su vez eliminará todos los nodos descendientes
}

/**
 * @brief Inserta una palabra en el árbol Trie.
 * 
 * Inserta una palabra en el árbol Trie, construyendo los nodos
 * necesarios para representar cada carácter de la palabra.
 * 
 * @param palabra Palabra que se va a insertar en el árbol Trie.
 */
void ArbolTrie::insertar(string palabra) {
    NodoTrie* nodoActual = raiz;

    for (char c : palabra) {
        if (nodoActual->hijos.find(c) == nodoActual->hijos.end()) { // si no existe
            nodoActual->hijos[c] = new NodoTrie(c);
        }

        nodoActual = nodoActual->hijos[c];
    }

    nodoActual->esFinPalabra = true;
}

/**
 * @brief Consulta si una palabra está presente en el árbol Trie.
 * 
 * @param palabra Palabra a consultar en el árbol Trie.
 * @return true si la palabra está presente y marcada como final de palabra, false en caso contrario.
 */
bool ArbolTrie::consultar(string palabra) {
    NodoTrie* nodo = buscarUltimoNodo(palabra);
    return (nodo != nullptr && nodo->esFinPalabra);
}

/**
 * @brief Verifica la existencia de un prefijo en el árbol Trie.
 * 
 * Comprueba si hay alguna palabra en el árbol Trie que comienza
 * con el prefijo proporcionado.
 * 
 * @param prefijo Prefijo a verificar en el árbol Trie.
 * @return true si existe al menos una palabra con el prefijo, false en caso contrario.
 */
bool ArbolTrie::existePrefijo(string prefijo) {
    return (buscarUltimoNodo(prefijo) != nullptr);
}

/**
 * @brief Busca el último nodo de una palabra en el árbol Trie.
 * 
 * Busca y devuelve el último nodo del árbol Trie que representa
 * la palabra completa.
 * 
 * @param palabra Palabra cuyo último nodo se va a buscar en el árbol Trie.
 * @return Puntero al último nodo de la palabra en el árbol Trie o nullptr si la palabra no está presente.
 */
NodoTrie* ArbolTrie::buscarUltimoNodo(string palabra) {
    NodoTrie* nodoActual = raiz;

    for (char c : palabra) {
        if (nodoActual->hijos.find(c) == nodoActual->hijos.end()) { // si no existe
            return nullptr;
        }

        nodoActual = nodoActual->hijos[c];
    }

    return nodoActual;
}

/**
 * @brief Obtiene el número total de palabras en el árbol Trie.
 * 
 * @return Número total de palabras en el árbol Trie.
 */
int ArbolTrie::getNumeroPalabras() {
    return contarNumeroPalabrasRecursivo(raiz);
}

/**
 * @brief Contador recursivo del número total de palabras en el árbol Trie.
 * 
 * Realiza un recorrido recursivo del árbol Trie, contando el número
 * total de palabras almacenadas en el árbol. Es utilizada internamente por la función
 * "getNumeroPalabras".
 * 
 * @param nodo Nodo actual en el recorrido del árbol.
 * @return Número total de palabras desde el nodo actual en el árbol Trie.
 */
int ArbolTrie::contarNumeroPalabrasRecursivo(NodoTrie* nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    int contador = 0;

    if (nodo->esFinPalabra) {
        contador++;
    }

    for (auto& hijo : nodo->hijos) {
        contador += contarNumeroPalabrasRecursivo(hijo.second);
    }

    return contador;
}

/**
 * @brief Vacía completamente el árbol Trie.
 */
void ArbolTrie::vaciar() {
    vaciarRecursivo(raiz);
}

/**
 * @brief Vacia un nodo y sus descendientes en el árbol Trie.
 * 
 * Realiza un recorrido recursivo del árbol Trie, liberando la memoria
 * asociada a cada nodo y eliminando los enlaces entre nodos. Es utilizada internamente
 * por la función "vaciar".
 * 
 * @param nodo Nodo actual en el recorrido del árbol que se va a vaciar.
 */
void ArbolTrie::vaciarRecursivo(NodoTrie* nodo) {
    if (nodo == nullptr) {
        return;
    }

    for (auto& par : nodo->hijos) {
        vaciarRecursivo(par.second);
        delete par.second;
    }

    nodo->hijos.clear();
    nodo->esFinPalabra = false;
}

/**
 * @brief Marca un nodo como el final de una palabra en el árbol Trie.
 * @param nodo Nodo que se va a marcar como el final de una palabra.
 */
void ArbolTrie::ponMarca(NodoTrie nodo){
    nodo.esFinPalabra = true;
}

/**
 * @brief Quita un nodo como el final de una palabra en el árbol Trie.
 * @param nodo Nodo que se va a quitar como el final de una palabra.
 */
void ArbolTrie::quitaMarca(NodoTrie nodo){
    nodo.esFinPalabra = false;
}

/**
 * @brief Consulta si un nodo es el final de una palabra en el árbol Trie.
 * @param nodo Nodo a consultar.
 * @return true si tiene marca, false si no la tiene.
 */
bool ArbolTrie::hayMarca(NodoTrie nodo){
    return nodo.esFinPalabra;
}

/**
 * @brief Encuentra la mayor palabra con un determinado prefijo en el árbol Trie.
 * 
 * Dado un prefijo, busca la mayor palabra en el árbol Trie que comienza con ese prefijo.
 * 
 * @param prefijo Prefijo para buscar la mayor palabra.
 * @return La mayor palabra con el prefijo proporcionado, o una cadena vacía si no hay ninguna palabra con ese prefijo.
 */
string ArbolTrie::mayorPalabraConPrefijo(string prefijo) {
    NodoTrie* nodoPrefijo = buscarUltimoNodo(prefijo);

    if (nodoPrefijo == nullptr) { // No hay ninguna palabra con el prefijo proporcionado.
        return "";
    }

    vector<string> palabrasConPrefijo;

    construirPalabrasConPrefijo(nodoPrefijo, prefijo, "", palabrasConPrefijo);

    string mayorPalabra = encontrarPalabraMasLarga(palabrasConPrefijo);

    return mayorPalabra;
}

/**
 * @brief Construye todas las palabras que comienzan con el prefijo.
 * 
 * @param nodo Nodo a partir del cual se construirán las palabras.
 * @param prefijo Prefijo.
 * @param palabraActual Parcialmente construida palabra actual.
 * @param palabras Lista para almacenar las palabras.
 */
void ArbolTrie::construirPalabrasConPrefijo(NodoTrie* nodo, string prefijo, string palabraActual, vector<string>& palabras) {
    if (nodo->esFinPalabra) {
        palabras.push_back(prefijo + palabraActual);
    }

    for (const auto& pareja : nodo->hijos) {
        construirPalabrasConPrefijo(pareja.second, prefijo, palabraActual + pareja.first, palabras);
    }
}

/**
 * @brief Encuentra la palabra más larga o la primera en orden alfabético en caso de empate.
 * 
 * @param palabras Lista de palabras para buscar la mayor.
 * @return La palabra más larga o la primera en orden alfabético en caso de empate.
 */
string ArbolTrie::encontrarPalabraMasLarga(const vector<string>& palabras) {
    if (palabras.empty()) {
        return "";
    }

    // Ordena la lista de palabras alfabéticamente.
    vector<string> palabrasOrdenadas = palabras;
    sort(palabrasOrdenadas.begin(), palabrasOrdenadas.end());

    
    string mayorPalabra = palabrasOrdenadas[0];
    // Encuentra la palabra más larga.
    for (const string& palabra : palabrasOrdenadas) {
        if (getLongitudPalabra(palabra) > getLongitudPalabra(mayorPalabra)) { //ERROR: piensa que ñ y ü son dos
            mayorPalabra = palabra;
        }
    }

    return mayorPalabra;
}

int ArbolTrie::getLongitudPalabra(string palabra){
    int numeroCaracteres = 0;
    for(int i=0; i<palabra.length(); i++){
        if (palabra[i]=='\xC3')
        {
            i++;
        }
        numeroCaracteres++;
    }
    return numeroCaracteres;
}

/**
 * @brief Obtiene el nodo padre de un nodo en el árbol Trie.
 * 
 * @param nodo Nodo para el cual se va a obtener el padre.
 * @return Puntero al nodo padre o nullptr si el nodo es la raíz.
 */
NodoTrie* ArbolTrie::obtenerPadre(NodoTrie* nodo) {
    if (nodo == raiz) {
        return nullptr; // El nodo es la raíz, no tiene padre.
    }

    // Busca el padre del nodo recorriendo hacia arriba en el árbol Trie.
    NodoTrie* padre = raiz;
    for (const auto& pareja : nodo->hijos) { // Si uno de sus hijos es el que buscamos, entonces este es el padre
        if (pareja.second == nodo) {
            break;
        }
        padre = pareja.second;
    }

    return padre;
}