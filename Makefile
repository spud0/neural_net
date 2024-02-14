# compile like -> gcc -I/opt/local/include -L/opt/local/lib -w -lz -lpng ../matrix/matrix.c png_handler.c -o png
# DEPS = ../matrix/matrix.c 

CC = gcc 
PNGFLAGS = -I/opt/local/inlcude -L/opt/local/lib -w -lz -libpng
FLAGS = -march=native

png: png_handler.c 
	$(CC) $(PNGFlAGS) $(FLAGS) util/png_handler.c  util/png_handler.h matrix/matrix.c -o png


m: matrix.c 
	$(CC) $(FLAGS) matrix/matrix.h

nn: nn/nn.c 
	$(CC) $(FLAGS) nn/nn.c

main: main.c 
	$(CC)

clean: 
	rm -f ... 
