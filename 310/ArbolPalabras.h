#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class NodoTrie {
public:
    char caracter;
    NodoTrie* sig;
    NodoTrie* ptr;
    map<char, NodoTrie*> hijos;
    bool esFinPalabra;

    NodoTrie(char c);
    ~NodoTrie();
};

class ArbolTrie {
private:
    NodoTrie* raiz;
    const static char CARACTER_NULO = '\0';
    void ponMarca(NodoTrie nodo);
    void quitaMarca(NodoTrie nodo);
    bool hayMarca(NodoTrie nodo);
    NodoTrie* buscarUltimoNodo(string palabra);
    int contarNumeroPalabrasRecursivo(NodoTrie* nodo);
    void vaciarRecursivo(NodoTrie* nodo);
    NodoTrie* obtenerPadre(NodoTrie* nodo);
    void construirPalabrasConPrefijo(NodoTrie* nodo, string prefijo, string palabraActual, vector<string>& palabras);
    string encontrarPalabraMasLarga(const vector<string>& palabras);
    int getLongitudPalabra(string palabra);
public:
    ArbolTrie();
    ~ArbolTrie();
    string mayorPalabraConPrefijo(string prefijo);
    void insertar(string palabra);
    bool consultar(string palabra);
    bool existePrefijo(string prefijo);
    int getNumeroPalabras();
    void vaciar();
};

#endif  // TRIE_H
