#include <stdio.h>
#include <stdlib.h>

#include <readFieldIndicadorTam.h>

t_field readFieldindicadorTamanho(FILE *fp) {
	t_field field;
	int register_size, domain_size, document_number_size, name_size, city_size;
	int state_size, dateTimeOri_size, dateTimeUpd_size;

	// Read's the size of register
	fread(&register_size, sizeof(int), 1, fp);

	// Read's the domain
	fread(&domain_size, sizeof(int), 1, fp);
	field.domain = (char *) malloc(sizeof(char) * (domain_size));
	fread(field.domain, sizeof(char), domain_size, fp);

	// Read's the document number
	fread(&document_number_size, sizeof(int), 1, fp);
	field.document_number = (char *) malloc(sizeof(char) * (document_number_size));
	fread(field.document_number, sizeof(char), document_number_size, fp);

	// Read's the name 
	fread(&name_size, sizeof(int), 1, fp);
	field.name = (char *) malloc(sizeof(char) * (name_size));
	fread(field.name, sizeof(char), name_size, fp);

	// Read's the city name
	fread(&city_size, sizeof(int), 1, fp);
	field.city = (char *) malloc(sizeof(char) * (city_size));
	fread(field.city, sizeof(char), city_size, fp);

	// Read's the state name
	fread(&state_size, sizeof(int), 1, fp);
	field.state = (char *) malloc(sizeof(char) * (state_size));
	fread(field.state, sizeof(char), state_size, fp);

	// Read's the date and time when the domain was created
	fread(&dateTimeOri_size, sizeof(int), 1, fp);
	field.dateTimeOri = (char *) malloc(sizeof(char) * (dateTimeOri_size));
	fread(field.dateTimeOri, sizeof(char), dateTimeOri_size, fp);

	// Read's the date and time of when the file was last modified
	fread(&dateTimeUpd_size, sizeof(int), 1, fp);
	field.dateTimeUpd = (char *) malloc(sizeof(char) * (dateTimeUpd_size));
	fread(field.dateTimeUpd, sizeof(char), dateTimeUpd_size, fp);

	// Read the ticket number
	fread(&(field.ticket), sizeof(int), 1, fp);  // Indicates the size of a int
	fread(&(field.ticket), sizeof(int), 1, fp);  // The number itself

	return field;
}


void freeFieldIndicadorTamanho(t_field field) {
	// Frees the memory used to store the strings
	free(field.name);
	free(field.domain);
	free(field.document_number);
	free(field.city);
	free(field.state);
	free(field.dateTimeOri);
	free(field.dateTimeUpd);
}

