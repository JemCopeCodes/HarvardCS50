/*
Credit Card Formats
    American Express
        15 digits, starts with 34 or 37
    Mastercard
        16 digits, starts with 51, 52, 53, 54, 55
    VISA
        13 or 16 digits, starts with 4

Checksum
    - Multiply every other digit by 2, starting with the second-to-last digit
    - Add those products digits together
    - Add teh sum to the sum of the digits that weren't multiplied by 2.
    - If the total's last digit is 0, number is valid!
*/

#include <stdio.h>
#include <cs50.h>

int checkSum(long number){
    //Luhn's Algorithm
    //printf("%ld\n", number/10 % 10);//gets last digit
    return 1; //temp for debug
}

// should probably make this a function so it's cleaner.
// int getFirstDigits(long number, int numOfDigits){
//     number / getLength(number)
// }

int getLength(long number){
    int counter = 0;

    while (number > 0){
        number /= 10;
        counter++;
    }
    return counter;
}

int main(void){
    long number = get_long("Number: ");
    if(checkSum(number)){
        //printf("double nums? %ld\n", number/100000000000000 % 100 );
            if((getLength(number) == 16) && number/1000000000000000 % 10 == 4){
                printf("VISA\n");
            } else if (getLength(number) == 13 && number/1000000000000 % 10 == 4){
                printf("VISA\n");
            }
            else if (getLength(number) == 16 && (number/100000000000000 % 100 == 51 || number/100000000000000 % 100 == 52 || number/100000000000000 % 100 == 53 || number/100000000000000 % 100 == 54 || number/100000000000000 % 100 == 55 )) {
                printf("MASTERCARD\n");
            } else if (getLength(number) == 15 && (number/10000000000000 % 100 == 34 ||number/10000000000000 % 100 % 100 == 37)) {
                printf("AMEX\n");
            } else {
                printf("INVALID\n");
            }
    } else {
        printf("INVALID\n");
    }
}

