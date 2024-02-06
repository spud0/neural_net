#include <stdio.h> 
#include <stdlib.h>

#include "nn.h"
#include "../matrix/matrix_ops.h"
#include "../neurons/activation.h"



nn * init_network(int input, int hidden, int output, double learning_rate){

	nn * network = malloc(sizeof(nn)); 
	
	network->input = input; 
	network->hidden = hidden;
	network->output = output; 
	network->learning_rate = learning_rate; 	

	return network; 
}



void print_network(nn * network){
	
	printf("Number of inputs: %d\n", network->input); 	
	printf("Number of outputs: %d\n", network->output); 
	printf("The learning rate: %d\n", network->learning_rate); 
	
	// The weights	
	print_matrix(network->hidden_weights); 
	print_matrix(network->output_weights); 
}


void free_network (nn * network){
	
	free_matrix(network->hidden_weights);
	free_matrix(network->output_weights);
	free(network); 
	network = NULL
	return; 
}
