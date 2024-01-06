#include <math.h> 
#include <assert.h> 
#include <stdlib.h> 

#include <stdio.h> 

#include "matrix.h"
#include "matrix_ops.h"

// Initialize matrix to zeroes
matrix * init_matrix (int rows, int cols){
	
	assert((rows > 0) && (cols > 0)); 	

	// Space for the matrix
	matrix *res = (matrix *) malloc(sizeof(matrix)); 
	
	// Space for the rows and cols
	res->entries = (double **) malloc(rows * sizeof(double*)); 
	for (size_t i = 0; i < rows; i++){
		res->entries[i] = (double *) malloc(cols * sizeof(double)); 
		for (size_t j = 0; j < cols; j++) {
			// Set everything to zeroes
			res->entries[i][j] = 0.0; 
		}
	}	
	
	res->rows = rows; 
	res->cols = cols; 
	return res; 

}

// matrix * flatten_matrix (matrix *m, ...) {}

// Copy matrix into another one
matrix * copy_matrix (matrix *m){

	assert( (m == NULL) == 0 ); 
	
	matrix * res = init_matrix(m->rows, m->cols);

	for (size_t i = 0; i < m->rows; i++){
		for (size_t j = 0; j < m->cols; j++){
				res->entries[i][j] = m->entries[i][j]; 
		}
	}

	return res; 	
}


matrix * fill_matrix (matrix *m, double num){
	
	assert( (m == NULL) == 0 ); 

	matrix *res = init_matrix(m->rows, m->cols); 
	
	for (size_t i = 0; i < m->rows; i++){
		for (size_t j = 0; j < m->cols; j++){
				res->entries[i][j] = num; 
		}
	}

	return res;
}

	
void print_matrix (matrix *m){
	if (m == NULL){
		printf("ERROR: Couldn't print matrix, NULL"); // use errno
	}
		
	for (size_t i = 0; i < m->rows; i++){
		for (size_t j = 0; j < m->cols; j++){
			printf("%1.3f ", m->entries[i][j]); 
		}
		printf("\n"); 
	}
	
}

// void free_matrix(matrix *m) {}
// void randomize_matrix (matrix *m, int n){} 


