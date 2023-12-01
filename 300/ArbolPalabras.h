#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <unordered_map>

using namespace std;

class NodoTrie {
private:
    char caracter;
    NodoTrie* sig;
    NodoTrie* ptr;
public:
    NodoTrie(char c);
friend class ArbolTrie;
};

class ArbolTrie {
private:
    NodoTrie* raiz;
    const static char CARACTER_NULO = '\0';

public:
    ArbolTrie();
    void insertar(string palabra);
    bool consultar(string palabra);
    bool existePrefijo(string prefijo);
    int getNumeroPalabras();
    void vaciar();
private:
    void ponMarca(NodoTrie nodo);
    void quitaMarca(NodoTrie nodo);
    bool hayMarca(NodoTrie nodo);
    NodoTrie* buscarUltimoNodo(string palabra);
    int contarNumeroPalabrasRecursivo(NodoTrie* nodo);
    void vaciarRecursivo(NodoTrie* nodo);
};

#endif  // TRIE_H
