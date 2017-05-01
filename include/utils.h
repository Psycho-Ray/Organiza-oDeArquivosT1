#ifndef _UTILS_H_
#define _UTILS_H_

#define OPTION int
#define TYPE_REG int

enum {
    NONE,
    READ_FROM_FILE,
    PRINT_ALL,
    SEARCH_BY_FIELD,
    SEARCH_BY_RECORD,
    SEARCH_BY_RECORD_BY_FIELD,
    EXIT
};


enum {
	SIZE_INDICATOR = 1,
	DELIMITER,
	FIXED_FIELDS
};


typedef enum {
	ALGO,
    // NONE,		com essa linha não compila, está redefinindo não do outro enum.
    // file organization types
} FTYPE;

#endif
