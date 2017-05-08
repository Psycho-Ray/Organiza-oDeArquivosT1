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
    string = (char *) malloc(50 * sizeof(char));
    letra = fgetc(stream);


    while (letra != separador && letra != fim_linha && letra != EOF) { 
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

    for(i = 0; i < 8; i++) {
        string = readLine(input, ';', '\n');
        field.data[i] = string;
        field.dataSize[i] = strlen(string) + 1; // strlen(string) + \0
    }

    return field;
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
