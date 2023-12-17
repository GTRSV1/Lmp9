#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *A, Matrix *b){
	double *najw = calloc(A->c , sizeof(double));
	int *najwindex = malloc(A->c * sizeof(int));
	
	for(int i=0; i< A->c ; i++){
		for (int j=0; j< A->r ; j++){
			if( fabs(A->data[i][j]) > najw[i] ){
				najw[i] = fabs(A->data[i][j]);
				najwindex[i] = j;
			}
		}
	}
	//niżej trzeba zrobić zamiany, tak aby nie było zer w diagonalach
	//same zera ogarniemy przy wyborze największego elementu
	for(int i=0; i< A->c; i++){
		if( A->data[i][i] == 0){
			if(najw[i]!=0){
				double temp;
				int ni = najwindex[i];
				for( int j=0; j< A->r; j++){
					temp = A->data[i][j];
					A->data[i][j] = A->data[ni][j];
					A->data[ni][j] = temp;
				}
				temp = b->data[0][i];
				b->data[0][i] = b->data[0][ni];
				b->data[0][ni] = temp;
			}
		}
	}

return 0;
}

