a.out: Diccionario.o InterpreteComandos.o TablaHash.o ArbolPalabras.o Main.o
	g++ Diccionario.o InterpreteComandos.o TablaHash.o Main.o ArbolPalabras.o -o a.out

TablaHash.o: TablaHash.cpp TablaHash.h
	g++ -c TablaHash.cpp

ArbolPalabras.o: ArbolPalabras.cpp ArbolPalabras.h
	g++ -c ArbolPalabras.cpp

Diccionario.o: Diccionario.cpp Diccionario.h TablaHash.h
	g++ -c Diccionario.cpp

InterpreteComandos.o: InterpreteComandos.cpp InterpreteComandos.h Diccionario.h TablaHash.h
	g++ -c InterpreteComandos.cpp

Main.o: Main.cpp Diccionario.h InterpreteComandos.h TablaHash.h
	g++ -c Main.cpp

clean:
	rm -rf a.out salidaActual.out *.o
