/*create a program that will ask the users name, age, and reddit username. have it tell them the information back, in the format:
your name is (blank), you are (blank) years old, and your username is (blank)
for extra credit, have the program log this information in a file to be accessed later.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *fp;
	fp = fopen("Info.txt", "w+");

	char *name = NULL, *username = NULL;
	int age;

	printf("What is your name? ");
	scanf("%ms", &name);

	printf("How old are you? ");
	scanf("%d", &age);

	printf("What is your reddit username? ");
	scanf("%ms", &username);

	printf("your name is %s, you are %d years old, and your username is %s.\n", name, age, username);

	fprintf(fp, "Name: %s\nAge: %d\nReddit Username: %s", name, age, username); 

	fclose(fp);

}
