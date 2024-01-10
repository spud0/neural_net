#ifndef PNG_H
#define PNG_H

#include "../matrix/matrix.h"

typedef struct {
	matrix *png_data; 
	size_t png_label;
} png_matrix; 


int get_label_from_dir (const char *dir_name); 
png_matrix * load_png_to_matrix (char *file_path); 
void print_png (png* p); 
void free_png_matrix (png *p); 

#endif // png.h
