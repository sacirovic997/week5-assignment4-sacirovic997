// Homework – Memory Logger
// Name: Sacirovic
// Date: 30.04.2026
//
// Read the README.md in this folder before starting!

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_WORDS 5

int main(void)
{
    // Declare an array of NUM_WORDS char* pointers
    char *words[NUM_WORDS];

    // -------------------------------------------------------
    // STEP 1 & 2: Read words and store copies in memory
    // -------------------------------------------------------
    for (int i = 0; i < NUM_WORDS; i++)
    {
        char *input = get_string("Enter word %i: ", i + 1);

        // Allocate memory for a copy of input (+1 for '\0')
        words[i] = malloc(strlen(input) + 1);

        // Check if malloc returned NULL
        if (words[i] == NULL)
        {
            printf("Memory error!\n");
            return 1;
        }

        // Copy input into words[i]
        strcpy(words[i], input);

        // Capitalize the first letter of words[i]
        if (strlen(words[i]) > 0)
        {
            words[i][0] = toupper(words[i][0]);
        }
    }

    // -------------------------------------------------------
    // STEP 3: Save all words to log.txt
    // -------------------------------------------------------

    // Open "log.txt" in write mode
    FILE *file = fopen("log.txt", "w");

    // Check if fopen returned NULL
    if (file == NULL)
    {
        printf("Could not open file!\n");
        return 1;
    }

    // Write each word to the file followed by "\n"
    for (int i = 0; i < NUM_WORDS; i++)
    {
        fprintf(file, "%s\n", words[i]);
    }

    // Close the file
    fclose(file);

    printf("\nWords saved to log.txt!\n");


    // STEP 4: Free all allocated memory
    

    // Free each word
    for (int i = 0; i < NUM_WORDS; i++)
    {
        free(words[i]);
    }

    return 0;
}
