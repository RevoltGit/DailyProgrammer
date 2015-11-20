	#include <stdio.h>
	#include <time.h>
	#include <stdint.h>

	inline uint64_t rdtsc() {
	    uint32_t lo, hi;
	    __asm__ __volatile__ (
	      "xorl %%eax, %%eax\n"
	      "cpuid\n"
	      "rdtsc\n"
	      : "=a" (lo), "=d" (hi)
	      :
	      : "%ebx", "%ecx");
	    return (uint64_t)hi << 32 | lo;
	}

	int main(){

		int a, count = 0, finished = 0;
		time_t t;
		unsigned long long start, i, q, n;

		int x[] = {-1, 2};
		int y[] = {-1, 1};
		int z[] = {-2, 1};

		srand((unsigned) time(&t));

		printf("What is your starting number? ");
		scanf("%llu", &start);
		unsigned long long stored = start;

		FILE *fp;
		n = rdtsc();

		while ( finished != 1 ) {

		fp = fopen("Solution.txt", "w+");
		fprintf(fp, "Starting number is %llu\n", start);
		fprintf(fp, "================================\n\n");

			while ( start != 1 ) {

				if ( start % 3 == 0 ){

					start = start/3;

					if ( start % 3 == 0 ){ 
						fprintf(fp, "%llu 0\n", start);
					}

				}

				else if ( start == 2 ) {
					a = rand() % 2;
					if ( y[a] > 0 ) {
						fprintf(fp, "%llu +1\n", start, y[a]);
					}
					if ( y[a] < 0 ) {
						fprintf(fp, "%llu -1\n", start, y[a]);
					}
					start = start+y[a];
					count+=y[a];
				}

				else if ( start % 3 == 1 ) {
					a = rand() % 2;
					if ( x[a] > 0 ) {
						fprintf(fp, "%llu +2\n", start, x[a]);
					}
					if ( x[a] < 0 ) {
						fprintf(fp, "%llu -1\n", start, x[a]);
					}
					start = start+x[a];
					count+=x[a];
				}

				else if ( start % 3 == 2 ) {
					a = rand() % 2;
					if ( z[a] > 0 ) {
						fprintf(fp, "%llu +1\n", start, z[a]);
					}
					if ( z[a] < 0 ) {
						fprintf(fp, "%llu -2\n", start, z[a]);
					}
					start = start+z[a];
					count+=z[a]; 
				}

			}

			fclose(fp);

			fprintf(fp, "%llu\n", start);

				if (( count == 0 ) && ( start == 1 )) { 
					finished = 1; 
				} else { start = stored; count = 0; }
		}

    q = rdtsc();
    printf("it took this long to call printf: %lld\n",q-n);
	}
