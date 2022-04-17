#include "recdes.h"

char* TakeTask (FILE* task)
{
    struct stat size;
    fstat(fileno(task), &size);

    char* buffer = (char*) calloc(size.st_size + 2, sizeof(char));

    fread (buffer, size.st_size, sizeof(char), task);

    return buffer;
}

int GetG (const char* buf, int* answer)
{
    uint32_t pos = 0;

    *answer = GetE (buf, &pos);

    if (buf[pos] == '$')
    {
        return CORRECT;
    }
    else
    {
        return INCORRECT;
    }
}

#undef CUR_S
#define CUR_S buf[*pos]

int GetE (const char* buf, uint32_t* pos)
{
    int val = GetT (buf, pos);
    //printf ("%c", CUR_S);//db
    while (1)
    {
        if (CUR_S == '+')
        {
            *pos += 1;
            val += GetT (buf, pos);
            continue;
        }
        if (CUR_S == '-')
        {
            *pos += 1;
            val -= GetT (buf, pos);
            continue;
        }
        else
        {
            break;
        }
    }
    //printf ("cur val = %d\n", val);//db
    return val;
}

int GetT (const char* buf, uint32_t* pos)
{
    int val = GetP (buf, pos);
    //printf ("%c\n", CUR_S);//db
    while (1)
    {
        if (CUR_S == '*')
        {
            *pos += 1;
            val *= GetP (buf, pos);
            continue;
        }
        if (CUR_S == '/')
        {
            *pos += 1;
            val /= GetP (buf, pos);
            continue;
        }
        else
        {
            break;
        }
    }

    return val;
}

int GetP (const char* buf, uint32_t* pos)
{
    int val = 0;
    
    if (CUR_S == '(')
    {
        *pos += 1;
        val = GetE (buf, pos);

        if (CUR_S == ')')
        {
            *pos += 1;
            return val;
        }
        else 
        {
            printf ("lexical error in func %s with cur_s %c\n", __func__, CUR_S);
            return 0;
        }
    }
    else 
    {
        val = GetN (buf, pos);
        return val;
    }
}

int GetN (const char* buf, uint32_t* pos)
{
    uint32_t prev_pos = *pos;
    int val = 0;

    while ('0' <= CUR_S && CUR_S <= '9')
    {
        val += 10*val + (CUR_S - '0');
        *pos += 1;  
    }
    
    if (*pos - prev_pos)
    {
        return val;
    }
    else 
    {
        printf ("lexical error in func %s\n", __func__);
        return 0;
    }
}


#undef CUR_S