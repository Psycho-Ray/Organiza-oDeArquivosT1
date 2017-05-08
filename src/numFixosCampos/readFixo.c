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

FILE *fixed_readDataBase(FILE *input, int *nregs, int *nfields) {
    FILE *output = fopen("answer.dat", "wb+");
    char zeroe[30] = "000000000000000000000000000000";
    int i;
    t_field field;
    *nfields = 8;


    for(*nregs = 0; !feof(input); (*nregs)++) {
        field = readRecord(input);
        if(feof(input)) break;

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

	rewind(output);

    return output;
}
