#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ){

    FILE *in;
    in = fopen(argv[1], "r+");

    int numarray[100], counter, a, b=0, c=0, d=0, i=0, sum=0;
    int divarray[100][100];

    while ( fscanf(in, "%d", &numarray[i++]) == 1 ){}

    counter = --i;

    for ( a = 0; a < counter; a++ ){
        for ( i = 1; i < numarray[a]; i++ ){
            if ( numarray[a] % i == 0 ){
                divarray[b][c++] = i;
            }
        }
        if ( c > d ){ d=c; } 
        c=0;
        b++;
    }

    c=d;

    for (a = 0; a < b; a++) {
        sum+=numarray[a];
        for (i = 0; i < c; i++) {
            if ( divarray[a][i] != 0 ){
                sum+=divarray[a][i];
            }
        }
        if ( sum > (2*numarray[a]) ){ 
            printf("%d is abundant by %d\n", numarray[a], (sum - (2*numarray[a])));
        }
        else if ( sum < (2*numarray[a]) ){ 
            printf("%d is deficient by %d\n", numarray[a], ((2*numarray[a])-sum));
        }
        else { printf("%d neither\n", numarray[a]); }
        sum = 0;
    }

    free(in);

}
