#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int forward_check(char *line, int len, int i){

	for ( i = 0; i < len; i++ ){
		if (( line[i] > line[i+1] ) && ( i+1 < len )) { return 0; }
	}

	return 1;

}

int reverse_check(char *line, int len, int i){

	for (i = 0; i < len; i++){
		if ( ( line[i] < line[i+1] ) && ( i <= len-1 ) ){ return 0; } 
	}

	return 1;

}

int main(){

	int i, len;
	char *line = NULL;
	bool contin = 1;

	while ( scanf("%ms", &line) == 1 ){
	
		len = strlen(line);

		int forward = forward_check(line, len, i);
		int reverse = reverse_check(line, len, i);

		if ( forward == 1 ) { printf("%s IN ORDER\n", line); }
		else if ( reverse == 1 ) { printf("%s REVERSE ORDER\n", line); }
		else { printf("%s NOT IN ORDER\n", line); }

		free(line);

	}

}
