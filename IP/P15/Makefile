MAIN=matrix.c
APP=app.exe
ALLIB=stdla.o
TOOLSLIB=stdtools.o
#Archivos
ALH=stdla.h
ALC=stdla.c
TOOLSH=stdtools.h
TOOLSC=stdtools.c

run: $(APP)
	./$(APP)

$(APP): $(MAIN) $(ALH) $(TOOLSH) $(ALLIB) $(TOOLSLIB)
	gcc $(MAIN) $(ALLIB) $(TOOLSLIB) -o $(APP)

$(ALLIB): $(ALC)
	gcc -c $(ALC) -o $(ALLIB)

$(TOOLSLIB): $(TOOLSC)
	gcc -c $(TOOLSC) -o $(TOOLSLIB)

clean: 	
	rm *.o
	rm *.exe