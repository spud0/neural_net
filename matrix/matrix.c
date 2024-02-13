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
	res->entries = (double **) malloc( (rows) * sizeof(double*)); 
	for (size_t i = 0; i < rows; i++){
		res->entries[i] = (double *) malloc( (cols) * sizeof(double)); 
		for (size_t j = 0; j < cols; j++) {
			// Set everything to zeroes
			res->entries[i][j] = 0.0; 
		}
	}	
	
	res->rows = rows; 
	res->cols = cols; 
	return res; 

}

matrix * fill_matrix (matrix *m, double num){
	
	assert( (m == NULL) == 0 ); 

	for (size_t i = 0; i < m->rows; i++){
		for (size_t j = 0; j < m->cols; j++){
				m->entries[i][j] = num; 
		}
	}

	return m;
}

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

void write_matrix_to_file(matrix *m, const char * file_path){
	FILE * file_ptr = fopen(file_path, "wb"); 
	fprintf(file_ptr, "%d\n", m->cols);	
	fprintf(file_ptr, "%d\n", m->rows);

	for (size_t i = 0; i < m->rows; i++){
		for (size_t j = 0; j < m->cols; j++) {
			fprintf(file_ptr, "%.5f\n", m->entries[i][j]); 
		}
	}

	printf("Wrote matrix to file: %s", file_path);	
	fclose(file_ptr); 
}	
	
matrix * flatten_matrix (matrix *m, int axis) {

	matrix *v; 

	if (axis == 0) {
		v = init_matrix(m->rows * m->cols, 1); 
	} else if (axis == 1) {
		v = init_matrix (1, m->rows * m->cols); 
	} else {
		assert (0); 
	}

	for (size_t i = 0; i < m->rows; i++) {
		for (size_t j = 0; j < m->cols; j++) {
			if (axis == 0) {
				v->entries[i * m->cols + j][0] = m->entries[i][j]; 
			} else {
				v->entries[0][i * m->cols + j] = m->entries[i][j]; 				
			}
		}
	}

	return v; 
}

double uniform_distrib (double min, double max) {
	double diff = max - min; 
	size_t scale = 10000; 
	size_t scaled_diff = (size_t) (diff * scale); 
	return min + ( (rand() % scaled_diff ) / scale); 
}

void randomize_matrix (matrix *m, int n){
	
	assert ( (m == NULL) == 0); 

	double min = -5.0 / sqrt(n); 
	double max =  5.0 / sqrt(n);   
	for (size_t i = 0; i < m->rows; i++){
		for (size_t j = 0; j < m->cols; j++) {
			m->entries[i][j] = uniform_distrib(min, max); 
		}
	}
}

	
void free_matrix(matrix *m) {
	
	assert( (m == NULL) == 0); 
	for (size_t i = 0; i < m->rows; i++){
		free(m->entries[i]); 
	}
	free(m->entries); 
	free(m); 
	// m = NULL; 
}

void print_matrix (matrix *m){

	assert ( (m == NULL) == 0);	

	printf("Rows: %d\nCols: %d\n", m->rows, m->cols); 
	
	for (size_t i = 0; i < m->rows; i++){
		for (size_t j = 0; j < m->cols; j++){
			printf("%1.5f ", m->entries[i][j]); 
		}
		printf("\n"); 
	}
	
}


// Take in a vector (1D Matrix)
int max_idx_matrix(matrix *v) {
	double max = 0; 
	int max_idx = 0; 
	
	for (size_t i = 0; i < v->rows; i++) {
		if (v->entries[i][0] > max) {
			max = v->entries[i][0]; 
			max_idx = i; 
		}

	}
	return max_idx; 
}
