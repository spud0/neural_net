#include <math.h>
#include "activation.h"
#include "../matrix/matrix_ops.h"

double sigmoid (double input) {
	return 1.0 / (1 + exp(-1 * input); 
}

matrix *derivative_sigmoid (matrix *m) {
	// 
	matrix *m_ones = init_matrix(m->rows, m->cols); 
	m_ones = matrix_fill(m_ones , 1); 

	matrix *subtracted = subtract(m_ones, m); 
	matrix *mult = multiply(m, subtracted); 
	
	free_matrix(m_ones); 
	free_matrix(subtracted);
	return mult;
}


matrix *softmax (matrix *m) {
	double total = 0;
	for (size_t i = 0; i < m->rows; i++){
		for (size_t j = 0; j < m->cols; j++){
			total += exp(m->entries[i][j]); 
		}
	}

	matrix * res = init_matrix(m->rows, m->cols); 
	
	for (size_t i = 0; i < res->rows; i++){
		for (size_t j = 0; j < res->cols; j++){
			res->entries[i][j] = exp(m->entries[i][j]) / total; 
		}
	}
	return res; 		

}
