

#include "matrix_ops.h"


// Matrix operations
matrix * dot_product (matrix *m){
}

 
matrix * add (matrix *m_one, matrix *m_two){
}

matrix * subtract (matrix *m_one, matrix *m_two){
}


matrix * transpose (matrix *m){
	static_assert(m == NULL); 

	matrix *res = init_matrix(m->cols, m->rows); 
	
	for (size_t i = 0; i < res->rows; i++){
		for (size_t j = 0; j < res->cols; j++) {
			res[i][j] = m[j][i]; 
		}
	}	

	return res; 

} 
matrix * multiply (matrix *m_one, matrix *m_two){


}


matrix * mult_scalar (double scalar, matrix *m){

}


matrix * add_scalar (double scalar, matrix *m){ 

}
