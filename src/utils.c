#include <stdio.h>
#include <stdlib.h>
#include <utils.h>


// TODO: Simplificar a readLine, não precisa ter um seprados e um fim_linha.
// TODO: Traduzir para inglês.
char * readLine(FILE *stream, char separador, char fim_linha) {
    /* Le de um stream um input até encontrar o char separador,  fim_linha ou ser o fim do arq.
    Alocamos 50 bytes pra o input, e caso passe disso, incrementamos de 50 em 50 até ter toda a mensagem. 
    Depois, eliminamos bytes desnecessários */
    int i, realloc_count=0; //realloc_count guarda a qtd de reallocs ja feitos
    char letra, *string;
    string = (char *) malloc(50 * sizeof(char));
    letra = fgetc(stream);
    i=0;
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


