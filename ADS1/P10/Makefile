APP=agenda.exe
MAIN=agenda.cpp
TOOLS_OBJ=tools.o
TOOLS_H=tools.hpp
TOOLS=tools.cpp
AGENDA_OBJ=contactolib.o
AGENDA_H=contactolib.hpp
AGENDA=contactolib.cpp

run: $(APP)
	./$(APP)

$(APP): $(MAIN) $(TOOLS_H) $(AGENDA_H) $(TOOLS_OBJ) $(AGENDA_OBJ)
	g++ -std=c++11 -S -C $(MAIN) $(TOOLS_OBJ) $(AGENDA_OBJ) -o $(APP)

$(TOOLS_OBJ): $(TOOLS)
	g++ -c $(TOOLS) -o $(TOOLS_OBJ)


$(AGENDA_OBJ): $(AGENDA_H) $(AGENDA)
	g++ -std=c++11 -c $(AGENDA) -o $(AGENDA_OBJ)