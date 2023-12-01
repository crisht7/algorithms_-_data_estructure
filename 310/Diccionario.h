#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "TablaHash.h"
#include "ArbolPalabras.h"

#include <string>
#include <algorithm> //para poder usar sort

using namespace std;

class Diccionario {
private:
    TablaHash tablaDispersion;
    ArbolTrie arbolPalabras;
public:
    Diccionario();
    void insertarPalabra(string palabra);
    bool consultarPalabra(string palabra);
    void vaciar();
    int getTamanio();
    static string normalizarPalabra(string texto);
    string getJuanagrama(string palabra);
    string getPalabraMasLarga(const string& prefijo);
};

#endif