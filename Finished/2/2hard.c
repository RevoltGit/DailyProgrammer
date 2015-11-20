#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

	char *line = NULL;
	const char start[] = "start";
	const char stop[] = "stop";
	const char lap[] = "lap";
	int started = 0, finished = 0;

	time_t tstart,tlap,end;

	tstart = time(NULL);
	end = time(NULL);

	while ( finished == 0 ) { 

		scanf("%ms", &line);

		if ( strcmp(line, start) == 0 ) {
			clock_t tstart = clock(), diff;
			printf("Started\n"); started = 1;
		}

		else if ((( strcmp(line, stop) == 0 ) && ( started == 0 )) ||
			(( strcmp(line, lap) == 0 ) && ( started == 0 )))
			{ printf("Must start first!\n"); }

		else if (( strcmp(line, lap) == 0 ) && (started == 1)) {
		tlap = end;
		end = time(NULL);
		printf("Lap %f seconds.\n", difftime(end, tlap));
		}

		else if ( strcmp(line, stop) == 0 ) { 
			finished = 1;
			printf("Final runtime is %f\n", difftime(end, tstart));
		}

		else if ( started == 0 ) { printf("Must start first!\n"); }
		else { printf("Must either say 'stop' or 'lap'!\n"); }

	}

	free(line);


}
