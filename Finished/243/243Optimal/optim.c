#include <stdio.h>
#include <stdlib.h>

int sumDivsDynamic(int n);

int main(int argc, char *argv[]){

	FILE *in;
	in = fopen(argv[1], "r+");
	int num, sum;

	while ( fscanf(in, "%d", &num) == 1 ){
		sum = sumDivsDynamic(num);
		if ((num-sum) > 0){ printf("%d deficient\n", num); }
		else if ((num-sum) < 0){ printf("%d abundant by %d\n", num, sum-num); }
		else { printf("%d neither\n", num); }
	}

	fclose(in);

}

int sumDivsDynamic(int n) {
  int i = 2, sum = 1, lower = n/2 + 1;
  while (i < lower) {
    if (n % i == 0) {
      lower = n/i;
      sum += i == lower ? i : i + lower;
    }
    i += 1;
  }
  return sum;
}
