/*
https://cs50.harvard.edu/x/2021/psets/2/substitution/

*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validateKey();

int main(int argc, string argv[]){
    if(argc == 2 && validateKey(argv[1])){
        string plainText = get_string("plaintext: ");
        string ciphertext = plainText;
        // do substitution
        printf("ciphertext: %s\n", ciphertext);
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