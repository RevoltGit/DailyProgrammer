#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void make_ppm_header();
void make_pixel();
void make_diagonal();
void make_gradient();

struct values {
	int 	width,
		height, 
		radius1, 
		radius2, 
		radius3; 
};

struct pixel {
	int 	red,
		green, 
		blue;
};

#endif
