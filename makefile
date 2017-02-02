CC=g++
CFLAGS=-c
LDFLAGS=-lGL -lGLEW -lSDL2 -std=c++11 -g
ROUTE=src/
SOURCES= $(ROUTE)game.cpp $(ROUTE)main.cpp 
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
