// Stores and prints an integer via its address
// The * operator (dereference) lets you follow a pointer to get the value it points to.
// If p holds the address of n, then *p gives you the value of n.

#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;

    // Print the value of n by dereferencing p (use *p)
    printf("%i\n", *p);
}
