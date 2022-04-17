#include "recdes.h"

int main ()
{
    FILE* task = fopen ("task.txt", "r");
    char* buffer = TakeTask (task);
    fclose (task);

    int answer;
    bool incorrect = GetG (buffer, &answer);

    //printf ("%s", buffer);

    if (incorrect)
    {
        printf ("lexical error!\n");
    }
    else
    {
        printf ("answer is %d\n", answer);
    }

    free (buffer);

    return 0;
}