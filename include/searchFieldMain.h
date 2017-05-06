#ifndef _SEARCHFIELDMAIN_H_
#define _SEARCHFIELDMAIN_H_

typedef struct {
	char *query;
	int fieldType;
} t_searchField;

t_searchField searchMain();

#endif
