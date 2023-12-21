#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	Matrix * A = readFromFile(argv[1], 1);
	Matrix * b = readFromFile(argv[2], 0);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printf("Wczytana macierz A:\n");
	printToScreen(A);
	printf("Wczytana macierz b:\n");
	printToScreen(b);

	if( A->r != b->r){
		fprintf(stderr, "Błąd! Podane macierze nie mają takiej samej liczby wierszy.\n");
		freeMatrix(A);
		freeMatrix(b);
		return 0;
	}

	eliminate(A,b);
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		backsubst(x,A,b);
		printf("Obliczona macierz X:\n");
		printToScreen(x);
	  	freeMatrix(x);
	} else {
		fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
