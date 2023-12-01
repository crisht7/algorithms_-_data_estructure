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
 * @brief Inserta una palabra en el árbol Trie.
 * 
 * Inserta una palabra en el árbol Trie, construyendo los nodos
 * necesarios para representar cada carácter de la palabra.
 * 
 * @param palabra Palabra que se va a insertar en el árbol Trie.
 */
void ArbolTrie::insertar(string palabra) {
    
}

/**
 * @brief Consulta si una palabra está presente en el árbol Trie.
 * 
 * Verifica si una palabra está presente en el árbol Trie.
 * 
 * @param palabra Palabra a consultar en el árbol Trie.
 * @return true si la palabra está presente y marcada como final de palabra, false en caso contrario.
 */
bool ArbolTrie::consultar(string palabra) {
    NodoTrie* temporal = raiz->sig;
    for(char c : palabra){
        while(temporal != nullptr && temporal->caracter < c){
            temporal = temporal->sig;
        }
    }
    if(temporal!=nullptr && temporal->caracter == c){
        
    }
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
        if (nodoActual->hijos.find(c) == nodoActual->hijos.end()) {
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