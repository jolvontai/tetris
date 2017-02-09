CC=g++
CFLAGS=-c
LDFLAGS=-lGL -lGLEW -lSDL2 -std=c++11 -g
ROUTE=src/
SOURCES= $(ROUTE)game.cpp $(ROUTE)main.cpp $(ROUTE)rect.cpp $(ROUTE)engine.cpp $(ROUTE)renderer.cpp $(ROUTE)element2d.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ohjelma

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(ROUTE)*.o
	rm -f ohjelma
