CC = g++
CFLAGS = -Wall -I..
SRC = filemanager.cpp fileinfo.cpp
OBJ = $(addprefix ../build/filemanager/, $(SRC:.cpp=.o))

.PHONY: all clean

all: $(OBJ)

../build/filemanager/%.o: %.cpp | ../build/filemanager/
	$(CC) $(CFLAGS) -c $< -o $@

../build/filemanager/:
	mkdir -p $@

clean:
	rm -f ../build/filemanager/*.o
