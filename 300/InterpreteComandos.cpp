#include "InterpreteComandos.h"

/**
 * @brief Constructor de la clase InterpreteComandos.
 * 
 * @param None
 * 
 * @return Instancia de la clase
 */
InterpreteComandos::InterpreteComandos(){
}

/**
 * @brief Termina la ejecución del programa.
 * 
 * Esta función imprime un mensaje indicando que el programa está saliendo y
 * luego termina la ejecución del programa utilizando la función exit() con el código 0.
 * 
 * @return None
 */
void InterpreteComandos::salir(){
    cout << "Saliendo..." << endl;
    exit(0);
}

/**
 * @brief Vacía el diccionario asociado al InterpreteComandos.
 * 
 * Esta función imprime un mensaje indicando que se está vaciando el diccionario,
 * realiza la operación de vaciar el diccionario asociado al InterpreteComandos
 * utilizando el método "vaciar()" de la clase del diccionario, y luego imprime
 * el total de palabras en el diccionario después de la operación.
 * 
 * @return None
 */
void InterpreteComandos::vaciarDiccionario(){
    cout << "Vaciando" << endl;
    diccionario.vaciar();
    cout << "Total diccionario: " << diccionario.getTamanio() << " palabras" << endl;
}

/**
 * @brief Busca una palabra en el diccionario asociado al InterpreteComandos.
 * 
 * Esta función busca la palabra proporcionada en el diccionario asociado al InterpreteComandos,
 * utilizando el método "consultarPalabra()" de la clase del diccionario. Imprime un mensaje
 * indicando la palabra que se está buscando y si la palabra es encontrada o no en el diccionario.
 * 
 * @param palabra Palabra a buscar en el diccionario.
 * @return None
 */
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

/**
 * @brief Inserta palabras en el diccionario asociado al InterpreteComandos.
 * 
 * Esta función inserta palabras en el diccionario asociado al InterpreteComandos,
 * extrayendo las palabras de la cadena de entrada proporcionada. La inserción de
 * palabras continúa hasta encontrar las etiquetas "<insertar>" y "</insertar>" que
 * delimitan el bloque de palabras a insertar. Muestra mensajes indicando la cantidad
 * de palabras insertadas y el total de palabras en el diccionario después de la operación.
 * 
 * @param palabras Cadena de entrada que contiene las palabras a insertar.
 * @return None
 */
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
            cout << " " << Diccionario::normalizarPalabra(palabra);
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

/**
 * @brief Interpreta un comando y realiza la operación correspondiente.
 * 
 * Esta función interpreta el comando proporcionado y realiza la operación asociada a
 * dicho comando. Utiliza distintas funciones internas según la estructura del comando.
 * Los comandos reconocidos son: "<insertar>", "<buscar>", "<vaciar>", "<exit>",
 * "<alocado>", "<partidas>", "<césar>", "<juanagra>", "<saco>", "<consomé>", "<alarga>".
 * Muestra mensajes indicando el resultado de la operación realizada.
 * 
 * @param comando Comando a interpretar y ejecutar.
 * @return None
 */
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
