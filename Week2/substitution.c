/*
https://cs50.harvard.edu/x/2021/psets/2/substitution/

*/

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]){
    if(argc == 2 && validateKey(argv[1])){
        string plainText = get_string("plaintext: ");
        string ciphertext = plainText
        // do substitution
        printf("ciphertext: %s\n", ciphertext);
    } else {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

int validateKey(string key){
// check that the key given is all alpha characters, 26 in length, and has each letter only once.
    if(strlen(key) != 26){
        printf("Key must be 26 characters.\n");
        return 0;
    }

    
}