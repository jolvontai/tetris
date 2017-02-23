CC=g++ 
CFLAGS=-ggdb -c -Wall -pedantic
LDFLAGS=-lGL -lGLEW -lSDL2 -lSDL2_image -std=c++11
SOURCEDIR=src
SOURCES=$(wildcard $(SOURCEDIR)/*.cpp)
BUILDDIR=build

OBJECTS=$(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
EXECUTABLE=ohjelma

all: dir $(BUILDDIR)/$(EXECUTABLE)

dir:
	if test -d $(BUILDDIR); then echo "folder exists skipping creating"; else mkdir -p $(BUILDDIR); fi

$(BUILDDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ $(LDFLAGS) -o $@

$(OBJECTS): $(BUILDDIR)/%.o : $(SOURCEDIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BUILDDIR)/*o $(BUILDDIR)/$(EXECUTABLE)
