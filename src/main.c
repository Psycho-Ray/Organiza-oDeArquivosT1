
/*==========Integrantes==========*/
// Alex Sander Ribeiro da Silva 9779350
// Bruno Gomes Coelho 9791160
// Gabriel de Melo Cruz 9763043
// Marcello Pagano Silva 9791031

#include <stdlib.h>
#include <stdio.h>
#include <utils.h>

void printMenu() {
    printf("1 - Ler a partir do arquivo\n");
    printf("2 - Imprimir todos os dados\n");
    printf("3 - Procurar por campo\n");
    printf("4 - Procurar por número do registro\n");
    printf("5 - Procurar por números de registro e de campo\n");
    printf("6 - Sair\n");
}

FTYPE getFileType() {
    FTYPE a = NONE;
    // pede o tipo de arquivo
    return a;
}

void closeFiles() {
    // fcloses and frees
}

int main(int argc, char *argv[]) {
    OPTION op = NONE;
    TYPE_REG regType = NONE;
    //FTYPE ftype = getFileType();
    // FILE *fp = NULL;
    
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
				        printf("%s", placeholder);
				        break;
				    case PRINT_ALL:
				        // Precisa de um ponteiro para o arquivo de registros e a quantidade de registros
						// void indicadorTamanho_printDataBase(FILE *fp, int n);
				        printf("Done");
				        break;
				    case SEARCH_BY_RECORD:
						// Precisa de um ponteiro para o arquivo de registros, a quantidade de registros e qual se deseja procurar
						// void indicadorTamanho_printRecord(FILE *fp, int n, int offset);
				        printf("Done");
				        break;
				    case SEARCH_BY_FIELD:
					    printf("%s", placeholder);
				        break;
				    case SEARCH_BY_RECORD_BY_FIELD:
				    	printf("%s", placeholder);
				        break;
				    case EXIT:
				        closeFiles(); // fclose and frees
				        break;
				    default:
				        printf("Opcao Invalida\n");
				        break;
				}

			case DELIMITER:
				switch(op) {
				    case READ_FROM_FILE:
				        printf("%s", placeholder);
				        break;
				    case PRINT_ALL:
				        printf("%s", placeholder);
				        break;
				    case SEARCH_BY_FIELD:
				        printf("%s", placeholder);
				        break;
				    case SEARCH_BY_RECORD:
					    printf("%s", placeholder);
				        break;
				    case SEARCH_BY_RECORD_BY_FIELD:
				    	printf("%s", placeholder);
				        break;
				    case EXIT:
				        closeFiles(); // fclose and frees
				        break;
				    default:
				        printf("Opcao Invalida\n");
				        break;
				}
			
			case FIXED_FIELDS:
				switch(op) {
				    case READ_FROM_FILE:
				        printf("%s", placeholder);
				        break;
				    case PRINT_ALL:
				        printf("%s", placeholder);
				        break;
				    case SEARCH_BY_FIELD:
				        printf("%s", placeholder);
				        break;
				    case SEARCH_BY_RECORD:
					    printf("%s", placeholder);
				        break;
				    case SEARCH_BY_RECORD_BY_FIELD:
				    	printf("%s", placeholder);
				        break;
				    case EXIT:
				        closeFiles(); // fclose and frees
				        break;
				    default:
				        printf("Opcao Invalida\n");
				        break;
				}
		}
    }

    return 0;
}
