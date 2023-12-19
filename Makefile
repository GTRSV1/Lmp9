all: bin/gauss

bin/gauss: $(wildcard src/*.c) | bin
	gcc -Wall -ggdb --pedantic src/*.c -o bin/gauss

bin:
	mkdir -p bin

test: all
	bin/gauss dane/A dane/b
