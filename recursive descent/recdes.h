#ifndef RECDES_H_INCLUDED
#define RECDES_H_INCLUDED

#include <iostream>
#include <sys\stat.h>

enum LexicalCheck
{
    CORRECT   = 0, 
    INCORRECT = 1
};

char*           TakeTask            (FILE* task);

int             GetG                (const char* buf, int* answer);

int             GetE                (const char* buf, uint32_t* pos);

int             GetT                (const char* buf, uint32_t* pos);

int             GetP                (const char* buf, uint32_t* pos);

int             GetN                (const char* buf, uint32_t* pos);

#endif