#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    int y = 1;
    int i = 1;
    int z = 0;
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *memorycard = fopen(argv[1], "r");
    if (memorycard == NULL)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    BYTE buffer [512];
    char filename [8];
    FILE *img = NULL;
    while (true)
    {
        size_t read_data_temp = fread(buffer, sizeof(BYTE), 512, memorycard);
        if (read_data_temp == 0)
        {
            break;
        }
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (z > 0)
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", z);
            img = fopen(filename, "w");
            fwrite(buffer, sizeof(BYTE), read_data_temp, img);
            z++;
        }
        else if (z > 0) // 
        {
            fwrite(buffer, sizeof(BYTE), read_data_temp, img);
        }
    }
    fclose(memorycard);
    return 0;
}