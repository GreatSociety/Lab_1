//
// Created by Great_Society on 11.11.2020.
//
//Дана строка из нескольких слов. Слова отделяются друг от друга
//пробелами или запятыми. Вывести слова, начинающиеся и
//заканчивающиеся одной и той же буквой.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char inputMassive [100], intermediateMassive[100];
    char*pInputMassive = inputMassive;
    int N,N_1;
    int X = 0;
    int putFlag = 0;
    puts("Please write any sentence on English, and no more than 99 characters:");
    fgets(pInputMassive,100,stdin); // Так мы уверены, что пользователь ничего не перезапишет.
    N = strlen(pInputMassive);

    for (int i = 0; i <= N; i++){
        // Если элемент массива буква, то записываем в массив для вывода слова
        if (isalpha(inputMassive[i])){
            intermediateMassive[X] = inputMassive[i];
            X++;
        }
        // Если нет, то узнаем длину массива для вывода
        else {

            N_1 = strlen(intermediateMassive);

            /* Если условия выполняется: 1-й и последний элемент массива равны
             * и массив не состоит из одного символа, то выводим на печать*/

            if(toupper(intermediateMassive[0]) == toupper(intermediateMassive[N_1-1]) && N_1>1){
                puts(intermediateMassive);
                putFlag++;
            }

            // Посел чего обнуляем счетчик элементов массива и сам массив для печати

            memset(intermediateMassive,0, sizeof(intermediateMassive));
            X = 0;
        }
    }
    if (putFlag == 0){
        puts("Sorry, your message doesn't meet the conditions or doesn't contain the search words");
    }
    return 0;
}
