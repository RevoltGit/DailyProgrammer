#include <stdio.h>

int main(){
	int start;

	printf("What is your starting number? ");
	scanf("%d", &start);

	while ( start != 1 ) {
		if ( start % 3 == 0 ) {  start = start/3;  if ( start % 3 == 0 ) { printf("%d 0\n", start);}}
		else if ( start % 3 == 1 ) { printf("%d -1\n", start); start = start-1;  }
		else if ( start % 3 == 2 ) { printf("%d 1\n", start); start = start+1;  }
	}
	printf("%d\n", start);
}
