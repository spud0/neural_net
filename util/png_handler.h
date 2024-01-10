#ifndef PNG_HANDLER_H
#define PNG_HANDLER_H

#include "../matrix/matrix.h"

typedef struct png_matrix {
	matrix *png_data; 
	size_t png_label;
} png_matrix; 


int get_label_from_dir (const char *dir_name); 
png_matrix * load_png_to_matrix (char *file_path); 
void print_png (png_matrix *p); 
void free_png_matrix (png_matrix *p); 

#endif // png_handler.h
