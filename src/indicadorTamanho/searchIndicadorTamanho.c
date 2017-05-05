#include <stdlib.h>
#include <stdio.h>

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


void indicadorTamanho_printDataBase(FILE *fp, int n) {
	int register_size, domain_size, document_number_size, name_size, city_size;
	int state_size, dateTimeOri_size, dateTimeUpd_size, ticket, i; 
	char *domain, *document_number, *name, *city, *state, *dateTimeOri;
	char *dateTimeUpd;

	for (i = 0; i < n; i++) {

		// Read's the size of register
		fread(&register_size, sizeof(int), 1, fp);

		// Read's the domain
		fread(&domain_size, sizeof(int), 1, fp);
		domain = (char *) malloc(sizeof(char) * (domain_size));
		fread(domain, sizeof(char), domain_size, fp);

		// Read's the document number
		fread(&document_number_size, sizeof(int), 1, fp);
		document_number = (char *) malloc(sizeof(char) * (document_number_size));
		fread(document_number, sizeof(char), document_number_size, fp);

		// Read's the name 
		fread(&name_size, sizeof(int), 1, fp);
		name = (char *) malloc(sizeof(char) * (name_size));
		fread(name, sizeof(char), name_size, fp);

		// Read's the city name
		fread(&city_size, sizeof(int), 1, fp);
		city = (char *) malloc(sizeof(char) * (city_size));
		fread(city, sizeof(char), city_size, fp);

		// Read's the state name
		fread(&state_size, sizeof(int), 1, fp);
		state = (char *) malloc(sizeof(char) * (state_size));
		fread(state, sizeof(char), state_size, fp);

		// Read's the date and time when the domain was created
		fread(&dateTimeOri_size, sizeof(int), 1, fp);
		dateTimeOri = (char *) malloc(sizeof(char) * (dateTimeOri_size));
		fread(dateTimeOri, sizeof(char), dateTimeOri_size, fp);

		// Read's the date and time of when the file was last modified
		fread(&dateTimeUpd_size, sizeof(int), 1, fp);
		dateTimeUpd = (char *) malloc(sizeof(char) * (dateTimeUpd_size));
		fread(dateTimeUpd, sizeof(char), dateTimeUpd_size, fp);

		// Read the ticket number
		fread(&ticket, sizeof(int), 1, fp);  // Indicates the size of a int
		fread(&ticket, sizeof(int), 1, fp);  // The number itself
 
		// Print the information
		printf("\t%d - %s\n", i, name);
		printf("\t\t\tDomain: \t%s\n", domain);
		printf("\t\t\tDocument Number: \t%s\n", document_number);
		printf("\t\t\tCity: \t%s\n", city);
		printf("\t\t\tState: \t%s\n", state);
		printf("\t\t\tDate and time created: \t%s\n", dateTimeOri);
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
	}

	// Make the file pointer return to the begging of the file
	rewind(fp);
}

void indicadorTamanho_printRecord(FILE *fp, int n, int offset) {
	int register_size, domain_size, document_number_size, name_size, city_size;
	int state_size, dateTimeOri_size, dateTimeUpd_size, ticket, i; 
	char *domain, *document_number, *name, *city, *state, *dateTimeOri;
	char *dateTimeUpd;

	// If the offset isn't valid, just return
	if (offset < 0 || offset >= n) {
		printf("Please, request a valid register number\n");
		return;
	}

	// Go to the offset requested
	for (i = 0; i < offset; i++) {
		fread(&register_size, sizeof(int), 1, fp);
		fseek(fp, register_size, SEEK_CUR);
	}

	// Read's the size of register
	fread(&register_size, sizeof(int), 1, fp);

	// Read's the domain
	fread(&domain_size, sizeof(int), 1, fp);
	domain = (char *) malloc(sizeof(char) * (domain_size));
	fread(domain, sizeof(char), domain_size, fp);

	// Read's the document number
	fread(&document_number_size, sizeof(int), 1, fp);
	document_number = (char *) malloc(sizeof(char) * (document_number_size));
	fread(document_number, sizeof(char), document_number_size, fp);

	// Read's the name 
	fread(&name_size, sizeof(int), 1, fp);
	name = (char *) malloc(sizeof(char) * (name_size));
	fread(name, sizeof(char), name_size, fp);

	// Read's the city name
	fread(&city_size, sizeof(int), 1, fp);
	city = (char *) malloc(sizeof(char) * (city_size));
	fread(city, sizeof(char), city_size, fp);

	// Read's the state name
	fread(&state_size, sizeof(int), 1, fp);
	state = (char *) malloc(sizeof(char) * (state_size));
	fread(state, sizeof(char), state_size, fp);

	// Read's the date and time when the domain was created
	fread(&dateTimeOri_size, sizeof(int), 1, fp);
	dateTimeOri = (char *) malloc(sizeof(char) * (dateTimeOri_size));
	fread(dateTimeOri, sizeof(char), dateTimeOri_size, fp);

	// Read's the date and time of when the file was last modified
	fread(&dateTimeUpd_size, sizeof(int), 1, fp);
	dateTimeUpd = (char *) malloc(sizeof(char) * (dateTimeUpd_size));
	fread(dateTimeUpd, sizeof(char), dateTimeUpd_size, fp);

	// Read the ticket number
	fread(&ticket, sizeof(int), 1, fp);  // Indicates the size of a int
	fread(&ticket, sizeof(int), 1, fp);  // The number itself

	// Print the information
	printf("\t%d - %s\n", i, name);
	printf("\t\t\tDomain: \t%s\n", domain);
	printf("\t\t\tDocument Number: \t%s\n", document_number);
	printf("\t\t\tCity: \t%s\n", city);
	printf("\t\t\tState: \t%s\n", state);
	printf("\t\t\tDate and time created: \t%s\n", dateTimeOri);
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