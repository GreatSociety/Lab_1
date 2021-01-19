//
// Created by Дмитрий Ярошевич on 1/19/21.
//

#include <stdio.h>
#include <stdlib.h>


char equiall (char *input);
int isBeta (char charc);
int toUp (char charc);

int main(){

    char *answer = malloc(2);
    char *inputString = malloc(128);

    do {

        puts("Please, write a sentence:");
        fgets(inputString, 128, stdin);

        equiall(inputString);

        puts("Something else?(Y/N)");
        fgets(answer,2,stdin);
        getchar();

    }while(toUp(*answer)=='Y');
}

char equiall (char *input){

    int i;
    int j;

    for(i = 0 ;*(input+i)!= '\0';i++) {
        if (isBeta(input[i])) {
            j = i;
            for(; isBeta(*(input + i)); i++) {
            }
            if ((toUp(input[j]) == toUp(input[i - 1]))  && (i-1-j)>0){
                for (int z = j; z < i; z++) {
                    printf("%c", input[z]);
                }
                putchar('\n');
            }
        }
    }
    return 0;
}

int isBeta (char charc){
    return (charc >= 'A' && charc <= 'Z')||(charc >= 'a' && charc <= 'z') ? 1:0;
}

int toUp (char charc){

     if ((charc>='A')&&(charc<='Z')) return charc;

     else{
         return (isBeta(charc))? charc-32: 0;
     }
}