MAIN=main.c
APP=main.exe
LIB=funciones.c
LIB_B=funciones.o
LIB_H=funciones.h

run: $(APP)
	./$(APP)

$(APP): $(MAIN) $(LIB_B) $(LIB_H)
	gcc $(MAIN) $(LIB_B) -o $(APP)

$(LIB_B): $(LIB)
	gcc -c $(LIB) -o $(LIB_B)