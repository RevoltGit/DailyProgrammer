#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int binary_decimal(int n)

{
    int decimal=0, i=0, rem;
    while (n!=0)
    {
        rem = n%10;
        n/=10;
        decimal += rem*pow(2,i);
        ++i;
    }
    return decimal;
}

int main(){

	
	int i, a, num, decimal, xor, decimal2;
	char *line = NULL;

	scanf("%ms", &line);

	int len = strlen(line);
	char temp[len];

	/* Print initial */

	for (i=0; i < strlen(line); i++){
		if ( line[i] == 48 ) { printf(" "); }
		if ( line[i] == 49 ) { printf("X"); }
		temp[i] = line[i];
	}

	printf("\n");

	/* Print the rest */

	for (a = 0; a < 6; a++ ){

		for (i=0; i<strlen(line); i++){

			if ( ( (i-1) < 0 ) && ( line[i+1] != line[i] ) && ( line[i] == 48 ) ) { temp[i] = 49; }
			if ( ( (i-1) < 0 ) && ( line[i+1] != line[i] ) && ( line[i] == 49 ) ) { temp[i] = 48; }
			if ( ( (i+1) >= len ) && ( temp[i] == 48 ) ) { temp[i] = 49; }
			if ( ( (i+1) >=  len ) && ( line[i] == 49 ) ) { temp[i] = 48; }
			if ( line[i] == line[i+2] ) {
				temp[i+1] = 48;
			}
			else if ( ( (i+1) >= len ) && ( temp[i-1] != temp[i] ) && ( temp[i-1] == 48 ) ) { temp[i] = 49; }
			else if ( ( (i+1) >= len ) && ( temp[i-1] != temp[i] ) && ( temp[i-1] == 49 ) ) { temp[i] = 48; }
			else if ( ( (i+1) >= len ) && ( temp[i-1] == temp[i] ) ) { temp[i] = 48; }
			else {  
				temp[i+1] = 49;
			}
			
		}

		for (i=0; i<strlen(line); i++){

			if ( temp[i] == 49 ) { printf("X"); } 
			else { printf(" "); }

			line[i] = temp[i];
		}

	printf("\n");
	}


/*
	for(i=0; i < len; i+=3) {
		char buffer[4];
		buffer[0] = line[i];
		buffer[1] = line[i+1];
		buffer[2] = line[i+2];
		buffer[3] = '\0';

		/* Now that we have our string stored in buffer,
			let's start making all of our conversions */
/*
		memcpy(d, buffer, sizeof(d));
		num = atoi(d);
		decimal = binary_decimal(num);
		printf("Decimal of ");
		printf(buffer);
		printf(" is %d.\n", decimal);
		decimal2 = binary_decimal(xor);
		printf("%d is xor.\n", decimal2);
	}
*/
	
	free(line);

}


