APP=main.exe

run: $(APP)
	./$(APP)

run2: app1.exe
	./app1.exe

run3: app2.exe
	./app2.exe

app2.exe: prob2.c bibfunciones.o bibfunciones.h
	gcc prob2.c bibfunciones.o -o app2.exe


app1.exe: prob1.c bibfunciones.o bibfunciones.h
	gcc prob1.c bibfunciones.o -o app1.exe


$(APP): cadenas1.c bibfunciones.o bibfunciones.h
	gcc cadenas1.c bibfunciones.o -o $(APP)

bibfunciones.o: bibfunciones.c
	gcc -c bibfunciones.c -o bibfunciones.o