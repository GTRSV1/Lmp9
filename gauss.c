#include "gauss.h"

/*
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

void switchin(int c, Matrix *A, Matrix *b){
	
	int n = A->c;	
	double najw = 0;
	int najwindex;

	for (int r = c; r < n ; r++){
		if( fabs(A->data[c][r]) > najw ){
			najw = fabs(A->data[c][r]);
			najwindex = r;
		}
	}

	if(najw != 0){
		double temp;
		int ni = najwindex;
		for( int r=0; r< n; r++){
			temp = A->data[c][r];
			A->data[c][r] = A->data[ni][r];
			A->data[ni][r] = temp;
		}
		temp = b->data[0][c];
		b->data[0][c] = b->data[0][ni];
		b->data[0][ni] = temp;
	}
}

int eliminate(Matrix *A, Matrix *b){
	int n = A->c;	
	
	for( int c= 0; c < n-1; c++ ){
		switchin(c, A, b);
		
		for( int r= c+1; r < n; r++ ){
			if(A->data[c][c] == 0)
				return 1;	
			double wsp = A->data[c][r] / A->data[c][c];
			for( int i= c; i < n; i++ ){
				A->data[i][r] -= A->data[i][r] * wsp;
			}
			b->data[0][r] -= b->data[0][c] * wsp;
		}
		
	}

return 0;
}

