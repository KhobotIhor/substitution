#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_key_valid(string key, int required_key_length);
void encrypt(string plaintext, char ciphertext[], string key, int text_length);

int main(int argc, string argv[])
{
    // if not key provided, or too many keys provided, return error
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // get key from input to main function
    string key = argv[1];
    int required_key_length = 26;

    // check for validity of key
    if (!is_key_valid(key, required_key_length))
    {
        // output error to user
        printf("Key must contain %i unique letters only.", required_key_length);
        return 1;
    }

    // get plaintext from user
    string plaintext = get_string("plaintext: ");

    int text_length = strlen(plaintext);

    // create array for ciphertext
    char ciphertext[text_length];

    // encrypting every char of plaintext as unique element into ciphertext array
    encrypt(plaintext, ciphertext, key, text_length);

    // display ciphertext to user char by char as a single string
    printf("ciphertext: ");
    for (int i = 0; i < text_length; i++)
    {
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}

// function for checking the validity of provided key
bool is_key_valid(string key, int required_key_length)
{
    // get length of key provided by user
    int key_length = strlen(key);

    // check if provided key in equal to required key length
    if (key_length != required_key_length)
    {
        // if no then return false
        return false;
    }

    // check every character of key
    for (int i = 0; i < key_length; i++)
    {
        // check if char is alphabetical
        if (!isalpha(key[i]))
        {
            // if no then return false
            return false;
        }
        // we need to go to pre-last character to make sure we do not go out of key string
        // boundaries
        if (i < key_length - 1)
        {
            // check wheather every char in key in unique, and is not repeated further in the key,
            // be it capital- or lower-case
            for (int j = i + 1; j < key_length; j++)
            {
                if (toupper(key[i]) == toupper(key[j]))
                {
                    // if char is not unique then return false
                    return false;
                }
            }
        }
    }
    return true;
}

// function for encrypting every char of plaintext into ciphertext array using key provided by user
void encrypt(string plaintext, char ciphertext[], string key, int text_length)
{

    // encrypting every char of plaintext
    for (int i = 0; i < text_length; i++)
    {
        // make sure the case(capital- or lower-) of every char in plaintext is preserved in
        // ciphertext
        if (isupper(plaintext[i]))
        {
            // get index of char in key that corresponds to char in plaintext(alphabetical)
            int index = plaintext[i] - 'A';

            // add encrypted char to ciphertext array
            ciphertext[i] = toupper(key[index]);
        }
        // same as before but with lower-case char
        else if (islower(plaintext[i]))
        {
            int index = plaintext[i] - 'a';
            ciphertext[i] = tolower(key[index]);
        }

        // if char is not lower-case nor upper-case, then it is not alphabetical and we must
        // preserve it as it is
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
}
