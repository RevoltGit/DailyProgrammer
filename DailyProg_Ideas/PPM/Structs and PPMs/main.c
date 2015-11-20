#include "functions.h"	

int main() {

	/* Variables */

	char *line = NULL;
	const char diagonal[] = "diagonal";
	const char circle[] = "circle";
	const char gradient[] = "gradient";
	char filename[10];
	int i = 0, a = 0, b = 0, c = 0;

	FILE *fp; //File pointer for output

	// Spointer for Shape(value) Struct
	struct values shape;
	struct values *sptr;
	sptr = &shape;

	// Cpointer for Colors(pixel) Struct
	struct pixel colors;
	struct pixel *cptr;
	cptr = &colors;

	printf("What would image would you like to make? ");
	scanf("%ms", &line);

	/******		DIAGONAL	******/

	if ( strcmp(line, diagonal) == 0 ) { 

		/* Neat filenaming trick prints diagonal.ppm to "filename"
		then uses the stored filename to create a file */
		sprintf(filename, "%s.ppm", diagonal); 
		fp = fopen (filename, "w+");

		// Two ways to do it. Neat.
		sptr->width=400;
		(*sptr).height=400;

		make_ppm_header(fp, sptr);

		make_diagonal(a, b, c, i, fp, sptr, cptr);
			
	
	}

	/******		GRADIENT	******/

	else if ( strcmp(line, gradient) == 0 ) {

		sprintf(filename, "%s.ppm", gradient);
		fp = fopen (filename, "w+");

		sptr->width=500;
		sptr->height=500;
		make_ppm_header(fp, sptr);

		make_gradient(a, i, fp, sptr, cptr);

	}


	/******		Error if Incorrect Input	******/

	else { 
		printf("You must choose between 'diagonal'");
		printf(" and 'gradient'!\n"); 
		fp = fopen("null.txt", "w+");
		remove("null.txt");
	}

	/* Free the memory */

	fclose(fp);
	free(line);

	return 0;
}
