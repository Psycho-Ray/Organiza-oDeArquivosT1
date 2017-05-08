#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>	// strcmp, strlen

#include <utils.h>
#include <searchFieldMain.h>


void readFieldIndicadorTam(FILE *fp)


void searchFieldIndicadorTam(FILE *fp) {
	t_searchField search;
	bool found = false;	
	int regSize, count = 0;
	int domain_size, document_number_size, name_size, city_size;
	int state_size, dateTimeOri_size, dateTimeUpd_size, ticket;
	char *domain, *document_number, *name, *city, *state, *dateTimeOri, *dateTimeUpd;
	
	search = searchFieldMain();
	
	// if the user has decided to abort
	if (search.fieldType == INVALID || strlen(search.query) == 0)
		return;

	while (!feof(fp)) {
	
		// read the size of the register
		fread(&regSize, sizeof(int), 1, fp);
		
		/* TODO: Essa não é a versão mais otimizado que poderia ser feito.
			Se estou procurando por um domínio específico (primeiro campo), tecnicamente não precisao alocar os outros 7 
			se estiver errado aquele domínio, apenas ler o tamanho do campo e dar fseek.
			Mas isso envolveria implementar 8 ifs diferente, muuuitos iguais....
			Posso deixar assim e mencionar isso no relatório? 
		*/
		// TODO: Supoe que guardamos o \0 na string

		// Read's the domain
		fread(&domain_size, sizeof(int), 1, fp);
		domain = (char *) malloc(sizeof(char) * (domain_size));
		fread(domain, sizeof(char), domain_size, fp);
		
		// Read's the document number
		document_number = (char *) malloc(sizeof(char) * (SIZE_DOCUMENT));
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
		dateTimeOri = (char *) malloc(sizeof(char) * (dateTimeOri_size));
		fread(dateTimeOri, sizeof(char), dateTimeOri_size, fp);

		// Read's the date and time of when the file was last modified
		dateTimeUpd = (char *) malloc(sizeof(char) * (dateTimeUpd_size));
		fread(dateTimeUpd, sizeof(char), dateTimeUpd_size, fp);


		// Read the ticket number
		fread(&ticket, sizeof(int), 1, fp);  // Indicates the size of a int
		fread(&ticket, sizeof(int), 1, fp);  // The number itself
		
		if( (search.fieldType == DOMAIN && strcmp(domain, search.query)) ||
			(search.fieldType == DOCUMENT && strcmp(document_number, search.query)) ||
			(search.fieldType == NAME && strcmp(name, search.query)) ||
			(search.fieldType == CITY && strcmp(city, search.query)) ||
			(search.fieldType == STATE && strcmp(state, search.query)) ||
			(search.fieldType == DATE_CREATED && strcmp(dateTimeOri, search.query)) ||
			(search.fieldType == DATE_UPDATED && strcmp(dateTimeUpd, search.query)) ||
			(search.fieldType == TICKET && ticket == atoi(search.query))
		  ) 
		{
			/* TODO: Modificar a impressão par ficar bonitinho */
			printField(name, domain, document_number, city, state, dateTimeOri, dateTimeUpd, ++count, ticket);
			found = true;
		}
		
	}
	if(!found)
		printf("Campo não encontrado em nenhum registro do arquivo.\n");
	printf("Retornando ao menu\n");
}

