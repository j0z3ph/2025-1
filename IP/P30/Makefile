MAIN=main.c
COMPILER=gcc
APP=main.exe
MAIN_TEST=control_calib.c
APP_TEST=test.exe
MINIWIN_H=miniwin.h
MINIWIN_LIB=miniwin.o
MINIWIN_SRC=miniwin.c
WIN_FLAGS=-mwindows
SERIAL=serial.c
SERIAL_H=serial.h
run: $(APP)
	./$(APP)

$(APP): $(MAIN) $(MINIWIN_H) $(MINIWIN_LIB) $(SERIAL_H)
	$(COMPILER) -o $(APP) $(MINIWIN_LIB) $(MAIN) $(SERIAL) $(WIN_FLAGS)

$(MINIWIN_LIB): $(MINIWIN_H) $(MINIWIN_SRC)
	$(COMPILER) -c $(MINIWIN_SRC) -o $(MINIWIN_LIB)

clean: 
	del $(APP) $(MINIWIN_LIB)

test: $(APP_TEST)
	./$(APP_TEST)

$(APP_TEST): $(MAIN_TEST) $(SERIAL_H)
	$(COMPILER) -o $(APP_TEST) $(MAIN_TEST) $(SERIAL)

