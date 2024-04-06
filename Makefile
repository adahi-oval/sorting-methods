CC=g++
CFLAGS=-g -std=c++17 -Iinclude

OBJ = $(patsubst %,build/%,main.o)

EXECUTABLE = SortMethods

all: SortMethods

SortMethods: $(OBJ)
	$(CC) -o $(EXECUTABLE) $^ $(CFLAGS) -lm

build/main.o: src/main.cc
	$(CC) -c -o $@ $< $(CFLAGS)

run:
	./$(EXECUTABLE)

.PHONY: clean

clean:
	@rm -f build/*.o *~ src/*~ src/*.exe
	@rm $(EXECUTABLE)
	@echo "Make clean: ¡Limpieza realizada con éxito!"