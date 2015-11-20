#include <stdio.h>

int guess_check(int guess, int num){

	if ( guess > num ) { return 0; }
	if ( guess < num ) { return 1; }
	if ( guess == num ) { return 2; }

}

int main(){

	int num, i, high = 101, low = 0, count = 0;

	printf("Enter a number between 1 and 100: ");
	scanf("%d", &num);

	int guess = (high+low)/2;

	for ( i = 0; i < 100; i++){

		int next = guess_check(guess, num);

		if ( next == 0 ){ 
			high = guess;
			guess = (high+low)/2; 
			printf("Guess is %d\n", guess);
			count++;
		}

		if ( next == 1 ){
			low = guess;
			guess = (high+low)/2;
			printf("Guess is %d\n", guess);
			count++;
		}

		if ( next == 2 ){ 
			printf("Final guess is %d in %d count.\n", guess, count); 
			return 0;
		}

	}


}
