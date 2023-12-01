#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "TablaHash.h"
#include "ArbolPalabras.h"
#include <string>
#include <set>

using namespace std;

class Diccionario {
private:
    TablaHash tablaDispersion; //ahora mismo no se utiliza.
    ArbolTrie arbolPalabras;
public:
    Diccionario();
    void insertarPalabra(string palabra);
    bool consultarPalabra(string palabra);
    void vaciar();
    int getTamanio();
    static string normalizarPalabra(string texto); 
    string getPalabraMasLarga(const string& prefijo);
};
#endif