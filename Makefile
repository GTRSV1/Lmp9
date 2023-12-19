all:
	gcc -Wall -ggdb --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
