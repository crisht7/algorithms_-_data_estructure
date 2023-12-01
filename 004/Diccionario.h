#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <string>
#include <set>

using namespace std;


class Diccionario {
private:
    set<string> listaPalabras;
public:
    Diccionario();
    void insertarPalabra(string palabra);
    bool consultarPalabra(string palabra);
    void vaciar();
    int getTamanio();
    static string normalizarPalabra(string texto);    
};

#endif
