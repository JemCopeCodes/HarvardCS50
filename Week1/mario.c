#include <stdio.h>
#include <cs50.h>

int main(void){
    int height = 0;

    do{
    height = get_int("Height: ");
    }
    while(height < 1 || height > 8);

    for(int i = 1; i <= height; i++){
        for(int x = 0; x < (height - i); x++){
            printf(" ");
        }
        for(int y = 0; y < i; y++){
            printf("#");
        }
        printf("  ");
        for(int z = 0; z < i; z++){
            printf("#");
        }
        printf("\n");
    }
}