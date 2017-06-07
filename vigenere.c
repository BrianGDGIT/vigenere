#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    //Checking argument
    if (argc != 2)
    {
        printf("Error enter a single argument.");
        return 1;
    }
    
    
    string key = argv[1];
    int keyLength = strlen(key);
    int newKey = 0; //stores the current key based on keyword position
    int alphaConverted[keyLength];  //Array of ints converted from plaintext string
    
    
    //Stepping through string to see if alphabetic
    for (int i = 0; i < keyLength; i++)
    {
        if (isalpha(key[i]) == false)
        {
            printf("Error enter an alphabetic argument.");
            return 1;
        }
    }
    
    //Gets the plaintext from user
    printf("plaintext: ");
    string plainText = get_string();
    
    printf("ciphertext: ");
    
    //Vigenere cipher algorithm
    //!!!Still need to wrap the key somehow
    
    //Convert string into int array
    for (int j = 0; j < keyLength; j++)
    {
        
        if (isupper(key[j]))
        {
            //Convert key to int array
            alphaConverted[j] = key[j] - 65;
        }
        else if (islower(key[j]))
        {
            alphaConverted[j] = key[j] - 97;
        }
    }
    
    //Plaintext shift based on converted alphabet shift value
    
    for (int i = 0, n = strlen(plainText); i < n; i++)
    {
        if (isalpha(plainText[i]))
        {
            if(isupper(plainText[i]))
            {
                plainText[i] = (plainText[i] - 65 + alphaConverted[newKey]) % 26 + 65;   
                printf("%c", plainText[i]);
            
                if (newKey < keyLength - 1) //Apprently a condition check can't be out of bounds. I had to subtract 1 from the check to preven this.
                {
                    newKey = newKey + 1;         
                }
                else
                {
                    newKey = 0;
                }
            }
            
            if(islower(plainText[i]))
            {
                plainText[i] = (plainText[i] - 97 + alphaConverted[newKey]) % 26 + 97;   
                printf("%c", plainText[i]);
            
                if (newKey < keyLength - 1) //Apprently a condition check can't be out of bounds. I had to subtract 1 from the check to preven this.
                {
                    newKey = newKey + 1;         
                }
                else
                {
                    newKey = 0;
                }    
            }
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    
    printf("\n");
    return 0;
    
}