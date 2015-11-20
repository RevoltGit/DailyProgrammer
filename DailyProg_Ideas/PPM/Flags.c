#include <stdio.h>

void make_ppm_header (int width, int height);
void make_ppm_image (int country_code, int height);

int main()
{
	int width, height;
	int country_code = 3;

	// prompt user to enter width and country_code of chosen flag
	/* Read image dimensions and pixel color */

	fprintf(stderr, "0) Poland\n");
	fprintf(stderr, "1) Netherland\n");
	fprintf(stderr, "2) Italy\n");

	fprintf(stderr, "\nEnter the country code and width: ");

	while ( (country_code < 0) || (country_code > 2) ){
	fscanf(stdin, "%d %d", &country_code, &width);
	fprintf(stderr, "\n\nMaking country %d with width %d \n", country_code, width);
	}

	switch(country_code){
		case 0:
			fprintf(stderr, "0) Poland\n");
			height = (width*5)/8;
			make_ppm_header(width, height);
			fprintf(stderr, "Height is %d.\n", height);
			break;
		case 1:
			fprintf(stderr, "1) Netherland\n");
			height = (width*2)/3;
			make_ppm_header(width, height);
			break;
		case 2:
			fprintf(stderr, "2) Italy\n");
			height = (width*2)/3;
			make_ppm_header(width, height);
			break;
	}
			

	/* Write the image data */
	make_ppm_image(country_code, width);

return(0);
}

void make_pixel (
int r, // red intensity
int g, // green intensity
int b ) // blue intensity
{
fprintf(stdout, "%c%c%c", r, g, b);
}

void make_ppm_image(country_code, width){
	int i = 0;
	int height, heightdiv, heightdivthree, widthdivthree;
		switch(country_code){
		case 0:
			height = (width*5)/8;
			heightdiv = height/2;
			
				while (i < (width * heightdiv)){
				make_pixel(255, 255, 255);
				i++;
				}

				i = 0;

				while (i < (width * heightdiv)){
				make_pixel(220, 20, 60);
				i++;
				}

			break;

		case 1:
			height = (width*2)/3;
			heightdivthree = height/3;

				while (i < (width * height)/3){
				make_pixel(174, 28, 40);
				i++;
				}

				//i = 0;

				while (i < 2*(width * height)/3){
				make_pixel(255, 255, 255);
				i++;
				}

				//i = 0;

				while (i < (width * height)){
				make_pixel(33, 70, 139);
				i++;
				}

			break;
		case 2:
			height = (width*2)/3;
			widthdivthree = width/3;
			int widthdivtwo = width/2;
			int d = 0;
			i = 0;

			while ( d < height*width ) {
			
				while (i < width) {
				
				if (i < (widthdivthree)){
					make_pixel(0, 146, 70);
					i++;
				}

				else if (i < width*2/3){
				make_pixel(255, 255, 255);
				i++;
				}

				else {
				make_pixel(206, 43, 55);
				i++;
				}
				}
			i = 0;
			d++;
			}
		break;
	}
}

void make_ppm_header (int width, int height){
 // this is the header of the ppm file
	fprintf(stdout, "P6\n");
	fprintf(stdout, "%d %d 255\n", width, height);
}

