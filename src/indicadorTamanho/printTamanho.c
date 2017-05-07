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
	t_field field;
	int i;

	for (i = 0; i < n; i++) {
//		field = readFieldindicadorTamanho(fp);

		// Print the information
		printf("\t%d - %s\n", i, field.name);
		printf("\t\t\tDomain: \t%s\n", field.domain);
		printf("\t\t\tDocument Number: \t%s\n", field.document_number);
		printf("\t\t\tCity: \t%s\n", field.city);
		printf("\t\t\tState: \t%s\n", field.state);
		printf("\t\t\tDate and time created: \t%s\n", field.dateTimeOri);
		printf("\t\t\tDate and time last updated: \t%s\n", field.dateTimeUpd);
		printf("\t\t\tTicket number: \t%d\n", field.ticket);

	//	freeFieldIndicadorTamanho(field);
	}

	// Make the file pointer return to the begging of the file
	rewind(fp);
}

void size_printRecord(FILE *fp, int n, int offset) {
	t_field field;
	int register_size, i;

	// If the offset isn't valid, just return
	if (offset < 0 || offset >= n) {
		printf("Please, request a valid register number\n");
		return;
	}

	// Go to the offset requested
	for (i = 0; i < offset; i++) {
		fread(&register_size, sizeof(int), 1, fp);

		// Se o contador do registro contar ele mesmo, deve ser register_size -4. 
		//  Ver com o Cruz depois como ele implementou 
		fseek(fp, register_size, SEEK_CUR);
	}

//	field = readFieldindicadorTamanho(fp); => JUST FOR NOT BREAKING THE CODE

	// Print the information
	printField(field.name, field.domain, field.document_number, field.city, field.state, 
				field.dateTimeOri, field.dateTimeUpd, offset, field.ticket);

	// frees the strings
//	freeFieldIndicadorTamanho(field);
	
	// Make the file pointer return to the begging of the file
	rewind(fp);
}
