#include "InterpreteComandos.h"

InterpreteComandos::InterpreteComandos(){

}

void InterpreteComandos::salir(){
    cout << "Saliendo..." << endl;
    exit(0);
}

void InterpreteComandos::vaciarDiccionario(){
    cout << "Vaciando" << endl;
    diccionario.vaciar();
    cout << "Total diccionario: " << diccionario.getTamanio() << " palabras" << endl;
}

void InterpreteComandos::buscarPalabra(string palabra){
    cout << "Buscando: " << Diccionario::normalizarPalabra(palabra) << " -> ";
    if(diccionario.consultarPalabra(palabra)){
        cout << "Encontrada" << endl;
    } else{
        cout << "No encontrada" << endl;
    }
}

void InterpreteComandos::alocado(string palabra){
    cout << "Alocado: " << Diccionario::normalizarPalabra(palabra) << endl;
    cout << "No implementado" << endl;
}

void InterpreteComandos::insertarPalabras(string palabras){
    istringstream primerStream(palabras);
    string palabra;
    int contador = 0;

    while (primerStream >> palabra) {
        if (palabra == "<insertar>") {
        } else if (palabra == "</insertar>"){
            cout << "Insertando: " << contador << " palabras" << endl;
            cout << "Total diccionario: " << diccionario.getTamanio() << " palabras" << endl;
            return;
        } else{
            diccionario.insertarPalabra(palabra);
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
                cout << "Total diccionario: " << diccionario.getTamanio() << " palabras" << endl;
                return;
            } else{
                diccionario.insertarPalabra(palabra);
                contador++;
            }
        }
    }
}

void InterpreteComandos::partidas(string entrada){
    istringstream streamBuscar(entrada);
    string palabra;

    cout << "Partidas:";
    while (streamBuscar >> palabra) {
        if (palabra == "<partidas>") {
        } else if (palabra == "</partidas>"){
            break;
        }
        else{
            cout << " " << Diccionario::normalizarPalabra(palabra); //TODO: error
        }
    }

    cout << endl << "No implementado" << endl;
}

void InterpreteComandos::cesar(string palabra){
    cout << "César: " << Diccionario::normalizarPalabra(palabra) << endl;
    cout << "No implementado" << endl;
}

void InterpreteComandos::juanagra(string palabra){
    cout << "Juanagrama: " << Diccionario::normalizarPalabra(palabra) << endl;
    cout << "No implementado" << endl;
}

void InterpreteComandos::saco(string entrada){
    istringstream streamBuscar(entrada);
    string palabra;

    cout << "Saco:";
    while (streamBuscar >> palabra) {
        if (palabra != "<saco>") {
            string palabraNormalizada = Diccionario::normalizarPalabra(palabra);
            cout << " " << palabraNormalizada;
        }
    }

    cout << endl << "No implementado" << endl;
}

void InterpreteComandos::consome(string palabra){
    cout << "Consomé: " << Diccionario::normalizarPalabra(palabra) << endl;
    cout << "No implementado" << endl;
}

void InterpreteComandos::alarga(string palabra){
    cout << "Alarga: " << Diccionario::normalizarPalabra(palabra) << endl;
    cout << "No implementado" << endl;
}

void InterpreteComandos::interpretarComando(string comando){
    string palabraActual;
    string proximaPalabra;
    istringstream stream(comando);
    while (stream >> palabraActual) {
        if (palabraActual == "<insertar>") { //
            insertarPalabras(comando);
            break;
        } else if (palabraActual == "<buscar>"){ //
            if(stream >> proximaPalabra){
                buscarPalabra(proximaPalabra);
            }
            break;
        } else if(palabraActual == "<vaciar>"){ //
            vaciarDiccionario();
            break;
        } else if(palabraActual == "<exit>"){ //
            salir();
        } else if(palabraActual=="<alocado>"){ //
            if(stream >> proximaPalabra){
                alocado(proximaPalabra);
            }
            break;
        } else if(palabraActual=="<partidas>"){ //
            partidas(comando);
            break;
        } else if(palabraActual=="<césar>"){ //
            if(stream >> proximaPalabra){
                cesar(proximaPalabra);
            }
            break;
        } else if(palabraActual=="<juanagra>"){ //
            if (stream >> palabraActual){
                juanagra(palabraActual);
            }   
            break;
        } else if(palabraActual=="<saco>"){ //
            saco(comando);
            break;
        } else if(palabraActual=="<consomé>"){ //
            if(stream >> proximaPalabra){
                consome(proximaPalabra);
            }
            break;
        } else if(palabraActual=="<alarga>"){ //
            if(stream >> proximaPalabra){
                alarga(proximaPalabra);
            }
            break;
        } else {
            break;
        }
    }
}
