#include <math.h> 
#include <assert.h> 
#include <stdlib.h> 

#include <stdio.h> 

#include "matrix.h"

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

void print_matrix(matrix *m){

}


int main(){
	matrix *m = init_matrix(5, 6); 

	printf("rows: %d\n cols: %d\n", m->rows, m->cols); 

	return 0; 

}
