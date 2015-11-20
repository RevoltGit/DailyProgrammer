#include "functions.h"

/*Makes the standard ppm header */
void make_ppm_header(FILE *fp, struct values *sptr){
	fprintf(fp, "P6\n");
	fprintf(fp, "%d %d 255\n", sptr->width, sptr->height);
}

/* Creates each set of r,g,b pixels */
void make_pixel(FILE *fp, struct pixel *cptr){
	fprintf(fp, "%c%c%c", cptr->red, cptr->green, cptr->blue);
}

/* Makes the diagonal ppm file */
void make_diagonal(int a, int b, int c, int i, FILE *fp, struct values *sptr, struct pixel *cptr){
	
	while ( a < sptr->height){
		while ( sptr->width > 0){
			cptr->red = 50;
			cptr->blue = 185;
			cptr->green = 164;
			make_pixel(fp, cptr);
			sptr->width--;
		}

		while ( b > 0 ){
			(*cptr).red = 110;
			(*cptr).blue = 85;
			(*cptr).green = 164;
			make_pixel(fp, cptr);
			b--;
		}

		c++;
		i++;
		a++;
		sptr->width = (400 - i);
		b = c;
	}

}

/* Makes the gradient ppm file */
void make_gradient(int a, int i, FILE *fp, struct values *sptr, struct pixel *cptr){

	cptr->red = 255;
	cptr->blue = 255;
	cptr->green = 255;

	for ( a = 0; a < sptr->height; a++){ 
		for ( i = 0; i < sptr->width; i++){

			make_pixel(fp, cptr);

			if ( 
				( i > (sptr->width/3)) && 
				( i < (sptr->width * 2 / 3) ) && 
				( cptr->red > 0 )) 
			
				{cptr->red--;}
			}

	cptr->red = 255;
	cptr->blue = 255;
	cptr->green = 255;

	}
}
