#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void fixed_printDataBase(RECORD_SIZE *size, FILE *fp, int n) {
	char *domain, *document_number, *name, *city, *state, *dateTimeOri;
	char *dateTimeUpd;

	// Make the file pointer return to the begging of the file
	rewind(fp);
}

void fixed_printRecord(RECORD_SIZE *size, FILE *fp, int n, int offset) {
	char *domain, *document_number, *name, *city, *state, *dateTimeOri;
	char *dateTimeUpd;

	// Make the file pointer return to the begging of the file
	rewind(fp);
}