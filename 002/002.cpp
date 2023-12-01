#include <iostream>
#include <string>

using namespace std;

string normalizarPalabra(string texto) {
    string resultado;
    size_t i = 0;
    
    while (i < texto.length()) {
        char byte1 = texto[i];
        
        if (byte1 == '\xC3') {
            char byte2 = texto[i + 1];
            switch (byte2) {
                case '\xA1':
                    resultado.push_back(static_cast<char>(0x41));
                    break;  // á*
                case '\xA9':
                    resultado.push_back(static_cast<char>(0x45));
                    break; //é
                case '\xAD':
                    resultado.push_back(static_cast<char>(0x49));
                    break;  // í*
                case '\xB3':
                    resultado.push_back(static_cast<char>(0x4F));
                    break;  // ó*
                case '\xBA':
                    resultado.push_back(static_cast<char>(0x55));
                    break;  // ú*
                case '\xBC':
                    resultado.push_back(static_cast<char>(0xC3));
                    resultado.push_back(static_cast<char>(0x9C));
                    break;  // ü*  
                case '\xB1':
                    resultado.push_back(static_cast<char>(0xC3));
                    resultado.push_back(static_cast<char>(0x91));
                    break;  // ñ*
                case '\x81':
                    resultado.push_back(static_cast<char>(0x41));
                    break;  // Á*
                case '\x89':
                    resultado.push_back(static_cast<char>(0x45));
                    break;  // É*
                case '\x8D':
                    resultado.push_back(static_cast<char>(0x49));
                    break;  // Í*
                case '\x93':
                    resultado.push_back(static_cast<char>(0x4F));
                    break;  // Ó*
                case '\x9A':
                    resultado.push_back(static_cast<char>(0x55));
                    break;  // Ú*
                case '\x9C':
                    resultado.push_back(static_cast<char>(0xC3));
                    resultado.push_back(static_cast<char>(0x9C));
                    break;  // Ü*
                case '\x91':
                    resultado.push_back(static_cast<char>(0xC3));
                    resultado.push_back(static_cast<char>(0x91));
                    break;  // Ñ
                default:
                    resultado.push_back(static_cast<char>(0xC3));
                    resultado.push_back(static_cast<char>(byte2));
                // si no es cualquiera de esos, que se añada, solo hay que tratar esos, aquí vendrian los caracteres tipo ç à
            }
            i += 2; // Saltar al siguiente porque este caracter son 2 bytes
        } else {
            resultado.push_back(static_cast<char>(toupper(byte1)));
            i++;
        }
    }
    
    return resultado;
}

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
            std::cout << contadorPalabras << ". " << palabra << " -> " << normalizarPalabra(palabra) << endl;
            palabra.clear();
            dentroDePalabra = false;
            }
        }

        if (!palabra.empty()) {
            contadorPalabras++;
            std::cout << contadorPalabras << ". " << palabra << " -> " << normalizarPalabra(palabra) << endl;
            palabra.clear();
        }
    }
}