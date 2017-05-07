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
	8 ticket 			int 

*/

void delimiter_printDataBase(FILE *fp, int n) {
	char *domain = NULL, *document_number = NULL, *name = NULL, *city = NULL;
	char *state = NULL, *dateTimeOri = NULL, *dateTimeUpd = NULL;
	int ticket, leng = 0, field = 1, record_counter = 0;
	char aux;

	// Read until end of file
	while(!feof(fp)) {
		fread(&aux, sizeof(char), 1, fp);
		if(!feof(fp)) {

			// If the record is over, print the information
			if (aux == '#') {
			printField(name, domain, document_number, city, state, dateTimeOri, dateTimeUpd, record_counter, ticket);

				// Free the strings
				free(name);
				free(domain);
				free(document_number);
				free(city);
				free(state);
				free(dateTimeOri);
				free(dateTimeUpd);

				// Set the pointers back to NULL
				name = domain = document_number = city = state = NULL;
				dateTimeOri = dateTimeUpd = NULL;

				record_counter++;
				continue;
			}

			// If it's a field delimiter, update the field
			if (aux == ';') {
				field++;
				leng = 0;
				continue;
			}

			// Read's the domain
			if (field == 1) {
				domain = (char *) realloc(domain, sizeof(char) * (leng + 1));
				domain[leng++] = aux;
			}

			// Read's the document number
			if (field == 2) {
				document_number = (char *) realloc(document_number, 
					sizeof(char) * (leng+1));
				document_number[leng++] = aux;
			}

			// Read's the name 
			if (field == 3) {
				name = (char *) realloc(name, sizeof(char) * (leng + 1));
				name[leng++] = aux;
			}	

			// Read's the city name
			if (field == 4) {
				city = (char *) realloc(city, sizeof(char) * (leng + 1));
				city[leng++] = aux;
			}

			// Read's the state name
			if (field == 5) {
				state = (char *) realloc(state, sizeof(char) * (leng + 1));
				state[leng++] = aux;
			}

			// Read's the date and time when the domain was created
			if (field == 6) {
				dateTimeOri = (char *) realloc(dateTimeOri, 
					sizeof(char) * (leng + 1));
				dateTimeOri[leng++] = aux;
			}

			// Read's the date and time of when the file was last modified
			if (field == 7) {
				dateTimeUpd = (char *) realloc(dateTimeUpd, 
					sizeof(char) * (leng + 1));
				dateTimeUpd[leng++] = aux;
			}

			// Read the ticket number
			if (field == 8) {
				// Already read a byte from the int, needs to go back one byte 
				fseek(fp, -1, SEEK_CUR);
				// Read the int
				fread(&ticket, sizeof(int), 1, fp);
			}
		}
	}

	// Make the file pointer return to the begging of the file
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

			// If it's a field delimiter, update the field
			if (aux == ';') {
				field++;
				leng = 0;
				continue;
			}
			
			// Read's the domain
			if (field == 1) {
				domain = (char *) realloc(domain, sizeof(char) * (leng + 1));
				domain[leng++] = aux;
			}

			// Read's the document number
			if (field == 2) {
				document_number = (char *) realloc(document_number, 
					sizeof(char) * (leng+1));
				document_number[leng++] = aux;
			}

			// Read's the name 
			if (field == 3) {
				name = (char *) realloc(name, sizeof(char) * (leng + 1));
				name[leng++] = aux;
			}	

			// Read's the city name
			if (field == 4) {
				city = (char *) realloc(city, sizeof(char) * (leng + 1));
				city[leng++] = aux;
			}

			// Read's the state name
			if (field == 5) {
				state = (char *) realloc(state, sizeof(char) * (leng + 1));
				state[leng++] = aux;
			}

			// Read's the date and time when the domain was created
			if (field == 6) {
				dateTimeOri = (char *) realloc(dateTimeOri, 
					sizeof(char) * (leng + 1));
				dateTimeOri[leng++] = aux;
			}

			// Read's the date and time of when the file was last modified
			if (field == 7) {
				dateTimeUpd = (char *) realloc(dateTimeUpd, 
					sizeof(char) * (leng + 1));
				dateTimeUpd[leng++] = aux;
			}

			// Read the ticket number
			if (field == 8) {
				// Already read a byte from the int, needs to go back one byte 
				fseek(fp, -1, SEEK_CUR);
				// Read the int
				fread(&ticket, sizeof(int), 1, fp);
			}
		}
	}

	// Print the information
	printField(name, domain, document_number, city, state, dateTimeOri, dateTimeUpd, offset, ticket);

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
