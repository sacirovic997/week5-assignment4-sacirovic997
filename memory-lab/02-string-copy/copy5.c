// Capitalizes a copy of a string — the SAFE way
//
// This is the production-quality version:
//   - Check if get_string returned NULL
//   - Check if malloc returned NULL
//   - Use strcpy instead of a manual loop
//   - Check length before capitalizing
//   - Free allocated memory when done

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Get a string
    char *s = get_string("s: ");

    // Check if s is NULL and return 1 if so
    if (s == NULL)
    {
        return 1;
    }

    // Allocate memory for t
    char *t = malloc(strlen(s) + 1);

    // Check if t is NULL and return 1 if so
    if (t == NULL)
    {
        return 1;
    }

    // Copy s into t using strcpy
    strcpy(t, s);

    // Capitalize t[0] only if the string is not empty
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // Print both strings
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // Free the memory you allocated
    free(t);

    return 0;
}
