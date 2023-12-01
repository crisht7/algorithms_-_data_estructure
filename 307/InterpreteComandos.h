#ifndef INTERPRETECOMANDOS_H
#define INTERPRETECOMANDOS_H

#include <string>
#include "Diccionario.h"
#include <iostream>
#include <sstream>
using namespace std;

class InterpreteComandos{
private:
    Diccionario diccionario;
    void vaciarDiccionario();
    void buscarPalabra(string palabra);
    void insertarPalabras(string entrada);
    void alocado(string palabra);
    void partidas(string entrada);
    void cesar(string palabra);
    void juanagra(string palabra);
    void consome(string palabra);
    void alarga(string palabra);
    void saco(string entrada);
    void alargaPalabra(const string& prefijo);
    void salir();
public:
    InterpreteComandos();
    void interpretarComando(string comando);

};

#endif