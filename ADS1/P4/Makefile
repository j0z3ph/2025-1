APP=main.exe

run: $(APP)
	./$(APP)

$(APP): funciones.cpp lazaro.hpp lazaro.o
	g++ funciones.cpp lazaro.o -o $(APP)

lazaro.o: lazaro.cpp
	g++ -c lazaro.cpp -o lazaro.o