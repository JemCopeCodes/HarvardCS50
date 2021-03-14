/*
Passes check50 cs50/problems/2021/x/substitution
https://cs50.harvard.edu/x/2021/psets/2/substitution/

Explaination of main() -- changing the ascii table index into alphabetical index.
'a' will be converted to the ascii table number. (61)
For example, if plainText[i] is 'h'(ascii 68) then the math of 'h' - 'a' is the same as 68 - 61 = 7
7 is the alphabetical index of the letter h (in an array that starts from 0) because it's the 8th letter in the alphabet
because the array starts at 0, argv[1][7] will give you the 8th letter from the key
the alphabetical index is equal to the key index because the key is also 26 letters

*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validateKey();


int main(int argc, string argv[]){
    if(argc == 2 && validateKey(argv[1])){
        string plainText = get_string("plaintext: ");
        string cipherText = plainText;
        int keyIndex = 0;

        for(int i = 0; i < strlen(plainText); i++){
            if(isalpha(plainText[i])){
                if(islower(plainText[i])){
                    keyIndex = plainText[i] - 'a';
                    cipherText[i] = tolower(argv[1][keyIndex]);
                } else {
                    keyIndex = plainText[i] - 'A';
                    cipherText[i] = toupper(argv[1][keyIndex]);
                }
            }
        }
        printf("ciphertext: %s\n", cipherText);
    } else {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

int validateKey(string key){
    if(strlen(key) != 26){
        printf("Key must be 26 characters.\n");
        return 0;
    }
    for(int i = 0; i < 26; i++){
        if(isalpha(key[i])){
            for(int k = i + 1; k < 26; k++){
                if(key[i] == key[k]){
                    printf("Error: Key must not contain any repeat characters.\n");
                    return 0;
                }
            }
        } else {
            printf("Error: Key must only contain characters from the alphabet.\n");
            return 0;
        }
    }
    return 1;
}