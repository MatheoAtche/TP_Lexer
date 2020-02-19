ECHO = echo
EDL = g++ 
EXE = main
COMP = g++ -c 

DEC = lexer.h symbole.h etat.h automate.h 
DEF = lexer.cpp symbole.cpp etat.cpp automate.cpp 
OBJ = lexer.o symbole.o

LIBS = -lm 
CPPFLAGS = -ansi -pedantic -Wall -std=c++11 $(P) -g

$(EXE) : $(OBJ) $(EXE).o
	@$(ECHO) "Edl de <main>"
	$(EDL) -o $(EXE) $(EXE).o $(OBJ) 

$(EXE).o : $(EXE).cpp
	@$(ECHO) "compil de <$@>"
	$(COMP) -o $@ $(CPPFLAGS) $^ 

%.o : %.cpp
	@$(ECHO) "compil de <$@>"
	$(COMP) -o $@ $(CPPFLAGS) $^ 

clean : 
	@$(ECHO) "Suppression des objets et de l'executable"
	rm *.o
	rm $(EXE) 
