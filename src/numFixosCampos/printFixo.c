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

void fixed_printDataBase(FILE *fp, int n) {
	t_field aux; 
	int i; 

	// Read every record
	for (i = 0; i < n; i++) {

		// Read the fields
		aux = readFieldindicadorTamanho(fp);

		// Print them
		printField(aux, i);
	}

	// Make the file pointer return to the begging of the file
	rewind(fp);
}

void fixed_printRecord(FILE *fp, int n, int offset) {
	t_field aux;

	// If the offset isn't valid, just return
	if (offset < 0 || offset >= n) {
		printf("Please, request a valid register number\n");
		return;
	}

	// Go to the offset-th record
	fseek(fp, calculateRecordSize(aux) * offset, SEEK_SET);

	// Read the fields
	aux = readFieldindicadorTamanho(fp);

	// Print them
	printField(aux, offset);

	// Make the file pointer return to the begging of the file
	rewind(fp);
} 
