// Saves names and numbers to a CSV file, checking for NULL
//
// This is the safe version — always check that fopen succeeded
// before writing to the file.

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Open "phonebook.csv" in append mode
    FILE *file = fopen("phonebook.csv", "a");

    // Check if fopen returned NULL and return 1 if so
    if (file == NULL)
    {
        return 1;
    }

    // Get name and number from the user
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // Write name and number to the file as "name,number\n"
    fprintf(file, "%s,%s\n", name, number);

    // Close the file
    fclose(file);

    return 0;
}
