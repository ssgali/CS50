#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cs50.h>
#include<ctype.h>
#include<stdlib.h>
int main(int argc, string argv[])
{
    //getting the correct key
    int z = 0 ;
    int l = strlen(argv[argc - 1]);
    for (int i = 0 ; i <= l ; i++)
    {
        if ((isalpha(argv[argc - 1][i])))
        {
            z++;
        }
    }
    int number = atoi(argv[argc - 1]);
    int key = isdigit(number);
    char upper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char lower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    if (key == 0 && argc < 3 && z == 0)
    {
        //CIPHERING THE TEXT
        string plaintext = get_string("plaintext:  ");
        printf("ciphertext: ");
        l = 0;
        l = strlen(plaintext);
        for (int j = 0 ; j < l ; j++)               //printing the ciphertext
        {
            if (isalpha(plaintext[j]))
            {
                if (isupper(plaintext[j]))
                {
                    char I = plaintext[j];
                    I = I - 65;
                    int c = (I + number) % 26; //c = chiphercharacter for upper case characters
                    printf("%c", upper[c]);
                }
                if (islower(plaintext[j]))
                {
                    char s = plaintext[j];
                    s = s - 97;
                    int sc = (s + number) % 26;
                    printf("%c", lower[sc]);    //sc = ciphercharacter for small alphabets
                }
            }
            else
            {
                printf("%c", plaintext[j]);
            }

        }
        printf("\n");       //for moving the pointer to next line less prone to errors
    }
    if (!(key == 0 && argc < 3 && z == 0))      //if user enters anything other then digit
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}