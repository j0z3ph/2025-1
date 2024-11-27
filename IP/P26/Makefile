APP=agenda.exe
MAIN=agenda.c
TOOLS_OBJ=tools.o
TOOLS_H=tools.h
TOOLS=tools.c

run: $(APP)
	./$(APP)

$(APP): $(MAIN) $(TOOLS_H) $(TOOLS_OBJ)
	gcc $(MAIN) $(TOOLS_OBJ) -o $(APP)

$(TOOLS_OBJ): $(TOOLS)
	gcc -c $(TOOLS) -o $(TOOLS_OBJ)