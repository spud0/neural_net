# compile like -> gcc -I/opt/local/include -L/opt/local/lib -w -lz -libpng ../matrix/matrix.c png_handler.c -o png
# https://stackoverflow.com/questions/20954719/png-h-not-found-in-mac-os-x-mavericks

CC = gcc 
CFLAGS = -I/opt/local/inlcude -L/opt/local/lib -w -lz -libpng

DEPS = ../matrix/matrix.c 