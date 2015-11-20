#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

	char cons[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
	char vow[5] = {'a','e','i','o','u'};
	int i, a=0;
	time_t t;

	char word[256];
	scanf("%s", word);

	for(i=0; word[i]!='\0'; ++i);

	/* Error handling */

	while ( a < i ){ 

		if ( ( word[a] != 67 ) && ( word[a] != 86 ) && ( word[a] != 99 ) && ( word[a] != 118 ) ) {

			printf("String must consist of c's and v's.\n");
			return 0;

		}
	
		a++;

	}

	/* End error handling */

	srand((unsigned) time(&t));

	for( a = 0 ; a < i ; a++ ){
		if ( word[a] == 67 ) {
      			int random = (rand() % 21);
			printf("%c", cons[random] - 32);
		}
		if ( word[a] == 86 ) {
      			int random = (rand() % 21);
			printf("%c", cons[random] - 32);
		}
		if ( word[a] == 99 ) {
      			int random = (rand() % 21);
			printf("%c", cons[random]);
		}
		if ( word[a] == 118 ) {
      			int random = (rand() % 21);
			printf("%c", cons[random]);
		}

   	}

}
