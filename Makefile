all: square

square: square.cc key.h
        g++ -ggdb square.cc key.h -o square

clean:
        rm -rf *.o *.h.gch square