#include <stdbool.h> 
#include <assert.h> 
#include <stdlib.h> 

#include "matrix_ops.h"


bool verify_dimensions(matrix *m_one, matrix *m_two){
	if ((m_one->rows == m_two->rows) && (m_one->cols == m_two->cols)) {
		return true; 
	} else {
		return false; 
	}

}


// Matrix operations
// matrix * dot_product (matrix *m){}

 
matrix * add (matrix *m_one, matrix *m_two){
	// Matrices aren't NULL
	assert( ((m_one == NULL) && (m_two == NULL)) == 0 ); 

	// Have the same rows and columns
	assert( (verify_dimensions(m_one, m_two) == false) == 0); 
	
	matrix *res = init_matrix(m_one->rows, m_one->cols); 

	for (size_t i = 0; i < m_one->rows; i++){
		for (size_t j = 0; j < m_one->cols; j++) {
			res->entries[i][j] = m_one->entries[i][j] + m_two->entries[i][j]; 
		}
	}

	return res; 		

}

matrix * subtract (matrix *m_one, matrix *m_two){

	// Matrices aren't NULL

	assert( (verify_dimensions(m_one, m_two) == false) == 0); 

	// Have the same rows and columns
	
	matrix *res = init_matrix(m_one->rows, m_one->cols); 

	for (size_t i = 0; i < m_one->rows; i++){
		for (size_t j = 0; j < m_one->cols; j++) {
			res->entries[i][j] = m_one->entries[i][j] -  m_two->entries[i][j]; 
		}
	}

	return res;
}


matrix * transpose (matrix *m){
	assert ( (m == NULL) == 0);  

	// Flip input, {cols, rows} vs {rows, cols}
	matrix *res = init_matrix(m->cols, m->rows); 
	
	for (size_t i = 0; i < res->rows; i++){
		for (size_t j = 0; j < res->cols; j++) {
			res->entries[i][j] = m->entries[j][i];
		}
	}	

	return res; 

} 

// matrix * multiply (matrix *m_one, matrix *m_two){ }


matrix * mult_scalar (double scalar, matrix *m){ 

	assert ( (m == NULL) == 0);  
	matrix *res = init_matrix(m->rows, m->cols); 

	for (size_t i = 0; i < res->rows; i++){
		for (size_t j = 0; j < res->cols; j++) {
			res->entries[i][j] = res->entries[i][j] * scalar; 
		}
	}	
	return res; 
}


matrix * add_scalar (double scalar, matrix *m){
 	
	assert ( (m == NULL) == 0);  
	matrix *res = init_matrix(m->rows, m->cols); 

	for (size_t i = 0; i < res->rows; i++){
		for (size_t j = 0; j < res->cols; j++) {
			res->entries[i][j] = res->entries[i][j] + scalar;
		}
	}	
	return res; 
}