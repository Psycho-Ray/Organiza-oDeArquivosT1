#ifndef _READFIELDINDICADORTAM_H_
#define _READFIELDINDICADORTAM_H_


typedef struct {
	char *domain;
	char *document_number;
	char *name;
	char *city;
	char *state;
	char *dateTimeOri;
	char *dateTimeUpd;
	int ticket;
} t_field;

t_field readFieldindicadorTamanho(FILE *fp);
void freeFieldIndicadorTamanho(t_field field);

#endif
