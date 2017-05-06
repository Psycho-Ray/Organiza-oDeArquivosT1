#ifndef _UTILS_H_
#define _UTILS_H_

#define OPTION int
#define TYPE_REG int
#define FIELD int

// Size of the fields that hava a fixed length, as chars
#define SIZE_DOCUMENT 19
#define SIZE_TIME 19
#define SIZE_TICKET 4


enum {
	INVALID,
	DOMAIN,
	DOCUMENT,
	NAME,
	CITY,
	STATE,
	DATE_CREATED,
	DATE_UPDATED,
	TICKET
};


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
