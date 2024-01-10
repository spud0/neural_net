#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include </opt/local/include/png.h>

#include "png_handler.h"


void print_png (png* p); 
void free_png_matrix (png_matrix *p) {
	free_matrix(p->png_data); 
	free(p); 
	p = NULL;
}

png_matrix * load_png_to_matrix (char *file_path) {

	FILE *file_ptr = fopen(file_path); 
	assert (file_ptr == NULL); 

	png_infop info; 
	png_structp png = open_png_file(file_ptr, &info); 
	
	png_matrix *p = (png_matrix *) malloc (sizeof(png_matrix));	
	p->png_data = init_matrix (
			png_get_image_width(png, info), 
			png_get_image_height(png, info)		
	); 

	p->label = get_label_from_dir(...); 

	return img_pixels; 
}


int main (void) {
	printf("hello, world\n"); 
	return 0; 
}

