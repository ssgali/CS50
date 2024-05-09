#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int n, j, a, s, h;
    do
    {
        n = get_int("Height : ");
    }
    while (n < 1 || n > 8);
    for (j = 0; j < n; j++)
    {
        h = n; // h is for spaces
        h = h - j;
        for (a = 1; a < h ; a++) // intializing with 1 because 1 space is needed not two (0 ,1)
        {
            printf(" ");
        }
        for (s = 0; s <= j; s++)
        {
            printf("#");
        }
        printf("  "); // middle space
        for (s = 0; s <= j; s++)
        {
            printf("#");
        }
        printf("\n");
    }
}