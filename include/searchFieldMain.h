#ifndef _SEARCHFIELDMAIN_H_
#define _SEARCHFIELDMAIN_H_

#include <stdbool.h>

typedef struct {
	char *query;
	int fieldType;
} t_searchField;

t_searchField searchFieldMain();

bool searchFound(t_searchField search, t_field field);

char continueSearch();

#endif
