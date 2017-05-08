#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>	// strcmp, strlen

#include <utils.h>
#include <readTamanho.h>

#include <searchFieldMain.h>


void size_searchField(FILE *fp) {
	t_searchField search;
	t_field field;
	bool found = false;
	char c;
	int count;
	
	// Gets the field to be searched from the user
	search = searchFieldMain();
	
	// If the user has decided to abort at the end of the last function, we abort
	if (search.fieldType == INVALID || strlen(search.query) == 0) {
		free(search.query);
		return;
	}

	while (!feof(fp)) {
	    fread(&c, sizeof(char), 1, fp);
	    
	    if (!feof(fp)) {
	        fseek(fp, -1, SEEK_CUR);
		
			/* TODO: Essa não é a versão mais otimizado que poderia ser feito.
				Se estou procurando por um domínio específico (primeiro campo), tecnicamente não precisao alocar os outros 7 
				se estiver errado aquele domínio, apenas ler o tamanho do campo e dar fseek.
				Mas isso envolveria implementar 8 ifs diferente, muuuitos iguais....
				Posso deixar assim e mencionar isso no relatório? 
			*/
			// TODO: Supoe que guardamos o \0 na string

			// Reads a field
			field = readFields(fp);
		
			// Verifies if its the field the user is looking for, with the corrects contents
			if( searchFound(search, field)) {
				/* TODO: Modificar a impressão par ficar bonitinho, acho que o count não faz sentido */
				printField(field, ++count);
				found = true;
			}		
			
			// Frees used memory
			free(search.query);
		}
	}
	if(!found)
		printf("Campo não encontrado em nenhum registro do arquivo.\n");
	printf("Retornando ao menu\n");
}


