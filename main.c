#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct pessoas{
    char name[100];
    char gender[20];
    int age;
};

void TakeAndCheckAge();
int FindASpecificWord();

int main(){

    struct pessoas pessoa[10];

    int i;
    int result;

    char find[10];

    for(i = 0; i < 10; i++){

        //system("cls");

        fflush(stdin);

        printf("O nome da %i pessoa:\n", i+1);
        fgets(pessoa[i].name, 100, stdin);// e se alguem botar um numero?

        printf("O sexo da %i pessoa:\n", i+1);
        fgets(pessoa[i].gender, 20, stdin);// e se alguem botar um numero?


        printf("A idade(em anos) da %i pessoa:\n", i+1);
        TakeAndCheckAge(&pessoa[i].age);
    }

    system("cls");

    printf("Voce quer achar pessoas por sexo ou por idade?\n");
    scanf("%s%*c", &find);


    for(i = 0; i < 10; i++){
        printf("%s", pessoa[i].name);
        printf("%s", pessoa[i].gender);
        printf("%i", pessoa[i].age);
    }

    system("pause");
    return 0;
}


void TakeAndCheckAge(int *age){

   int quant = 0;
   do
   {
       if(quant == 0){
           scanf("%i%*c", &*age);
       }else{
           printf("A idade nao e possivel, tente denovo\n");
           scanf("%i%*c", &*age);
       }
       quant++;
   } while (*age <= -1);

   quant = 0;
}

int FindASpecificWord(char *word){

    char *findWord[] = {"Sexo", "sexo", "Idade", "idade"};
    char *fnd;
    int len = sizeof(findWord)/sizeof(findWord[0]);
    int i;

    for(i = 0; i < len; i++){
        if(strstr(word,findWord[i])){
            fnd = strstr(word,findWord[i]);
        }
    }

    //comparar qual é a palavra de fnd e retornar um numero espefico da função
    //Depois disso indentar no result e assim fazer o if no main

    return 0;
}
