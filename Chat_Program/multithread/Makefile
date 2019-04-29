CFLAGS=-Wall -g 
LDFLAGS=-Wall -g -pthread      ## -pthread flag to leverage the POSIX standards based thread API for C/C++.

COMPILE=g++ $(CFLAGS) -c
LINK=g++ $(LDFLAGS) -o

SRCDIR=./src
OBJDIR=./obj
#OBJ=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(wildcard $(SRCDIR)/*.cpp))
OBJ=$(OBJDIR)/main.o $(OBJDIR)/mythread.o $(OBJDIR)/server.o $(OBJDIR)/client.o
BINDIR=./bin
BIN=$(BINDIR)/chat

all: $(BIN) 

$(BIN): $(OBJ)			 ## specifies dependencies
	$(LINK) $(BIN) $(OBJ)    ## create the linker that combines all of the generated compiled object files into one single executable program.

$(OBJDIR)/%.o:	$(SRCDIR)/%.cpp  ## specifies dependencies 
	$(COMPILE) $< -o $@	 ## specifies how o files should be compiled and constructed.

clean:
	rm -f $(OBJ) $(BIN)      ## remove object files


