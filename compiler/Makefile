CC = g++
CFLAGS = -Wall -I.. -g
SRC = compiler.cpp
OBJ = $(addprefix ../build/compiler/, $(SRC:.cpp=.o))

.PHONY: all clean

all: $(OBJ)

../build/compiler/%.o: %.cpp | ../build/compiler/
	$(CC) $(CFLAGS) -c $< -o $@

../build/compiler/:
	mkdir -p $@

clean:
	rm -f ../build/compiler/*.o
