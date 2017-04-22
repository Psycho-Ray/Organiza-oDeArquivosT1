
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
    FTYPE a;
    // pede o tipo de arquivo
    return a;
}

void closeFiles() {
    // fcloses and frees
}

int main(int argc, char *argv[]) {
    OPTION op = NONE;
    FTYPE ftype = NONE;
    FILE *fp = NULL;

    ftype = getFileType();

    while(op != EXIT) {
        printMenu();
        scanf("%d", &op);

        switch(op) {
            case READ_FROM_FILE:
                break;
            case PRINT_ALL:
                break;
            case SEARCH_BY_FIELD:
                break;
            case SEARCH_BY_RECORD:
                break;
            case SEARCH_BY_RECORD_BY_FIELD:
                break;
            case EXIT:
                closeFiles(); // fclose and frees
                break;
            default:
                printf("Opcao Invalida\n");
                break;
        }
    }

    return 0;
}
