run: main.exe
	./main.exe

run2: arreglos.exe
	./arreglos.exe

run3: masgrande.exe
	./masgrande.exe

run4: cuentadigitos.exe
	./cuentadigitos.exe


main.exe: imprimenumeros.c biblioteca.o biblioteca.h
	gcc imprimenumeros.c biblioteca.o -o main.exe

arreglos.exe: arreglo.c biblioteca.o biblioteca.h
	gcc arreglo.c biblioteca.o -o arreglos.exe

masgrande.exe: masgrande.c biblioteca.o biblioteca.h
	gcc masgrande.c biblioteca.o -o masgrande.exe

cuentadigitos.exe: digitos.c biblioteca.o biblioteca.h
	gcc digitos.c biblioteca.o -o cuentadigitos.exe

biblioteca.o: biblioteca.c
	gcc -c biblioteca.c -o biblioteca.o

