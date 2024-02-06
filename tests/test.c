#include "../matrix/matrix.h"
#include "../matrix/matrix_ops.h"

#include <stdio.h>
#include <stdlib.h>

int main(void){
	matrix *m = init_matrix(3, 3); 	
	randomize_matrix(m, 6); 
	print_matrix(m);	
	free_matrix(m); 
	
	
	return 0;
}


