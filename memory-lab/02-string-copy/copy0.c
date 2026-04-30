// Capitalizes a string - the WRONG way
//
// Run this. Enter a lowercase word.
// Notice that BOTH s and t get capitalized, even though we only changed t.
//
// TODO: Write a comment below explaining WHY this happens:
// ANSWER: Because s and t point to the same memory address, so changing t[0] also changes s[0].

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get a string
    string s = get_string("s: ");

    // This does NOT copy the string!
    // It only copies the address - s and t now point to the same memory.
    string t = s;

    // Capitalize first letter of t
    t[0] = toupper(t[0]);

    // Print both - are they different?
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
