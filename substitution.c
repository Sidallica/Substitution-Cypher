#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char substitution(char alpha, string key);

int main(int argc, string argv[])
{
    //Checking for correct number of command line arguments
    if (argc == 2)
    {
        int length = strlen(argv[1]);
        //Checking if key is 26 in length
        if (length != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        //Checking if key is all alphabets
        for (int i = 0; i < length; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }

        string key = argv[1];
        //Checking if all characters are unique irrespective of case
        for (int i = 0; i < length; i++)
        {
            for (int k = 0; k < length; k++)
            {
                if (i == k)
                {
                    break;
                }
                else
                {
                    if (tolower(key[i]) == tolower(key[k]))
                    {
                        printf("Key must contain unique characters.\n");
                        return 1;
                    }
                }
            }
        }

        //Prompt user for text to be converted into cipher
        string plaintext = get_string("plaintext:  ");
        printf("ciphertext: ");

        //Algorithm for substitution cipher
        for (int i = 0; i < strlen(plaintext); i++)
        {
            printf("%c", substitution(plaintext[i], key));
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

//Function for substitution cipher
char substitution(char alpha, string key)
{
    //Handling upper case alphabets
    if (isupper(alpha))
    {
        int index = (int) alpha - 65;
        return toupper(key[index]);
    }
    //Handling lower case alphabets
    else if (islower(alpha))
    {
        int index = (int) alpha - 97;
        return tolower(key[index]);
    }
    //Handling punctuations etc.
    else
    {
        return alpha;
    }
}