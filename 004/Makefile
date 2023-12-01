#all:
#	g++ -o a.out Diccionario.cpp InterpreteComandos.cpp Main.cpp   

a.out: Diccionario.o InterpreteComandos.o Main.o
	g++ Diccionario.o InterpreteComandos.o Main.o

Diccionario.o: Diccionario.cpp Diccionario.h
	g++ -c Diccionario.cpp

InterpreteComandos.o: InterpreteComandos.cpp InterpreteComandos.h Diccionario.h
	g++ -c InterpreteComandos.cpp

Main.o: Main.cpp Diccionario.h InterpreteComandos.h 
	g++ -c Main.cpp

clean:
	rm -rf a.out Diccionario.o InterpreteComandos.o Main.o 