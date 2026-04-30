// Copies a file byte by byte
//
// This shows how files are just sequences of bytes in memory.
// We read one byte at a time from the source and write it to the destination.
// Usage: ./cp source destination

#include <stdio.h>

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./cp source destination\n");
        return 1;
    }

    // Open argv[1] for reading in binary mode
    FILE *src = fopen(argv[1], "rb");
    if (src == NULL)
    {
        printf("Could not open source file.\n");
        return 1;
    }

    // Open argv[2] for writing in binary mode
    FILE *dst = fopen(argv[2], "wb");
    if (dst == NULL)
    {
        printf("Could not open destination file.\n");
        fclose(src);
        return 1;
    }

    BYTE b;

    // Read one BYTE from src, write it to dst, until src is empty
    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    // Close both files
    fclose(src);
    fclose(dst);

    return 0;
}
