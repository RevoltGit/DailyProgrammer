#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Usage(char *filename) {
	printf("Usage: %s <database file>\n", filename);
}

char make_lower(char c){

	char somechar = c;
	int charval = somechar;
	
	if ( charval >= 95 && charval <= 127 ){}
 	else {
		 charval = charval + 32;
 		 char upperchar = charval;
 	}

	return charval;

}

int Search_in_File(char *fname, char *str) {
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char temp[512];

	if((fp = fopen(fname, "r")) == NULL) {
		return(-1);
	}

	while(fgets(temp, 512, fp) != NULL) {
		if((strstr(temp, str)) != NULL) {
			find_result++;
		}
		line_num++;
	}

	if(fp) {
		fclose(fp);
	}

   	return find_result;
}


int main(int argc, char *argv[]) {

	FILE *db;
	db = fopen(argv[1], "a");

	int result, i, len;
	char *name = NULL;
	char *firstname = NULL;
	char *lastname = NULL;
	char email[30] = {};
	const char *domain = "@dailypro.edu";

	if( argc != 2 ) {
		Usage(argv[0]);
		exit(1);
	}

	printf("Email Database\n");
	printf("New name?: ");
	scanf("%ms%ms", &firstname, &lastname);

	size_t length = strlen(firstname);
	firstname[length] = ' '; // overwrite null termination
	firstname[length+1] = '\0'; // add a new null termination
	strcat(firstname, lastname);
	name = firstname;

	email[0] = make_lower(name[0]);

	if ( strlen(lastname) < 7 ){ len = strlen(lastname); }
	else { len=7; }
	for (i = 0; i < len; i++){
		email[i+1] = make_lower(lastname[i]);
	}
	
	result = Search_in_File(argv[1], email);

	if (result > 0){
		sprintf(email, "%s%d", email, result+1);
		for (i = 0; i < strlen(domain); i++){
			email[i+len+2] = domain[i];
		}
	}
	else { 	for (i = 0; i < strlen(domain); i++){
			email[i+len+1] = domain[i];
		}
	}

	printf("Assigned Email: %s\n", email);
	fprintf(db, "%s - %s\n", name, email);

	return 0;

}

