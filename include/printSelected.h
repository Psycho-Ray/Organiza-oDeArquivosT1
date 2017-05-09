#ifndef _PrintSelected_
#define _PrintSelected_

#include <stdlib.h>
#include <stdio.h>
#include <utils.h>

//Necessárias
void print_selected(FILE *file, int reg_type, int reg_offset, int field_offset);

//úteis
int jump_to_register(FILE *file, int type, int offset);

#endif //PrintSelected
