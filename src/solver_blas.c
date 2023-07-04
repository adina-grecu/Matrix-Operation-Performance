/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"
#include "cblas.h"
#include "string.h"

/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {

	double *C = calloc(N * N, sizeof(double));

	//copie matrice B
	double *Bcopy = calloc(N * N, sizeof(double));
	memcpy(Bcopy, B, N * N * sizeof(double));

	//A * B, rezultatul in matricea B
	cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, N, N, 1, A, N, B, N);

	//AB * At, rezultatul in matricea B
	cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasTrans, CblasNonUnit, N, N, 1, A, N, B, N); 

	//Bt * Bt + ABAt, rezultatul in matricea B
	cblas_dgemm(CblasRowMajor, CblasTrans, CblasTrans, N, N, N, 1, Bcopy, N, Bcopy, N, 1, B, N);

	//C = B
	memcpy(C, B, N * N * sizeof(double));
	free(Bcopy);
	
	return C;
}
