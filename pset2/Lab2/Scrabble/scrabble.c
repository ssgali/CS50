#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    // Score both words
    int score1 = compute_score(word1); // function starting
    int score2 = compute_score(word2); //function starting
    // TODO: Print the winner

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");    //Player 1 Wins
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");    //Player 2 Wins
    }

    if (score2 == score1)
    {
        printf("Tie!\n");              //Scores is Equal
    }

}

int compute_score(string word)
{
    int sum1 = 0; // intiallizing with zero because it may cause error while calculating 2nd scoreS
    // TODO: Compute and return score for string
    for (int i = 0, n = strlen(word) ; i < n ; i++)    // loop to find the Length of string
    {
        char ch = word[i]; //assigning the alphabet to ch
        //This will Add the POINTS of the Word
        if (islower(ch) || isupper(ch))    //simple functions
        {

            for (int j = 0 ; j < n; j++) //loop to find the score of the word
            {
                if (ch == 'a' || ch == 'A') // using break because to repeat the process not continue
                {
                    sum1 = sum1 + 1;
                    break;
                }
                if (ch == 'b' || ch == 'B') // checking if ch meets the required alphabet
                {
                    sum1 = sum1 + 3;
                    break;
                }
                if (ch == 'c' || ch == 'C')
                {
                    sum1 = sum1 + 3;
                    break;
                }
                if (ch == 'd' || ch == 'D')
                {
                    sum1 = sum1 + 2;
                    break;
                }
                if (ch == 'e' || ch == 'E')
                {
                    sum1 = sum1 + 1;
                    break;
                }

                if (ch == 'f' || ch == 'F')
                {
                    sum1 = sum1 + 4;
                    break;
                }

                if (ch == 'g' || ch == 'G')
                {
                    sum1 = sum1 + 2;
                    break;
                }

                if (ch == 'h' || ch == 'H')
                {
                    sum1 = sum1 + 4;
                    break;
                }

                if (ch == 'i' || ch == 'I')
                {
                    sum1 = sum1 + 1;
                    break;
                }

                if (ch == 'j' || ch == 'J')
                {
                    sum1 = sum1 + 8;
                    break;
                }

                if (ch == 'k' || ch == 'K')
                {
                    sum1 = sum1 + 5;
                    break;
                }

                if (ch == 'l' || ch == 'L')
                {
                    sum1 = sum1 + 1;
                    break;
                }

                if (ch == 'm' || ch == 'M')
                {
                    sum1 = sum1 + 3;
                    break;
                }

                if (ch == 'n' || ch == 'N')
                {
                    sum1 = sum1 + 1;
                    break;
                }

                if (ch == 'o' || ch == 'O')
                {
                    sum1 = sum1 + 1;
                    break;
                }

                if (ch == 'p' || ch == 'P')
                {
                    sum1 = sum1 + 3;
                    break;
                }

                if (ch == 'q' || ch == 'Q')
                {
                    sum1 = sum1 + 10;
                    break;
                }

                if (ch == 'r' || ch == 'R')
                {
                    sum1 = sum1 + 1;
                    break;
                }

                if (ch == 's' || ch == 'S')
                {
                    sum1 = sum1 + 1;
                    break;
                }

                if (ch == 't' || ch == 'T')
                {
                    sum1 = sum1 + 1;
                    break;
                }

                if (ch == 'u' || ch == 'U')
                {
                    sum1 = sum1 + 1;
                    break;
                }

                if (ch == 'v' || ch == 'V')
                {
                    sum1 = sum1 + 4;
                    break;
                }

                if (ch == 'w' || ch == 'W')
                {
                    sum1 = sum1 + 4;
                    break;
                }

                if (ch == 'x' || ch == 'X')
                {
                    sum1 = sum1 + 8;
                    break;
                }

                if (ch == 'y' || ch == 'Y')
                {

                    sum1 = sum1 + 4;
                    break;
                }

                if (ch == 'z' || ch == 'Z')
                {
                    sum1 = sum1 + 10;
                    break;
                }

            }
        }

    }
    //Returning The value
    return sum1;
}