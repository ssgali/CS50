#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int main(void)
{
    int letters = 0, i = 0, sentences = 0, m = 0, n = 0, words = 0, index;
    float L, S;
    string para = get_string("Text : ");
    n = strlen(para);
    for (i = 0 ; n > i ; i++)
    {
        char p = para[i];//Checking for letters
        if (isalpha(p))
        {
            letters += 1;
        }
        if (isspace(p) && !isspace(para[i - 1]))//check for words
        {
            words++;
        }
        if (para[i] == '.' || para[i] == '?' || para[i] == '!')//check for sentences
        {
            sentences++;
        }
    }

    words = words + 1;
    S = (sentences / (float) words) * 100;
    L = (letters / (float) words) * 100;
    index = round(0.0588 * L - 0.296 * S - 15.8); // comparing and applying the formula 

    if (index < 1) //finding the grade
    
    {
        printf("Before Grade 1\n");
        
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
        
    }
    else
    {
        printf("Grade %d\n", index);//the answer
    }

}