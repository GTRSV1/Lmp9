all: bin/gauss

.PHONY: all test test1 test2 test3 test4 test5 test6  test7 clean

bin/gauss: $(wildcard src/*.c) | bin
	gcc -Wall -ggdb --pedantic src/*.c -o bin/gauss

bin:
	mkdir -p bin

clean:
	rm -rf bin

test: all
	bin/gauss dane/A dane/b
test1:
	bin/gauss dane/Adiag dane/bdiag
test2:
	bin/gauss dane/Akolzer dane/bdiag
test3:
	bin/gauss dane/Arect dane/b
test4:
	bin/gauss dane/A dane/A
test5:
	bin/gauss dane/A dane/bdiag
test6:
	bin/gauss dane/A
test7:
	bin/gauss dane/Aspr dane/bspr
