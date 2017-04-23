#author Pikorová Karolína
#pikorkar@fit.cvut.cz

#variables ------------------------------------------------------------------------------
BIN=./pikorkar
CXX=g++
CFLAGS=-Wall -pedantic -Wno-long-long -O0 -ggdb
RM=rm -rf
DOCDIR=doc
SRCDIR=src

OBJECTS=\
	$(SRCDIR)/main.o\
	$(SRCDIR)/Commands.o\
	$(SRCDIR)/Create.o\
	$(SRCDIR)/Database.o\
	$(SRCDIR)/Delete.o\
	$(SRCDIR)/Insert.o\
	$(SRCDIR)/Load.o\
	$(SRCDIR)/Reader.o\
	$(SRCDIR)/Save.o\
	$(SRCDIR)/Select.o

#Makefile arguments ----------------------------------------------------------------------

#Compile project and creates documentation.
all:
	make compile doc

#Clean all created files.
clean:		
	$(RM) $(OBJECTS) $(BIN) $(DOCDIR)

#Binary saved in <login>.
compile:	$(BIN)

#Creates documentation.
doc:
	doxygen

#Run binary.
run:
	$(BIN)

#rules ----------------------------------------------------------------------------------

$(BIN): $(OBJECTS)
	$(CXX) $(CFLAGS) $(OBJECTS) -o $(BIN)

$(SRCDIR)/main.o: $(SRCDIR)/main.cpp 
	$(CXX) $(CFLAGS) -c $(SRCDIR)/main.cpp -o $(SRCDIR)/main.o

$(SRCDIR)/Commands.o: $(SRCDIR)/Commands.cpp 
	$(CXX) $(CFLAGS) $(LIBS) -c $(SRCDIR)/Commands.cpp -o $(SRCDIR)/Commands.o

$(SRCDIR)/Create.o: $(SRCDIR)/Create.cpp
	$(CXX) $(CFLAGS) -c $(SRCDIR)/Create.cpp -o $(SRCDIR)/Create.o

$(SRCDIR)/Database.o: $(SRCDIR)/Database.cpp
	$(CXX) $(CFLAGS) -c $(SRCDIR)/Database.cpp -o $(SRCDIR)/Database.o

$(SRCDIR)/Delete.o: $(SRCDIR)/Delete.cpp
	$(CXX) $(CFLAGS) -c $(SRCDIR)/Delete.cpp -o $(SRCDIR)/Delete.o

$(SRCDIR)/Insert.o: $(SRCDIR)/Insert.cpp
	$(CXX) $(CFLAGS) -c $(SRCDIR)/Insert.cpp -o $(SRCDIR)/Insert.o

$(SRCDIR)/Load.o: $(SRCDIR)/Load.cpp
	$(CXX) $(CFLAGS) -c $(SRCDIR)/Load.cpp -o $(SRCDIR)/Load.o

$(SRCDIR)/Reader.o: $(SRCDIR)/Reader.cpp
	$(CXX) $(CFLAGS) -c $(SRCDIR)/Reader.cpp -o $(SRCDIR)/Reader.o

$(SRCDIR)/Save.o: $(SRCDIR)/Save.cpp
	$(CXX) $(CFLAGS) -c $(SRCDIR)/Save.cpp -o $(SRCDIR)/Save.o

$(SRCDIR)/Select.o: $(SRCDIR)/Select.cpp
	$(CXX) $(CFLAGS) -c $(SRCDIR)/Select.cpp -o $(SRCDIR)/Select.o
