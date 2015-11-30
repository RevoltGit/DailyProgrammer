	#include <stdio.h>
	#include <stdlib.h>

	int main( int argc, char *argv[] ){

		FILE *in;
		FILE *out;

		in = fopen(argv[1], "r+");
		out = fopen("out.txt", "w+");

		int numarray[100], counter, a, b=0, c=0, d=0, i=0, sum=0;
		int divarray[100][100];

		while ( fscanf(in, "%d", &numarray[i++]) == 1 ){}

		counter = --i;

		for ( a = 0; a < counter; a++ ){
			fprintf(out, "%d ", numarray[a]);
		}

		fprintf(out, "\n\n");

		/* Storing the divsors in an array */

		for ( a = 0; a < counter; a++ ){
			for ( i = 1; i < numarray[a]; i++ ){
				if ( numarray[a] % i == 0 ){
					divarray[b][c++] = i;
				}
			}

			/* We need the highest column count so we print them all */
			if ( c > d ){ d=c; } 
			c=0;
			b++;

		}

		c=d;

		/* Printing the entire array */

		for (a = 0; a < b; a++) {
			for (i = 0; i < c; i++) {
				if ( divarray[a][i] == 0 ){ fprintf(out, ". \t");}
				else { fprintf(out, "%d \t", divarray[a][i]); }
			}
			fprintf(out, "\n");
		}

		fprintf(out,"\n"); 

		/* Individual number output */

		for (a = 0; a < b; a++) {
			fprintf(out, "Divisors of %d are: ", numarray[a]);
			for (i = 0; i < c; i++) {
				if ( divarray[a][i] != 0 ){
					fprintf(out, "%d ", divarray[a][i]);
				}
			}
			fprintf(out, "\n");
		}

		fprintf(out, "\n");

		/* Number check for deficient, abundant, or perfect */

		for (a = 0; a < b; a++) {
			fprintf(out, "Inclusive sum of divisors of ");
			fprintf(out, "%d is: ", numarray[a]);
			sum+=numarray[a];
			for (i = 0; i < c; i++) {
				if ( divarray[a][i] != 0 ){
					sum+=divarray[a][i];
				}
			}
			fprintf(out, "%d\n", sum);
			if ( sum > (2*numarray[a]) ){ 
				fprintf(out, "%d is abundant by %d\n\n", numarray[a], (sum - (2*numarray[a])));
			}
			else if ( sum < (2*numarray[a]) ){ 
				fprintf(out, "%d is deficient by %d\n\n", numarray[a], ((2*numarray[a])-sum));
			}
			else { fprintf(out, "%d neither\n\n", numarray[a]); }
			sum = 0;
		}

	}
