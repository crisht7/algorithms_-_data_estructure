#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "TablaHash.h"
#include <string>

#include <algorithm> //para poder usar sort

using namespace std;

class Diccionario {
private:
    TablaHash tablaDispersion;
public:
    Diccionario();
    void insertarPalabra(string palabra);
    bool consultarPalabra(string palabra);
    void vaciar();
    int getTamanio();
    static string normalizarPalabra(string texto);
    string getJuanagrama(string palabra);  
};

#endif