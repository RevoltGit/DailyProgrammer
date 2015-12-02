#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[]){

	FILE *in;
	in = fopen(argv[1], "r");

	if ( argc != 2 ) { printf("Must supply in.txt!\n"); exit(0); }

	int numlist[100] = {}, fruitcount[100] = {};
	int a = 0, b = 0, c = 0, i = 0, total = 500, counter = 0;
	char stringlist[100][100] = {};

	while (fscanf(in, "%s %d", &stringlist[i], &numlist[i]) != -1){i++;}

	for (;;){
		if ( total - numlist[a] < 0 ) { a++; counter++; }
		else if (total - numlist[a] > 0 ) {
			fruitcount[a]++;
			total = total - numlist[a++];
		}
		if ( a > i-1 ) { a = 0; }
		if ( counter > i ){ break; }
	}

	for (a = 0; a < i; a++){
		printf("%s %d\n", stringlist[a], fruitcount[a]);
	}

}
