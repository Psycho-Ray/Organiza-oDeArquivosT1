#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <utils.h>

/*Pula caracteres do arquivo até encontrar "delim" n vezes*/
int delimiter_fast_foward(FILE *file, int n, char delim) {
    int counter = 0;
    char aux;

    //Pula n registros
    while (counter++ < n) {
        //Inicializa com um caracter qualquer diferente de "delim"
        aux = delim + 1;

        //Procura "delim"
        while (!feof(file) && aux != delim)
            fread(&aux, sizeof(char), 1, file);
    }

    //Retorna sucesso (0) ou erro (1)
    return feof(file);
}

/*Pula "size" bytes n vezes*/
int sizeMark_fast_foward(FILE *file, int n) {
    int i, size;

    //Pula n registros
    for (i=0; i<n; i++) {
        if (!feof(file)) {
            //Pula "size" bytes
            fread(&size, sizeof(int), 1, file);
            fseek(file, size, SEEK_CUR);
        }
    }

    return feof(file);
}

/*Pula n registros*/
void jump_to_field(FILE *file, int n) {
    int i, size;

    //Pula n campos
    for (i=0; i<n; i++) {
        //Caso campos de tamanho fixo
        if (i == 0 || i == 2 || i == 3 || i == 4) {
            fread(&size, sizeof(int), 1, file);
            fseek(file, size, SEEK_CUR);
        }
        //Caso campos de tamanho variável
        else fseek(file, SIZE_FIXED, SEEK_CUR);
    }
}

/*Percorre nFields (nesse caso, 8) campos n vezes*/
int all_fields_fast_foward(FILE *file, int n, int nFields) {
    //Pula n registros
    while (n-- > 0)
        if (!feof(file))
            //Pula nFields campos (nesse caso 8)
            jump_to_field(file, nFields);

    return feof(file);
}

int jump_to_register(FILE *file, int type, int offset) {
    switch(type) {
        case (DELIMITER):
            if (!delimiter_fast_foward(file, offset, '#')) {
                //Caso "eof" encontrado antes do registro
                printf("Registro nao encontrado\n");
                return -1;
            }
            break;

        case (SIZE_INDICATOR):
            if (!sizeMark_fast_foward(file, offset)) {
                //Caso "eof" encontrado antes do registro
                printf("Registro nao encontrado\n");
                return -1;
            }
            break;

        case (FIXED_FIELDS):
            if (!all_fields_fast_foward(file, offset, 8)) {
                //Caso "eof" encontrado antes do registro
                printf("Registro nao encontrado\n");
                return -1;
            }
            break;
    }

    return feof(file);
}

/*Imprime o conteúdo do campo "field_offset" do registro "reg_offset"*/
//Importante: Essa função enumera os campos à partir de 0
void print_selected(FILE *file, int reg_type, int reg_offset, int field_offset) {
    //Garante que percorrerá todo o arquivo
    rewind(file);

    //Caso offset inválido
    if (reg_offset < 0 || field_offset < 0 || field_offset > 7) {
        printf("Numero de campo e/ou registro invalido\n");
        return;
    }

    //Pula para o registro "reg_offset"
    if (!jump_to_register(file, reg_type, reg_offset)) {
        //Caso "eof" encontrado antes do registro
        printf("Registro não encontrado\n");
        return;
    }

    //Pula para o campo "field_offset"
    jump_to_field(file, field_offset);

    //Lê e imprime o campo
    char *result = readLine(file, ';', '\n');
    printf("%s\n", result);
    free(result);

    rewind(file);
    return;
}
