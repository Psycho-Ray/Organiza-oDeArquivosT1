#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <utils.h>
#include <readTamanho.h>

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

void size_printDataBase(FILE *fp, int n) {
	t_field aux; 
	int i, record_size; 

	// Read every record
	for (i = 0; i < n; i++) {
		fread(&record_size, sizeof(int), 1, fp);

		// Read the fields
		aux = readFields(fp);

		// Print them
		printField(aux, i);
		
		// Free the memory
		freeFields(aux);
		
		// Asks the user to press enter to continue
		userContinue();
	}

	// Make the file pointer return to the begging of the file
	rewind(fp);
}


void size_printRecord(FILE *fp, int n, int offset) {
	t_field aux;
	int record_size, i;

	// If the offset isn't valid, just return
	if (offset < 0 || offset >= n) {
		printf("Please, request a valid register number\n");
		return;
	}

	// Go to the offset requested
	for (i = 0; i < offset; i++) {
		// Read's the record's size
		fread(&record_size, sizeof(int), 1, fp);

		// Skip the record
		fseek(fp, record_size, SEEK_CUR);
	}

	// Read the fields
	aux = readFields(fp);

	// Print them
	printField(aux, i);
	
	// Frees used memory
	freeFields(aux);

	// Make the file pointer return to the begging of the file
	rewind(fp);
} 
