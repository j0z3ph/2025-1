run: main.exe
	./main.exe

main.exe: funciones.cpp biblioteca.o biblioteca.hpp
	g++ funciones.cpp biblioteca.o -o main.exe

biblioteca.o: biblioteca.cpp 
	g++ -c biblioteca.cpp -o biblioteca.o