#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <png.h>

#include "png_handler.h"

// Unsure about approach
int get_label_from_dir(const char *dir_name ) {
	int idx = -1; 
	if (sscanf(dir_name, "%d/", &idx) == 1) {
		return idx; 
	}
	return idx; 
}

void print_png (png_matrix* p){ 
	assert(p == NULL);
	printf("Label for png file: %zu\n", p->png_label); 
	print_matrix (p->png_data); 
}
	
void free_png_matrix (png_matrix *p) {
	assert(p == NULL); 
	free_matrix(p->png_data); 
	free(p); 
	p = NULL;
}


// Open and initialize libpng
png_structp open_png_file (FILE *file_ptr, png_infop *info) {

	png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL); 
	if (!png) {
		fclose(file_ptr); 
		return NULL; 
	}

	*info = png_create_info_struct(png); 
	if (!info) {
		png_destroy_read_struct(&png, NULL, NULL); 
		fclose (file_ptr); 
		return NULL; 
	}

	if (setjmp(png_jmpbuf(png))) {
		png_destroy_read_struct(&png, info, NULL); 
		fclose(file_ptr); 
		return NULL; 
	}

	png_init_io(png, file_ptr); 	
	png_read_info(png, *info); 	

	return png; 
}

// Allocate memory for row pointers 
png_bytep * allocate_row_pointers (int height, png_structp png, png_infop info) {

	png_bytep * row_ptrs = 	malloc(height * sizeof(png_bytep)); 
	for (size_t i = 0; i < height; i++){
		row_ptrs[i] = malloc(png_get_rowbytes(png, info)); 
	}	
		
	return row_ptrs; 
}


// Read image data into png_data field s
void populate_matrix_from_image(png_structp png, png_bytep *row_ptrs, png_matrix *p) {
	
	int height = p->png_data->cols;
	int width  = p->png_data->rows; 
	
	png_read_image(png, row_ptrs); 

	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {
			p->png_data->entries[i][j] = row_ptrs[i][j]; 		
		}
	}
}


/*
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
	

	// Split the full file path by the '/' char and take the number part... 
	//p->label = get_label_from_dir(...); 

	return p; 
}
*/

void write_png_to_file(const char *file_path, png_matrix *p){

	FILE * file_ptr = fopen(file_path, "wb"); 
	
	for (size_t i = 0; i < ; i++){
		for (size_t j = 0; j < ...; j++) {
			// TODO: Write the contents of a PNG file to a TXT as a Matrix 		
		}
	}


}



int main (void) {
	printf("hello, world\n"); 
	return 0; 
}

