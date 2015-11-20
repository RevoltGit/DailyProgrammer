#include <stdio.h>

unsigned long long fib(unsigned long long num);

int main(){
	
	unsigned long long a = 0, b = 1, c = 0, d, i, num;

        scanf("%llu", &num);

	unsigned long long fibreturn = fib(num);

	if ( fibreturn == num ){
		printf("%llu %llu ", a, b);

		for ( i = 0; i < num; i++ ){

			while ( c < num ) {
				c = a + b; 
				a = b; 
				b = c; 
				printf("%llu ", c); 
			}
		}
	}

	else { 
		b = num/fibreturn;
		printf("%llu %llu ", a, b);
		for ( i = 0; i < num; i++ ){

			while ( c < num ) {
				c = a + b; 
				a = b; 
				b = c; 
				printf("%llu ", c); 
			}
		}
	}

	fputs("\n", stdout);
}

unsigned long long fib(unsigned long long num){

	unsigned long long a = 0, b = 1, c = 0, d, max_fact;

		while ( c < num ){ 
			c = a + b; 
			a = b; 
			b = c; 
			d = c;
			if ( num % d == 0 ){ max_fact = d; }
		}

	return max_fact;

}
