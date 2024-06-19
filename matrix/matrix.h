#ifndef MATRIX_H
#define MATRIX_H

#define TODO 1337

// Matrix Structure
typedef struct matrix {
	int rows;
	int cols; 
	double **entries; 
} matrix; 

// Matrix function prototypes
matrix * init_matrix (int rows, int cols); 
matrix * fill_matrix (matrix *m, double num);
matrix * copy_matrix (matrix *m);
matrix * flatten_matrix (matrix *m, int axis);

void print_matrix (matrix *m); 
void free_matrix (matrix *m);
void randomize_matrix (matrix *m, int n);  

int max_idx_matrix(matrix *v); 
#endif // matrix.h
