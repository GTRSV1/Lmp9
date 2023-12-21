#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    int n = mat->r;

    if (mat->r != mat->c || mat->r != b->r || b->c != 1 || x->r != n || x->c != 1) {
        fprintf(stderr, "Błąd: Niewłaściwy rozmiar macieży.\n");
        return 2;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (mat->data[i][i] == 0) {
        	fprintf(stderr, "Błąd: Wystąpiło dzielenie przez zero\n");
        	return 1;
        } else {

        	x->data[i][0] = b->data[i][0] / mat->data[i][i];

        	for (int j = i + 1; j < n; j++) {
        	    x->data[i][0] -= (mat->data[i][j] * x->data[j][0]) / mat->data[i][i];
        	}
        }
    }

    return 0;
}



