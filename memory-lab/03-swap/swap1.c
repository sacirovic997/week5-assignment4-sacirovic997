// Swaps two integers using pointers
//
// Instead of passing values, we pass the ADDRESSES of x and y.
// The function can then follow those addresses and modify the real variables.

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);

    // Pass the addresses of x and y using &
    swap(&x, &y);

    printf("x is %i, y is %i\n", x, y);
}

// Swap using pointers
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
