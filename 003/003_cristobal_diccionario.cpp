#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> diccionario; // Ahora las claves son de tipo string

void elegir();

void insertar() {
    string palabra;
    cout << "<insertar> ";
    int contador = 1;
    while (true) {
        string entrada;
        cin >> entrada;
        if (entrada == "</insertar>") {
            break;
        }
        diccionario[entrada] = ""; // Asignamos la palabra como clave, el valor es una cadena vacía
        contador++;
    }
    cout << "Insertando: " << contador-1 << " palabras" << endl;
    cout << "Total diccionario: " << diccionario.size() << endl;
    elegir();
}

void buscar() {
    string palabra;
    cout << "<buscar> ";
    cin >> palabra;
    cout << "Buscando: " << palabra << " -> ";
    if (diccionario.find(palabra) != diccionario.end()) {
        cout << "Encontrada " << endl;
    } else {
        cout << "No encontrada " << endl;
    }
    elegir();
}

int main(void){
   
    elegir();


}

void elegir(){
    cout << "Elige una opcion(insertar, vaciar, buscar, exit): ";
    string opcion;
    cin >> opcion;
if(opcion == "<insertar>"){
    insertar();
}
else if(opcion == "<vaciar>"){
    diccionario.clear();
    cout << "Total diccionario: " << diccionario.size() << endl;
    elegir();
}
else if(opcion == "<buscar>"){
    buscar();
}
else if(opcion == "<partidas>"){
    cout << "No implementado" << endl;
}
else if(opcion == "<alocado>"){
    cout << "No implementado" << endl;
}
else if(opcion == "<césar>"){
    cout << "No implementado" << endl;
}
else if(opcion == "<juanagra>"){
    cout << "No implementado" << endl;
}
else if(opcion == "<saco>"){
    cout << "No implementado" << endl;
}
else if(opcion == "<consomé>"){
    cout << "No implementado" << endl;
}
else if(opcion == "<alarga>"){
    cout << "No implementado" << endl;
}
else if(opcion == "<exit>"){
    cout << "Saliendo..." << endl;
    exit(1);
}else{
    cout << "Opcion no válida" << endl;
    elegir();
}
}
