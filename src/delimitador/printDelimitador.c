#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
	
	1 dominio 			string
	2 documento 		string
	3 nome 				string
	4 cidade			string
	5 uf 				string
	6 dataHora 			string
	7 dataHoraAtuli 	string
	8 ticket 			int 

*/

void delimiter_printDataBase(FILE *fp, int n) {


	rewind(fp);
}


void delimiter_printRecord(FILE *fp, int n, int offset) {
	char *domain = NULL, *document_number = NULL, *name = NULL, *city = NULL;
	char *state = NULL, *dateTimeOri = NULL, *dateTimeUpd = NULL;
	int ticket, leng = 0, field = 1, record_counter = 0;
	char aux;

	// If the offset isn't valid, just return
	if (offset < 0 || offset >= n) {
		printf("Please, request a valid record number\n");
		return;
	}

	while(record_counter != offset) {
		// Read each byte looking for record delimeters 
		fread(&aux, sizeof(char), 1, fp);

		// If it's a record delimeter, we are in the next record
		if (aux == '#') record_counter++;  
	}


	while(!feof(fp)) {
		fread(&aux, sizeof(char), 1, fp);
		if(!feof(fp)) {
			// If the record is over, break
			if (aux == '#') break;
			// If it's a field delimiter, update de field
			if (aux == ';') {
				field++;
				leng = 0;
				continue;
			}
			// If it's in the first field. Read the domain
			if (field == 1) {
				domain = (char *) realloc(domain, sizeof(char) * (leng + 1));
				domain[leng++] = aux;
			}
			if (field == 2) {
				document_number = (char *) realloc(document_number, 
					sizeof(char) * (leng+1));
				document_number[leng++] = aux;
			}
			if (field == 3) {
				name = (char *) realloc(name, sizeof(char) * (leng + 1));
				name[leng++] = aux;
			}	
			if (field == 4) {
				city = (char *) realloc(city, sizeof(char) * (leng + 1));
				city[leng++] = aux;
			}
			if (field == 5) {
				state = (char *) realloc(state, sizeof(char) * (leng + 1));
				state[leng++] = aux;
			}
			if (field == 6) {
				dateTimeOri = (char *) realloc(dateTimeOri, 
					sizeof(char) * (leng + 1));
				dateTimeOri[leng++] = aux;
			}
			if (field == 7) {
				dateTimeUpd = (char *) realloc(dateTimeUpd, 
					sizeof(char) * (leng + 1));
				dateTimeUpd[leng++] = aux;
			}
			if (field == 8) {
				fseek(fp, -1, SEEK_CUR);
				fread(&ticket, sizeof(int), 1, fp);
			}
		}
	}

	// Print the information
	if (strcmp(name, "null")) 
		printf("\t%d - %s\n", offset, name);
	if (strcmp(domain, "null")) 
		printf("\t\t\tDomain: \t%s\n", domain);
	if (strcmp(document_number, "null")) 
		printf("\t\t\tDocument Number: \t%s\n", document_number);
	if (strcmp(city, "null")) 
		printf("\t\t\tCity: \t%s\n", city);
	if (strcmp(state, "null")) 
		printf("\t\t\tState: \t%s\n", state);
	if (strcmp(dateTimeOri, "null")) 
		printf("\t\t\tDate and time created: \t%s\n", dateTimeOri);
	if (strcmp(dateTimeUpd, "null")) 
		printf("\t\t\tDate and time last updated: \t%s\n", dateTimeUpd);
	printf("\t\t\tTicket number: \t%d\n", ticket);

	// Free the strings
	free(name);
	free(domain);
	free(document_number);
	free(city);
	free(state);
	free(dateTimeOri);
	free(dateTimeUpd);

	// Make the file pointer return to the begging of the file
	rewind(fp);
}