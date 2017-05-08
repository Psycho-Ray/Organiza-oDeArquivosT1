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

            // writes the string
            fwrite(field.data[i], sizeof(char), field.dataSize[i], output); 

            // if we need to fill with zeroes (for fixed-size fields)
            if(i == 1 || i == 5 || i == 6 || i == 7) 
                fwrite(zeroe, sizeof(char), SIZE_FIXED - (field.dataSize[i]), output);
        }
        freeRecord(field);
    }

    freeRecord(field);

    return output;
}

