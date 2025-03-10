CC = g++
CFLAGS = -Wall -I..
SRC = parser.cpp
OBJ = $(addprefix ../build/parser/, $(SRC:.cpp=.o))

.PHONY: all clean

all: $(OBJ)

../build/parser/%.o: %.cpp | ../build/parser/
	$(CC) $(CFLAGS) -c $< -o $@

../build/parser/:
	mkdir -p $@

clean:
	rm -f ../build/parser/*.o
