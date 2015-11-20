#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {

	int i, j, y, count, zerocount = 0, onecount = 0, maxzero = 0, maxone = 0;

	/* Input the game board */

	printf("How many columns are there? ");

	scanf("%d", &count);

	printf("Count is %d\n\n", count);

	char a[count][count];

	/* Scan for the input */

	for (i = 0; i < count; i++){

		j = 0;

		for (j = 0; j < count; j++){
		
			scanf(" %c", &a[i][j]);

		}

	}

	fputs("\n", stdout);

	/* Print the input in a neat, spaced grid */

	for (i = 0; i < count; i++){

		j = 0;

		for (j = 0; j < count; j++){

			printf("%c ", a[i][j]);

		}

		fputs("\n", stdout);

	}

	/* Calculate max amount of 0s or 1s per row */
	/* Upon further notice, it appears the max amount of 0s and 1s
	is x/2 where x is the number of columns/rows. */

	maxzero = count/2;

	printf("Maxzero is %d\n", maxzero);

	int z = maxzero;

	/* Let's check all of our stuff line by line */

for ( y = z; y >= 0; y-- ){

	for (i = 0; i < count; i++){

		maxone = z;
		maxzero = z;

		j = 0;

		for (j = 0; j < count; j++){


			/* Max check */


			if ( a[i][j] == 48 ) { maxzero--; }
			if ( a[i][j] == 49 ) { maxone--; }


			if ( maxzero == 0 ) { 
				for (j = 0; j < count; j++){ 
					if (a[i][j] == 46) { a[i][j] = 49;  }
				}
			}

			if ( maxone == 0 ) { 
				for (j = 0; j < count; j++){ 
					if (a[i][j] == 46) { a[i][j] = 48; }
				}
			}


			/* If the dot has a 0 on both sides, make it a 1 */

			if ( 	(a[i][j] == 46) && 
				(a[i][j-1] == 48) && 
				(a[i][j+1] == 48) 
			) { a[i][j] = 49; }


			/* If the dot has a 1 on both sides, make it a 0 */

			if ( 	(a[i][j] == 46) && 
				(a[i][j-1] == 49) && 
				(a[i][j+1] == 49) 
			) { a[i][j] = 48; }
		}

	}

	/* Vertical max check */

	for (j = 0; j < count; j++){

		maxone = z;
		maxzero = z;

		i = 0;

		for (i = 0; i < count; i++){


			/* Max check */


			if ( a[i][j] == 48 ) { maxzero--; }
			if ( a[i][j] == 49 ) { maxone--; }


			if ( maxzero == 0 ) { 
				for (i = 0; i < count; i++){ 
					if (a[i][j] == 46) { a[i][j] = 49;  }
				}
			}

			if ( maxone == 0 ) { 
				for (i = 0; i < count; i++){ 
					if (a[i][j] == 46) { a[i][j] = 48; }
				}
			}

		}

	}

	for (i = 0; i < count; i++){

		j = 0;

		for (j = 0; j < count; j++){

			printf("%c ", a[i][j]);

		}

		fputs("\n", stdout);

	}

fputs("\n", stdout);
fputs("\n", stdout);

}
/*

	for (j = 0; j < count; j++){

		i = 0;

		for (i = 0; i < count; i++){

			if ( 	(a[i][j] == 48) && 
				(a[i][j] == a[i][j+1]) && 
				(a[i][j] == a[i][j-1]) 
			) { a[i][j] = 49; } 

			if ( 	(a[i][j] == 48) && 
				(a[i][j] == a[i][j+1]) && 
				(a[i][j] == a[i][j+2]) 
			) { a[i][j] = 49; }


		}


	}

*/

	/* ----------- Print it out one last time ----------- */

	for (i = 0; i < count; i++){

		j = 0;

		for (j = 0; j < count; j++){

			printf("%c ", a[i][j]);

		}

		fputs("\n", stdout);

	}

	fputs("\n", stdout);

	return 0;

}
