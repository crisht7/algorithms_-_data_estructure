#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;
int palabrasTotales = 0;

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

void insertar(string palabras) {
    istringstream primerStream(palabras);
    string palabra;
    int contador = 0;

    while (primerStream >> palabra) {
        if (palabra == "<insertar>") {
        } else if (palabra == "</insertar>"){
            cout << "Insertando: " << contador << " palabras" << endl;
            cout << "Total diccionario: " << palabrasTotales << " palabras" << endl;
            return;
        } else{
            palabrasTotales++;
            contador++;
        }
    }

    palabra.clear();
    string entrada;

    while(cin >> entrada){
        istringstream segundoStream(entrada);
        while (segundoStream >> palabra) {
            if (palabra == "<insertar>") {
            } else if (palabra == "</insertar>"){
                cout << "Insertando: " << contador << " palabras" << endl;
                cout << "Total diccionario: " << palabrasTotales << " palabras" << endl;
                return;
            } else{
                palabrasTotales++;
                contador++;
            }
        }
    }
}

void buscar(string entrada) {
    istringstream streamBuscar(entrada);
    string palabra;

    while (streamBuscar >> palabra) {
        if (palabra == "<buscar>") {
        }
        else{
            string palabraNormalizada = normalizarPalabra(palabra);
            cout << "Buscando: " << palabraNormalizada << " -> No encontrada" << endl;
        }
    }

}

void alocado(string entrada){
    istringstream streamBuscar(entrada);
    string palabra;

    while (streamBuscar >> palabra) {
        if (palabra == "<alocado>") {
        }
        else{
            string palabraNormalizada = normalizarPalabra(palabra);
            cout << "Alocado: " << palabraNormalizada << endl;
            cout << "No implementado" << endl;
            break;
        }
    }
}

void partidas(string entrada){
    istringstream streamBuscar(entrada);
    string palabra;

    cout << "Partidas:";
    while (streamBuscar >> palabra) {
        if (palabra == "<partidas>") {
        } else if (palabra == "</partidas>"){
            break;
        }
        else{
            string palabraNormalizada = normalizarPalabra(palabra);
            cout << " " << palabraNormalizada; //TODO: error
        }
    }

    cout << endl << "No implementado" << endl;
}

void cesar(string entrada){
    istringstream streamBuscar(entrada);
    string palabra;

    while (streamBuscar >> palabra) {
        if (palabra == "<césar>") {
        }
        else{
            string palabraNormalizada = normalizarPalabra(palabra);
            cout << "César: " << palabraNormalizada << endl;
            cout << "No implementado" << endl;
            break;
        }
    }

}

void juanagra(string entrada){
    istringstream streamBuscar(entrada);
    string palabra;

    while (streamBuscar >> palabra) {
        if (palabra == "<juanagra>") {
        }
        else{
            string palabraNormalizada = normalizarPalabra(palabra);
            cout << "Juanagrama: " << palabraNormalizada << endl;
            cout << "No implementado" << endl;
            break;
        }
    }
}

void saco(string entrada){
    istringstream streamBuscar(entrada);
    string palabra;

    cout << "Saco:";
    while (streamBuscar >> palabra) {
        if (palabra == "<saco>") {
        }
        else{
            string palabraNormalizada = normalizarPalabra(palabra);
            cout << " " << palabraNormalizada; //TODO: error
        }
    }

    cout << endl << "No implementado" << endl;
}

void consome(string entrada){
    istringstream streamBuscar(entrada);
    string palabra;

    while (streamBuscar >> palabra) {
        if (palabra == "<consomé>") {
        }
        else{
            string palabraNormalizada = normalizarPalabra(palabra);
            cout << "Consomé: " << palabraNormalizada << endl;
            cout << "No implementado" << endl;
            break;
        }
    }
}

void alarga(string entrada){
    istringstream streamBuscar(entrada);
    string palabra;

    while (streamBuscar >> palabra) {
        if (palabra == "<alarga>") {
        }
        else{
            string palabraNormalizada = normalizarPalabra(palabra);
            cout << "Alarga: " << palabraNormalizada << endl;
            cout << "No implementado" << endl;
            break;
        }
    }
}

int main(void){
    string entradaTotal;
    string palabra;

    while(std::getline(std::cin, entradaTotal)){
        istringstream stream(entradaTotal);
        while (stream >> palabra) {
            if (palabra == "<insertar>") {
                insertar(entradaTotal);
                break;
            } else if (palabra == "<buscar>"){
                buscar(entradaTotal);
                break;
            } else if(palabra == "<vaciar>"){
                cout << "Vaciando" << endl;
                palabrasTotales = 0;
                cout << "Total diccionario: 0 palabras" << endl;
                break;
            } else if(palabra == "<exit>"){
                cout << "Saliendo..." << endl;
                exit(0);
            } else if(palabra=="<alocado>"){
                alocado(entradaTotal);
                break;
            } else if(palabra=="<partidas>"){
                partidas(entradaTotal);
                break;
            } else if(palabra=="<césar>"){
                cesar(entradaTotal);
                break;
            } else if(palabra=="<juanagra>"){
                juanagra(entradaTotal);
                break;
            } else if(palabra=="<saco>"){
                saco(entradaTotal);
                break;
            } else if(palabra=="<consomé>"){
                consome(entradaTotal);
                break;
            } else if(palabra=="<alarga>"){
                alarga(entradaTotal);
                break;
            } else {
                break;
            }
        }
    }

}

