/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	
	double *C = malloc(N * N * sizeof(double));
	double *AB = malloc(N * N * sizeof(double));
	double *ABAt = malloc(N * N * sizeof(double));
	double *BtBt = malloc(N * N * sizeof(double));

	//AB=A×B
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			register double sum = 0.0;
			for (register int k = i; k < N; k++) {
				sum += A[i * N + k] * B[k * N + j];
			}
			AB[i * N + j] = sum;
		}
	}

	//ABAt=AB×At
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			register double sum = 0.0;
			for (register int k = j; k < N; k++) {
				sum += AB[i * N + k] * A[j * N + k];
			}
			ABAt[i * N + j] = sum;
		}
	}

	//BtBt=Bt×Bt
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			register double sum = 0.0;
			for (register int k = 0; k < N; k++) {
				sum += B[k * N + i] * B[j * N + k];
			}
			BtBt[i * N + j] = sum;
		}
	}

	//C=ABAt+BtBt
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			C[i * N + j] = ABAt[i * N + j] + BtBt[i * N + j];
		}
	}

	free(AB);
	free(ABAt);
	free(BtBt);
		
	return C;
}
