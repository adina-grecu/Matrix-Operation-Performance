/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {

	double *C = calloc(N * N, sizeof(double));
	double *AB = calloc(N * N, sizeof(double));
	double *ABAt = calloc(N * N, sizeof(double));
	double *BtBt = calloc(N * N, sizeof(double));

	//AB=A×B
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = i; k < N; k++) {
				AB[i * N + j] += A[i * N + k] * B[k * N + j];
			}
		}
	}

	//ABAt=AB×At
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = j; k < N; k++) {
				ABAt[i * N + j] += AB[i * N + k] * A[j * N + k];
			}
		}
	}

	//BtBt=Bt×Bt
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				BtBt[i * N + j] += B[k * N + i] * B[j * N + k];
			}
		}
	}

	//C=ABAt+BtBt
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			C[i * N + j] = ABAt[i * N + j] + BtBt[i * N + j];
		}
	}

	free(AB);
	free(ABAt);
	free(BtBt);
		
	return C;
}
