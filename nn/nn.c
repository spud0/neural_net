#include <stdio.h> 
#include <stdlib.h>


#include "nn.h"
#include "../matrix/matrix_ops.h"
#include "../neurons/activation.h"



void print_network(nn * network){

}


void free_network (nn * network){
	
	free_matrix(network->hidden_weights);
	free_matrix(network->output_weights);
	free(network); 
	network = NULL
	return; 
}
