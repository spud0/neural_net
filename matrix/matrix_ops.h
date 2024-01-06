#include <stdbool.h>

#include "matrix.h"

// Matrix operations
matrix * dot_prodcut (matrix *m); 
matrix * add (matrix *m_one, matrix *m_two);
matrix * subtract (matrix *m_one, matrix *m_two); 
matrix * transpose (matrix *m); 
matrix * multiply (matrix *m_one, matrix *m_two); 
matrix * multiply_scalar(double scalar, matrix *m); 
matrix * add_scalar(double scalar, matrix *m); 
bool verify_dimensions(matrix *m_one, matrix *m_two);
