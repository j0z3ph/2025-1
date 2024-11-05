APP=programa.exe

run: $(APP)
	./$(APP)

$(APP): funciones.cpp bibfunciones.hpp bibfunciones.o
	g++ funciones.cpp bibfunciones.o -o $(APP)

bibfunciones.o: bibfunciones.cpp
	g++ -c bibfunciones.cpp -o bibfunciones.o