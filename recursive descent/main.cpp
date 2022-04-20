#include "recdes.h"

int main ()
{
    FILE* task = fopen ("task.txt", "r");
    char* buffer = TakeTask (task);
    fclose (task);

    Tree aboba;
    Tree* tree = &aboba;
    TreeCtor (tree);
    
    bool incorrect = GetG (buffer, THEAD);

    //printf ("%s", buffer);

    if (incorrect)
    {
        printf ("lexical error!\n");
    }
    else
    {
        TreeDump (tree);
        printf ("all is ok\n");
    }

    TreeDtor (tree);

    free (buffer);

    return 0;
}