#ifndef _PRINTFIXO_H_
#define _PRINTFIXO_H_

void fixed_printDataBase(RECORD_SIZE *size, FILE *fp, int n);
void fixed_printRecord(RECORD_SIZE *size, FILE *fp, int n, int offset);

#endif