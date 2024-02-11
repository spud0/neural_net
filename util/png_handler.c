#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <png.h>

#include "png_handler.h"
#include "../matrix/matrix.h"

// Unsure about approach
int get_label_from_dir(const char *dir_name ) {
	int idx = -1; 
	if (sscanf(dir_name, "%d/", &idx) == 1) {
		return idx; 
	}
	return idx; 
}

void print_png (png_matrix* p){ 
	assert( (p == NULL) == 0);
	printf("Label for png file: %zu\n", p->png_label); 
	print_matrix (p->png_data); 
}
	
void free_png_matrix (png_matrix *p) {
	assert( (p == NULL) == 0); 
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

png_matrix * load_file_to_png_matrix (char *file_path) {

	FILE *file_ptr = fopen(file_path, "rb"); 
	assert ( (file_ptr == NULL ) == 0); 

	png_infop info; 
	png_structp png = open_png_file(file_ptr, &info); 

	int width = png_get_image_width(png, info);
	int height = png_get_image_height(png, info); 

	png_matrix *p = (png_matrix *) malloc (sizeof(png_matrix));	
	p->png_data = init_matrix (width, height); 

	png_bytep *row_ptrs = allocate_row_pointers(height, png, info); 
	populate_matrix_from_image(png, row_ptrs, p); 

	// Clean up resources
	for (size_t i = 0; i < height; i++){
		free(row_ptrs[i]); 
	}

	free(row_ptrs); 
	fclose(file_ptr); 
	png_destroy_read_struct(&png, &info, NULL); 
	
	#if 0
	// Split the full file path by the '/' char and take the number part... 
	p->label = get_label_from_dir(...); 
	# endif 

	return p; 
}


#if 0
void write_png_to_file(const char *file_path, png_matrix *p){

	FILE * file_ptr = fopen(file_path, "a"); 
	
	for (size_t i = 0; i < p->png_data->cols; i++){
		for (size_t j = 0; j < p->png_data->rows; j++) {
			fprintf(file_ptr, file_path); 
			// TODO: Figure out if I want a string here
			fprintf(file_ptr, ... );  
		}
	}
}
#endif

int main (void) {

	// load my file into the png_matrix type
	png_matrix *p = load_file_to_png_matrix ("../assets/image_file.png"); 
	print_matrix(p->png_data); 
	free_png_matrix(p); 	

	return 0; 
}

