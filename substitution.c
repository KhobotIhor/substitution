#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//declaring alphabet for further use
const string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

//declaring a function encrypt
string encrypt(string text_input, string key);

int main(int argc, string argv[])
{

    //getting a key from the command-line arguments
    string key = argv[1];


    //if there are not 2 arguments then tell a user the correct usage
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");

        //return failure
        return 1;
    }
    //if the key length is not 26 then ask user to choose a key of length 26
    else if(strlen(key) != 26)
    {
        printf("key must contain 26 characters\n");

        //return failure
        return 2;
    }
    else
    {
        //if some chars in key are not uppercase then transform them to uppercase for a normal program work
        for(int i = 0; i < 26; i++)
        {
            if(!isupper(key[i]))
            {
                key[i] = toupper(key[i]);
            }
        }

        //ask user for a text to encrypt
        string text_to_encrypt = get_string("plaintext: ");

        //print encrypted text
        printf("cyphertext: %s\n", encrypt(text_to_encrypt, key));

        //return success
        return 0;
    }
}



string encrypt(string text_input, string key)
{

    //declaring a variable text_output whic will be outputed by function at the end
    string text_output = text_input;


    //interate through each char of the text_input
    for(int i_text = 0; i_text < 26; i_text++)
    {

        //check if char is alphabetical
        if (isalpha(text_output[i_text]))
        {
            //substitute variable to uppercase char for comparison with alphabet letters
            char letter_sub = toupper(text_output[i_text]);

            //iterate through each letter of the alphabet
            for(int i_alpha = 0; i_alpha < 26; i_alpha++)
            {

                //check if uppercased text_input letter is equal to the alphabet letter
                if (letter_sub == alpha[i_alpha])
                {

                    //if letter was initially uppercased then it will remain uppercased at the end
                    if(isupper(text_output[i_text]))
                    {

                        //make the text_output letter equal to the respective letter in the key
                        text_output[i_text] = key[i_alpha];
                    }

                    //if letter was initially lowercase then it will remain lowercase
                    else
                    {

                        //make the text_output letter equal to the respective letter in the key
                        text_output[i_text] = tolower(key[i_alpha]);
                    }
                }
            }
        }
    }

    //return encrypted text
    return text_output;
}
