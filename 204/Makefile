a.out: Diccionario.o InterpreteComandos.o TablaHash.o Main.o
	g++ Diccionario.o InterpreteComandos.o TablaHash.o Main.o -o a.out

TablaHash.o: TablaHash.cpp TablaHash.h
	g++ -c TablaHash.cpp

Diccionario.o: Diccionario.cpp Diccionario.h TablaHash.h
	g++ -c Diccionario.cpp

InterpreteComandos.o: InterpreteComandos.cpp InterpreteComandos.h Diccionario.h TablaHash.h
	g++ -c InterpreteComandos.cpp

Main.o: Main.cpp Diccionario.h InterpreteComandos.h TablaHash.h
	g++ -c Main.cpp

clean:
	rm -rf a.out *.o
