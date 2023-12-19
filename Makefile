all: bin/gauss

.PHONY: all test clean

bin/gauss: $(wildcard src/*.c) | bin
	gcc -Wall -ggdb --pedantic src/*.c -o bin/gauss

bin:
	mkdir -p bin

clean:
	rm -rf bin

test: all
	bin/gauss dane/A dane/b
