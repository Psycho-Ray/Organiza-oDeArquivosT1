
/*==========Integrantes==========*/
// Alex Sander Ribeiro da Silva 9779350
// Bruno Gomes Coelho 9791160
// Gabriel de Melo Cruz 9763043
// Marcello Pagano Silva 9791031

#include <stdlib.h>
#include <stdio.h>

#include <utils.h>
#include <printFixo.h>
#include <printDelimitador.h>
#include <printTamanho.h>
#include <readFixo.h>
#include <readDelimitador.h>
#include <readTamanho.h>
#include <searchFieldIndicadorTam.h>

void printMenu() {
    printf("1 - Ler a partir do arquivo\n");
    printf("2 - Imprimir todos os dados\n");
    printf("3 - Procurar por campo\n");
    printf("4 - Procurar por número do registro\n");
    printf("5 - Procurar por números de registro e de campo\n");
    printf("6 - Sair\n");
}

void closeFiles(FILE *input, FILE *output) {
    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    OPTION op = NONE;
    TYPE_REG regType = NONE;
    FILE *input = fopen("Dominios.csv", "r+"), *output;
    int nregs, nfields; // offset = 0; variavel nao usado
    
    while (regType < 1 || regType > 3) {
        printf("Digite 1 para registros de tamanho variável com indicador de tamanho\n");
	    printf("Digite 2 para registros de tamanho variável com delimitadores entre registros\n");
	    printf("Digite 3 para registros de tamanho variável com número fixo de campos\n");
	    scanf("%d", &regType);
    }
    
	/////////////////////////////////////////////////////////// DEBUGGING ///////////////////////////////////////////////////////////  
	char placeholder[50] = "Função ainda não implementada.\n";
	///////////////////////////////////////////////////////////
   
    while(op != EXIT) {
        printMenu();
        scanf("%d", &op);
        
        switch(regType) {
        	case SIZE_INDICATOR:
				switch(op) {
				    case READ_FROM_FILE:
                        output = size_readDataBase(input, &nregs, &nfields);
				        break;
				    case PRINT_ALL:
				        // Precisa de um ponteiro para o arquivo de registros e a quantidade de registros
						// void size_printDataBase(FILE *fp, int n);
				        printf("Done");
				        break;
				    case SEARCH_BY_RECORD:
						// Precisa de um ponteiro para o arquivo de registros, a quantidade de registros e qual se deseja procurar
						// void size_printRecord(FILE *fp, int n, int offset);
				        printf("Done");
				        break;
				    case SEARCH_BY_FIELD:
					    printf("%s", placeholder);
				        break;
				    case SEARCH_BY_RECORD_BY_FIELD:
				    	printf("%s", placeholder);
				        break;
				    case EXIT:
				        //closeFiles(input, output); // fclose and frees
				        break;
				    default:
				        printf("Opcao Invalida\n");
				        break;
				}
                break;

			case DELIMITER:
				switch(op) {
				    case READ_FROM_FILE:
                        output = delimiter_readDataBase(input, &nregs, &nfields);
				        break;
				    case PRINT_ALL:
				    	// Precisa de um ponteiro para o arquivo de registros e a quantidade de registros 
				    	//delimiter_printDataBase(output, nregs); ainda nao implementado
				        printf("Done");
				        break;
				    case SEARCH_BY_RECORD:
				    	// Precisa de um ponteiro para o arquivo de registros, a quantidade de registros e qual se deseja procurar
						// delimiter_printRecord(output, nregs, offset); ainda nao implementado
				        printf("Done");
				        break;
				    case SEARCH_BY_FIELD:
					    printf("%s", placeholder);
				        break;
				    case SEARCH_BY_RECORD_BY_FIELD:
				    	printf("%s", placeholder);
				        break;
				    case EXIT:
				        //closeFiles(input, output); // fclose and frees
				        break;
				    default:
				        printf("Opcao Invalida\n");
				        break;
				}
                break;
			
			case FIXED_FIELDS:
				switch(op) {
				    case READ_FROM_FILE:
                        output = fixed_readDataBase(input, &nregs, &nfields);
				        break;
				    case PRINT_ALL:
				    	// Precisa de uma struct RECORD_SIZE com o tamanho de cada campo e o do registro nela
				    	// de um ponteiro para o arquivo de registros e a quantidade de registros
				    	// void fixed_printDataBase(RECORD_SIZE *size, FILE *fp, int n);
				        printf("Done");
				        break;
				    case SEARCH_BY_RECORD:
				    	// Precisa de uma struct RECORD_SIZE com o tamanho de cada campo e o do registro nela
				    	// de um ponteiro para o arquivo de registros, quantidade de registros e o offset
				    	// void fixed_printRecord(RECORD_SIZE *size, FILE *fp, int n, int offset);
				        printf("Done");
				        break;
				    case SEARCH_BY_FIELD:
				    	// precisa so do input :)
					    searchFieldIndicadorTam(input);
				        break;
				    case SEARCH_BY_RECORD_BY_FIELD:
				    	printf("%s", placeholder);
				        break;
				    case EXIT:
				        //closeFiles(input, output); // fclose and frees
				        break;
				    default:
				        printf("Opcao Invalida\n");
				        break;
				}
                break;
		}
    }
    closeFiles(input, output);
    return 0;
}
