COMPILER = g++
CFLAGS = -Wall -g
OBJDIR=./obj
SRC = ./src
OBJ = $(OBJDIR)/client.o
EXECUTABLE = ./bin

$(OBJDIR)/%.o: $(SRC)/%.cpp
	$(COMPILER) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE)/client: $(OBJ)
	$(COMPILER) -o $@ $^ $(CFLAGS)
