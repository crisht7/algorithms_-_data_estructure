#ifndef TABLAHASH_H
#define TABLAHASH_H

#include <vector>
#include <list>
#include <string>
#include <set>
#include <algorithm> //para poder usar sort
#include <math.h>

using namespace std;

class TablaHash {
private:
    static const int TAMANIO_INICIAL = 1000;
    static constexpr double FACTOR_CARGA = 0.7;
    static const int FALTA_COINCIDENCIA = -1;
    static const int VALOR_INICIAL_HASH = 5381;
    static const int BASE_HASH = 20;
    static const int VALOR_CARACTERES_DOBLE_BYTE = 23;

    vector<set<string>> tabla;
    vector<set<string>> tablaJuanagrama;
    int numeroElementos;

    void expandirTabla();
    unsigned int hash(string cadena, int size);
    unsigned int hashJuanagrama(string cadena, int size);
    unsigned int getValorCaracter(char caracter);
public:
    TablaHash();
    string encontrarJuanagrama(const string& palabra); //const para que no se modifique con el sort
    void insertar(string palabra);
    int buscar(string palabra);
    void borrar(string palabra);
    int getTamanio();
    void vaciar();
    bool existePalabra(const string& palabra);
};

#endif // TABLAHASH_H
