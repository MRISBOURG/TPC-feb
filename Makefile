ECHO=@echo
COMP=g++
CPPFLAGS=-g -DMAP -Wall -ansi -pedantic -std=c++11
INT= Ligne.h Classement.h Graphe.h
REAL=$(INT:.h=.cpp)
BINAIRE=$(INT:.h=.o)
EXE=run

$(EXE): $(BINAIRE) main.o
	$(ECHO) "Editions des liens, création de <$<>"
	$(COMP) -o $(EXE) $(BINAIRE) main.o

Test: $(BINAIRE) test.o
	$(ECHO) "Editions des liens, création de <$<>"
	$(COMP) -o test $(BINAIRE) test.o

%.o: %.cpp
	$(ECHO) "Compilation du fichier <$<>"
	$(COMP) -c  $(CPPFLAGS) $<	

clean:
	@rm -rf *.o run test

