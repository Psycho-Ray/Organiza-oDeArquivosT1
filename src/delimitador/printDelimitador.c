#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <utils.h>


/*
	
	1 dominio 			string
	2 documento 		string
	3 nome 				string
	4 cidade			string
	5 uf 				string
	6 dataHora 			string
	7 dataHoraAtuli 	string
	8 ticket 			string

*/


void delimiter_printDataBase(FILE *fp, int n) {
	t_field aux;
	char delim;
	int i;

	for(i = 0; !feof(fp); i++){

		// Read the fields
		aux = readFields(fp);
		
		if (i == 0)
			printf("aqui: %s\n", aux.domain);
		
		fflush(stdout);
		printf("i eh %d\n", i);

		// Print them
		printField(aux, i);
		
		// Frees used memory
		freeFields(aux);

		// Read the delimiter
		fread(&delim, sizeof(int), 1, fp);
	}


	// Make the file pointer return to the begging of the file
	rewind(fp);
}


void delimiter_printRecord(FILE *fp, int n, int offset) {
	t_field aux;
	char delim;
	int i = 0; 

	// If the offset isn't valid, just return
	if (offset < 0 || offset >= n) {
		printf("Please, request a valid register number\n");
		return;
	}

	for (i = 0; i < offset; i++) {
		// Read the fields
		aux = readFields(fp);

		// Frees used memory
		freeFields(aux);
		
		// Read the delimiter
		fread(&delim, sizeof(int), 1, fp);
		
	}

	// Read the fields from the request offset
	aux = readFields(fp);

	// Print them
	printField(aux, i);

	// Frees used memory
	freeFields(aux);	

	// Make the file pointer return to the begging of the file
	rewind(fp);
} 
