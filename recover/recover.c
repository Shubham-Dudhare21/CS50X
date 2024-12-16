#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define UNIT_SIZE 512

bool new_jpg(uint8_t *buffer);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("ENTER SINGLE ARGUMENT!\n");
        return 1;
    }

    FILE *infile = fopen(argv[1], "r");
    FILE *outfile = NULL;
    char filename[8];

    if (infile == NULL)
    {
        printf("INPUT FILE DOES NOT EXIST!\n");
        return 1;
    }
    int name_counter = 0;
    uint8_t buffer[UNIT_SIZE];

    while (fread(&buffer, UNIT_SIZE, 1, infile))
    {
        if (new_jpg(buffer))
        {
            if (name_counter != 0)
            {
                fclose(outfile);
            }
            sprintf(filename, "%03i.jpg", name_counter);
            outfile = fopen(filename, "w");
            fwrite(&buffer, UNIT_SIZE, 1, outfile);
            name_counter++;
        }
        else if (name_counter != 0)
        {
            fwrite(&buffer, UNIT_SIZE, 1, outfile);
        }
    }
    fclose(outfile);
    fclose(infile);
    return 0;
}

bool new_jpg(uint8_t *buffer)
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    return false;
}
