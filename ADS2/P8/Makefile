APP=agenda.exe
MAIN=agenda.cpp
TOOLS_OBJ=tools.o
TOOLS_H=tools.hpp
TOOLS=tools.cpp
AGENDA_OBJ=agendalib.o
AGENDA_H=agendalib.hpp
AGENDA=agendalib.cpp

run: $(APP)
	./$(APP)

$(APP): $(MAIN) $(TOOLS_H) $(AGENDA_H) $(TOOLS_OBJ) $(AGENDA_OBJ)
	g++ $(MAIN) $(TOOLS_OBJ) $(AGENDA_OBJ) -o $(APP)

$(TOOLS_OBJ): $(TOOLS)
	g++ -c $(TOOLS) -o $(TOOLS_OBJ)

$(AGENDA_OBJ): $(AGENDA) $(AGENDA_H)
	g++ -c $(AGENDA) -o $(AGENDA_OBJ)