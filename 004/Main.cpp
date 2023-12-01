#include "InterpreteComandos.h"


int main(void){
    InterpreteComandos interprete;
    string comando;
    while(getline(cin, comando)){
        interprete.interpretarComando(comando);
    }
}