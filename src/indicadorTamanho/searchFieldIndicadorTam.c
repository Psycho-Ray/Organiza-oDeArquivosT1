#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

#include <printTamanho.h>
#include <utils.h>
#include <searchFieldMain.h>


void searchFieldIndicadorTam(FILE *fp) {
	t_search search;
	bool found = false;	
	int regSize, current_pos;
	int state_size, dateTimeOri_size, dateTimeUpd_size, ticket, i; 
	char *domain, *document_number, *name, *city, *state, *dateTimeOri, *dateTimeUpd;
	
	search = searchFieldMain;
	
	// if the user has decided to abort
	if (search.fieldType == INVALID)
		return;
	
	fread(&regSize, sizeof(int), 1, fp);
	/* TODO upoe que guardamos 0 no final do arquivo quando chegamos ao fim dos registros.
		falar com o Gabriel Cruz sobre como ele implementou. */
	while(regSize != 0) {
	
		/* TODO: Essa não é a versão mais otimizado que poderia ser feito.
			Se estou procurando por um domínio específico (primeiro campo), tecnicamente não precisao alocar os outros 7 
			se estiver errado aquele domínio, apenas ler o tamanho do campo e dar fseek.
			Mas isso envolveria implementar 8 ifs diferente, muuuitos iguais....
			Posso deixar assim e mencionar isso no relatório? 
		*/
		
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
		
		if( (search.fieldType == DOMAIN && strcmp(domain, search.query)) ||
			(search.fieldType == DOCUMENT && strcmp(document, search.query)) ||
			(search.fieldType == NAME && strcmp(name, search.query)) ||
			(search.fieldType == CITY && strcmp(city, search.query)) ||
			(search.fieldType == STATE && strcmp(state, search.query)) ||
			(search.fieldType == DATE_CREATED && strcmp(dateTimeOri, search.query)) ||
			(search.fieldType == DATE_UPDATED && strcmp(dateTimeUpd, search.query)) ||
			(search.fieldType == TICKET && ticket == atoi(search.query))
		  ) {
				printRegister(domain, document, name, city, state, dateTimeOri, dateTimeUpd, ticket);
				found = true;
		}
		fread(&regSize, sizeof(int), 1, fp);
		
	}
	if(!found)
	printf("Campo não encontrado em nenhum registro do arquivo.\n");
	printf("Retornando ao menu\n");
}
