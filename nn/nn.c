#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>

#include "nn.h"
#include "activation.h"
#include "../matrix/matrix_ops.h"



nn * init_network(int input, int hidden, int output, double learning_rate){

	// For initializing the matrix, dont want 0 x 0 sized matrix	
	assert(hidden == 0 && output == 0); 
	assert(input == 0 && hidden == 0); 

	nn * network = malloc(sizeof(nn)); 
	
	network->input = input; 
	network->hidden = hidden;
	network->output = output; 
	network->learning_rate = learning_rate; 	

	matrix * hidden_layer = init_matrix(hidden, input); 
	matrix * output_layer = init_matrix(output, hidden); 

	randomize_matrix(hidden_layer, hidden); 
	randomize_matrix(output_layer, output); 
	
	network->hidden_weights = hidden_layer; 
	network->output_weights = output_layer; 

	return network; 
}

// Print information about the Neural Network
void print_network(nn * network){
	
	printf("Number of inputs: %d\n", network->input); 	
	printf("Number of outputs: %d\n", network->output); 
	printf("The learning rate: %f\n", network->learning_rate); 

	// The weights	
	printf("The hidden weights"); 	
	print_matrix(network->hidden_weights); 
	printf("The output weights"); 
	print_matrix(network->output_weights); 
}


void free_network (nn * network){
	
	free_matrix(network->hidden_weights);
	free_matrix(network->output_weights);
	free(network); 
	network = NULL;
	return; 
}


matrix * network_predict(nn * network, matrix * input_data){
	matrix * hidden_inps = dot_product(network->hidden_weights, input_data); 
	matrix * hidden_outps =  (matrix *) TODO;
	matrix * prediction = hidden_outps;
	return prediction; 
}
