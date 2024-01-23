#include <math.h>
#include "activation.h"
#include "../matrix/matrix_ops.h"


double sigmoid (double input) {
	return 1.0 / (1 + exp(-1 * input); 
}


matrix *derivative_sigmoid (matrix *m) {
	// 
	matrix * m_ones = init_matrix(m->rows, m->cols); 
	m_ones = matrix_fill(m_ones , 1); 

	matrix *subtracted = subtract(m_ones, m); 
	matrix *mult = multiply(m, subtracted); 
	
	free_matrix(m_ones); 
	free_matrix(subtracted);
	return mult;
}



matrix *softmax (matrix *m);
