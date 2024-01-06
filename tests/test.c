#include "../matrix/matrix.h"
#include "../matrix/matrix_ops.h"

#include <stdio.h>

int main(void){
	//	matrix *m = init_matrix(5, 6); 

	matrix *m1 = init_matrix(3, 3); 
	matrix *m2 = init_matrix(3, 3); 
	matrix *m3 = init_matrix(3, 3); 
	matrix *m4 = init_matrix(3, 3); 

	m1 = fill_matrix(m1, 20.0);
	print_matrix(m1);

	m2 = fill_matrix(m2, -6.834); 
	matrix *m5 = add(m1, m2); 
	
	m3 = fill_matrix(m3, -11.43); 
	m4 = fill_matrix(m4, -0.0056);

	m4 = add(m3, m4); 
	m2 = subtract(m1, m4); 

	print_matrix(m4); 
	printf("\n"); 
	print_matrix(m2); 

	printf("\n"); 
	print_matrix(m5); 
			
	return 0; 

}


