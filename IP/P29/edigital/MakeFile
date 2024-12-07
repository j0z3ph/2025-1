ifdef OS
	APP = arduino.exe
	EXECCMD = .\arduino.exe
else
	APP = arduino.out
	EXECCMD = ./arduino.out
endif
MAIN = escritura_digital.c
SERIALLIB = serial.c
COMPILER = gcc

all: $(APP)
	$(EXECCMD)

$(APP): $(MAIN) $(SERIALLIB)
	$(COMPILER) $(MAIN) $(SERIALLIB) -o $(APP)