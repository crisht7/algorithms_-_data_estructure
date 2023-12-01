#ifndef TABLAHASH_H
#define TABLAHASH_H

#include <vector>
#include <list>
#include <string>

using namespace std;

class TablaHash {
private:
    // preguntar profesor
    struct Elemento {
        string clave; 
        int valor;
        Elemento(string k, int v) : clave(k), valor(v) {}
    };

    static const int TAMANIO_INICIAL = 1000;
    static constexpr double FACTOR_CARGA = 0.7;
    static const int FALTA_COINCIDENCIA = -1;

    vector<list<Elemento>> tabla;
    int numeroElementos;

    void expandirTabla();
    unsigned int hash(string cadena, int size);
public:
    TablaHash();
    // destructor
    void insertar(string key, int valor);
    int buscar(string key);
    void borrar(string key);
    int getTamanio();
    void vaciar();
    bool existeClave(const string& key);
};

#endif
