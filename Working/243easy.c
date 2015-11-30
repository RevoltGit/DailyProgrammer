#include <stdio.h>
#include <stdlib.h>

int main(){

	int numarray[100], counter, a, b=0, c=0, i=0;
	int divarray[100][100];

	while ( scanf("%d", &numarray[i++]) == 1 ){}

	counter = i;
	
	for ( a = 0; a < counter; a++ ){
		for ( i = 0; i < numarray[a]; i++ ){
			if ( numarray[a] % i == 0 ){
				divarray[b][c++] = i;
			}
			b++;
		}
	}

}
