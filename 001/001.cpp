#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string entradaTotal;
    bool dentroDePalabra = false;
    string palabra;
    int contadorPalabras = 0;

    while(cin >> entradaTotal){
        for (char c : entradaTotal) {
        if (c != ' ' && c != '\n') {
            palabra += c;
            dentroDePalabra = true;
        } else if (dentroDePalabra) {
            contadorPalabras++;
            cout << contadorPalabras << ". " << palabra << endl;
            palabra.clear();
            dentroDePalabra = false;
            }
        }

        if (!palabra.empty()) {
            contadorPalabras++;
            cout << contadorPalabras << ". " << palabra << endl;
            palabra.clear();
        }
    }
}
