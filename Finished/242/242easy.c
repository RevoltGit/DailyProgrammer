#include <stdio.h>

int Fibonacci(int i);

int main(){

	int i=0, a=0;
	int people, fruits;

        scanf("%d %d", &people, &fruits);

	    while ( (fruits * i) < people){
		i = Fibonacci(i);
		i = i*2;
		i += 1;
		a++;
	    }

	printf("%d\n", a+1);
}

int Fibonacci(int i){

	int a = 0, b = 1, c= 0;
	while (c < i){ c = a + b; a = b; b = c;  }
	return c;

}
