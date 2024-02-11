#ifndef NN_H
#define NN_H

#include "../matrix/matrix.h"
#include "../util/png_handler.h"


typedef struct nn {
	int input; 
	int hidden; 
	int output; 
	double learning_rate; 
	matrix * hidden_weights; 
	matrix * output_weights; 
} nn; 


nn * init_network(int input, int hidden, int output, double learning_rate); 
nn * load_network(const char * file_path); 


matrix * network_predict(nn * network, matrix * input_data); 
matrix * network_predict_file(nn * network, png_matrix *png); 

double 

void print_network(nn * network); 
void free_network (nn * network); 
void save_network (nn * network, const char * file_path); 
void train_network(nn * network, matrix * input_data, matrix * output_data); 

#endif // NN_H
