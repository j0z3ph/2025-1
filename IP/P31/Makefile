MAIN=main.c
COMPILER=gcc
APP=main.exe
MINIWIN_H=miniwin.h
MINIWIN_LIB=miniwin.o
MINIWIN_SRC=miniwin.c
WIN_FLAGS=-mwindows -lwinmm
run: $(APP)
	./$(APP)

$(APP): $(MAIN) $(MINIWIN_H) $(MINIWIN_LIB)
	$(COMPILER) -o $(APP) $(MINIWIN_LIB) $(MAIN) serial.c $(WIN_FLAGS)

$(MINIWIN_LIB): $(MINIWIN_H) $(MINIWIN_SRC)
	$(COMPILER) -c $(MINIWIN_SRC) -o $(MINIWIN_LIB)

clean: 
	del $(APP) $(MINIWIN_LIB)