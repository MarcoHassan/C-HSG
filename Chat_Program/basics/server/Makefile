COMPILER = g++
CFLAGS = -Wall -g
OBJDIR=./obj
SRC = ./src
OBJ = $(OBJDIR)/server.o
EXECUTABLE = ./bin

$(OBJDIR)/%.o: $(SRC)/%.cpp
	$(COMPILER) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE)/server: $(OBJ)
	$(COMPILER) -o $@ $^ $(CFLAGS)
