CC = g++
CFLAGS = -Wall -I.. -g
SRC = analyser.cpp
OBJ = $(addprefix ../build/analyser/, $(SRC:.cpp=.o))

.PHONY: all clean

all: $(OBJ)

../build/analyser/%.o: %.cpp | ../build/analyser/
	$(CC) $(CFLAGS) -c $< -o $@

../build/analyser/:
	mkdir -p $@

clean:
	rm -f ../build/analyser/*.o
