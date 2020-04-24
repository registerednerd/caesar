#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool isNumeric(string);
char cipherChar(char, int);


int main(int argc, string argv[])
{
    if (argc != 2 || !isNumeric(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext:");
    int length = strlen(plaintext);
    printf("ciphertext: ");
    for (int i = 0; i < length; i++)
    {
        printf("%c", cipherChar(plaintext[i], key));
    }
    printf("\n");
}


bool isNumeric(string subject)
{
    int length = strlen(subject);
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(subject[i]))
        {
            return false;
        }
    }
    return true;
}


char cipherChar(char plainchar, int key)
{
    int letter = plainchar;
    int cipherchar;
    if (letter >= 65 && letter <= 90)
    {
        letter = letter + key;
        while (letter > 90)
        {
            letter -= 26;
        }
    }
    else if (letter >= 97 && letter <= 122)
    {
        letter = letter + key;
        while (letter > 122)
        {
            letter -= 26;
        }
    }

    return (char) letter;
}
