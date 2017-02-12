CC=g++ -ggdb
CFLAGS=-c
LDFLAGS=-lGL -lGLEW -lSDL2 -std=c++11
ROUTE=src/
OUTPUT=build/
SOURCES= $(ROUTE)game.cpp $(ROUTE)main.cpp $(ROUTE)rect.cpp $(ROUTE)engine.cpp $(ROUTE)renderer.cpp $(ROUTE)element2d.cpp
OBJECTS=$(OUTPUT *.o)
EXECUTABLE=ohjelma

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $(OUTPUT)$@

clean:
	rm -f build/*.o
	rm -f build/ohjelma
