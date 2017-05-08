#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>	// strcmp, strlen

#include <utils.h>
#include <readTamanho.h>

#include <searchFieldMain.h>


void searchFieldIndicadorTam(FILE *fp) {
	t_searchField search;
	t_field field;
	bool found = false;	
	int regSize, count = 0;
	
	// Gets the field to be searched from the user
	search = searchFieldMain();
	
	// if the user has decided to abort at the end of the last function, we abort
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

		// reads a field
		field = readFieldindicadorTamanho(fp);
		
		// verifies if its the field the user is looking for, with the corrects contents
		if( (search.fieldType == DOMAIN && strcmp(field.domain, search.query)) ||
			(search.fieldType == DOCUMENT && strcmp(field.document_number, search.query)) ||
			(search.fieldType == NAME && strcmp(field.name, search.query)) ||
			(search.fieldType == CITY && strcmp(field.city, search.query)) ||
			(search.fieldType == STATE && strcmp(field.state, search.query)) ||
			(search.fieldType == DATE_CREATED && strcmp(field.dateTimeOri, search.query)) ||
			(search.fieldType == DATE_UPDATED && strcmp(field.dateTimeUpd, search.query)) ||
			(search.fieldType == TICKET && strcmp(field.ticket, search.query))
		  ) 
		{
			/* TODO: Modificar a impressão par ficar bonitinho, acho que o count não faz sentido */
			printField(field, ++count);
			found = true;
		}
		
	}
	if(!found)
		printf("Campo não encontrado em nenhum registro do arquivo.\n");
	printf("Retornando ao menu\n");
}


