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
		if( fabs(A->data[r][c]) > najw ){
			najw = fabs(A->data[r][c]);
			najwindex = r;
		}
	}
	
	if(najw != 0){
		double temp;
		int ni = najwindex;
		for( int i=0; i< n; i++){
			temp = A->data[c][i];
			A->data[c][i] = A->data[ni][i];
			A->data[ni][i] = temp;
		}
		temp = b->data[c][0];
		b->data[c][0] = b->data[ni][0];
		b->data[ni][0] = temp;
	}
}

int eliminate(Matrix *A, Matrix *b){
	int n = A->c;	
	
	for( int c= 0; c < n-1; c++ ){
		switchin(c, A, b);
		
		for( int r= c+1; r < n; r++ ){
			if(A->data[c][c] == 0)
				return 1;	
			double wsp = A->data[r][c] / A->data[c][c];
			for( int i= c; i < n; i++ ){
				A->data[r][i] -= A->data[c][i] * wsp;
			}
			b->data[r][0] -= b->data[c][0] * wsp;
		}
		
	}

return 0;
}

