#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>	// strcmp
#include <ctype.h> 	// isdigit

#include <utils.h>


// TODO: Simplificar a readLine, não precisa ter um seprador e um fim_linha.
// TODO: Traduzir para inglês.
char *readLine(FILE *stream, char separador, char fim_linha) {
    /* Le de um stream um input até encontrar o char separador,  fim_linha ou ser o fim do arq.
    Alocamos 50 bytes pra o input, e caso passe disso, incrementamos de 50 em 50 até ter toda a mensagem. 
    Depois, eliminamos bytes desnecessários */
    int i = 0, realloc_count = 0; //realloc_count guarda a qtd de reallocs ja feitos
    char letra, *string;
    char carriageReturn = '\r';
    string = (char *) malloc(50 * sizeof(char));
    letra = fgetc(stream);


    while (letra != separador && letra != fim_linha && letra != carriageReturn && letra != EOF) { 
        //leia até o usario pressionar separador, fim_lina ou ser o fim do arquivo
        string[i] = letra;
        i++;
        letra = fgetc(stream);
        if (i >= 50*(realloc_count +1)) { 
            //se houver mais chars do que o que já alocamos, realloc mais
            string = (char *) realloc(string, 50 * (realloc_count +2)*sizeof(char));
            realloc_count++;
        }
    } // i sai com o tamanho da string
    string = realloc(string, (i+1)*sizeof(char)); //elimina bytes desnecessários
    string[i] = '\0'; //adicionando um \0 no fim da string
    return string;
}


t_field readFields(FILE *fp) {
    int domain_size, name_size, city_size, state_size;
    t_field field;
    char c; 

    fread(&c, sizeof(char), 1, fp);

    if (!feof(fp)) {
        fseek(fp, -1, SEEK_CUR);

        // Reads the domain
        fread(&domain_size, sizeof(int), 1, fp);
        field.domain = (char *) malloc(sizeof(char) * (domain_size));
        fread(field.domain, sizeof(char), domain_size, fp);
        
        // Reads the document number
        field.document_number = (char *) malloc(sizeof(char) * (SIZE_FIXED));
        fread(field.document_number, sizeof(char), SIZE_FIXED, fp);

        // Reads the name 
        fread(&name_size, sizeof(int), 1, fp);
        field.name = (char *) malloc(sizeof(char) * (name_size));
        fread(field.name, sizeof(char), name_size, fp);

        // Reads the city name
        fread(&city_size, sizeof(int), 1, fp);
        field.city = (char *) malloc(sizeof(char) * (city_size));
        fread(field.city, sizeof(char), city_size, fp);

        // Reads the state name
        fread(&state_size, sizeof(int), 1, fp);
        field.state = (char *) malloc(sizeof(char) * (state_size));
        fread(field.state, sizeof(char), state_size, fp);

        // Reads the date and time when the domain was created
        field.dateTimeOri = (char *) malloc(sizeof(char) * (SIZE_FIXED));
        fread(field.dateTimeOri, sizeof(char), SIZE_FIXED, fp);

        // Reads the date and time of when the file was last modified
        field.dateTimeUpd = (char *) malloc(sizeof(char) * (SIZE_FIXED));
        fread(field.dateTimeUpd, sizeof(char), SIZE_FIXED, fp);

        // Read the ticket number
        field.ticket = (char *) malloc(sizeof(char) * (SIZE_FIXED));
        fread(&field.ticket, SIZE_FIXED, 1, fp);  // Indicates the size of a int   
        
    }
    
    return field;
}


void freeFields(t_field field) {
	free(field.domain);
	free(field.document_number);
	free(field.name);
	free(field.city);
	free(field.state);
	free(field.dateTimeOri);
	free(field.dateTimeUpd);
	free(field.ticket);
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



/* TODO: pode ser simplificada, receber um char **fields e iterar sobre ele, acredito que fique mais elegante // ltkills
	TODO CONTINUADO: Sei que não era bem isso que queria mas coloquei a struct field porque podemos querer imprimir com tabs diferentes
		Acho que assim fica mais fácil para entender também // Cenoura */
void printField(t_field field, int offset) {
				
	if (strcmp(field.name, "null")) 
		printf("\t%d - %s\n", offset, field.name);
	if (strcmp(field.domain, "null")) 
		printf("\t\t\tDomain: \t%s\n", field.domain);
	if (strcmp(field.document_number, "null")) 
		printf("\t\t\tDocument Number: \t%s\n", field.document_number);
	if (strcmp(field.city, "null")) 
		printf("\t\t\tCity: \t%s\n", field.city);
	if (strcmp(field.state, "null")) 
		printf("\t\t\tState: \t%s\n", field.state);
	if (strcmp(field.dateTimeOri, "null")) 
		printf("\t\t\tDate and time created: \t%s\n", field.dateTimeOri);
	if (strcmp(field.dateTimeUpd, "null")) 
		printf("\t\t\tDate and time last updated: \t%s\n", field.dateTimeUpd);
	if (strcmp(field.ticket, "null"))
		printf("\t\t\tTicket number: \t%s\n", field.ticket);
}


/*Loads the record into t_field struct*/
t_field readRecord(FILE *input) {
    char *string;
    int i;
    t_field field;
    field.data = malloc(sizeof(char *)*8);

	// TODO: Verificar para os campos de tamanho fixo se a string não é maior que o nosso limite (SIZE_FIXED)
    for(i = 0; i < 8; i++) {
        string = readLine(input, ';', '\n');
        field.data[i] = string;
        field.dataSize[i] = strlen(string) + 1; // strlen(string) + \0
    }
    
    // Reading extra \n
    string = readLine(input, '\n', '\n');
    free(string);

    return field;
}


void userContinue() {
	int count = 0;
	char c = 0;
	printf("Digite p para o próximo registro\n");
	while (c != 'p') {
		count++;
		c = getchar();
		if (count == 10) {
			printf("Você parece estar com dificuldade para pressionar enter.\n");
			printf("Continuando para o próximo registo\n");
			break;
		}
	}
}


void freeRecord(t_field field) {
    int i;
    for(i = 0; i < 8; i++) free(field.data[i]);
    free(field.data);
}

/*==========TEST AND DEBUGGING FUNCTIONS==========*/

void printRecord(t_field field) {
	int i;
    for(i = 0; i < 8; i++)
        printf("%s;", field.data[i]);
    printf("#\n");
}
