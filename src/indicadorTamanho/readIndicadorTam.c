#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <utils.h>

/*
	1 dominio 			string
	2 documento 		string // fixed
	3 nome 				string
	4 cidade			string
	5 uf 				string
	6 dataHora 			string // fixed
	7 dataHoraAtuli 	string // fixed
	8 ticket 			string // fixed

*/


t_field readFieldindicadorTamanho(FILE *fp) {
	int domain_size, name_size, city_size, state_size;
	t_field field;

	// Read's the domain
	fread(&domain_size, sizeof(int), 1, fp);
	field.domain = (char *) malloc(sizeof(char) * (domain_size));
	fread(field.domain, sizeof(char), domain_size, fp);
	
	// Read's the document number
	field.document_number = (char *) malloc(sizeof(char) * (SIZE_FIXED));
	fread(field.document_number, sizeof(char), SIZE_FIXED, fp);

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
	field.dateTimeOri = (char *) malloc(sizeof(char) * (SIZE_FIXED));
	fread(field.dateTimeOri, sizeof(char), SIZE_FIXED, fp);

	// Read's the date and time of when the file was last modified
	field.dateTimeUpd = (char *) malloc(sizeof(char) * (SIZE_FIXED));
	fread(field.dateTimeUpd, sizeof(char), SIZE_FIXED, fp);

	// Read the ticket number
	field.ticket = (char *) malloc(sizeof(char) * (SIZE_FIXED));
	fread(&field.ticket, SIZE_FIXED, 1, fp);  // Indicates the size of a int
	
	return field;
}


int calculateRecordSize(t_field field) {
    int regSize = 0, i;

    for(i = 0; i < 8; i++) {
        if(i == 2 || i == 3 || i == 4 || i == 0) // if variable-sized field
            regSize += field.dataSize[i];
        else
            regSize += SIZE_FIXED;
    }

    return regSize;
}


FILE *size_readDataBase(FILE *input, int *nregs, int *nfields) {
    FILE *output = fopen("answer.dat", "wb");
    char zeroe[30] = "000000000000000000000000000000";
    int i, regSize = 0;
    t_field field;
    *nfields = 8;


    for(*nregs = 0; !feof(input); (*nregs)++) {
        field = readRecord(input);
        if(feof(input)) break;

        // Calculate and write the size of the record (including string termiantors '\0')
        regSize = calculateRecordSize(field);
        fwrite(&regSize, sizeof(int), 1, output);

        // Write record
        for(i = 0; i < (*nfields); i++) {
            if(i == 2 || i == 3 || i == 4 || i == 0) // if variable-sized field
                fwrite(&field.dataSize[i], sizeof(int), 1, output);

            fwrite(field.data[i], sizeof(char), field.dataSize[i], output); // writes the string

            if(i == 1 || i == 5 || i == 6 || i == 7) // if we need to fill with zeroes (for fixed-size fields)
                fwrite(zeroe, sizeof(char), SIZE_FIXED - (field.dataSize[i]), output);
        }
        freeRecord(field);
    }

    freeRecord(field);

    return output;
}

