#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct pessoas{
    char name[100];
    char gender;
    int age;
};

char TakeAndCheckGender();
void TakeAndCheckAge();
int FindASpecificWord();
char FindPeopleGender();
int FindPeopleAge();

int main(){

    struct pessoas pessoa[10];

    int i;
    int result_check_genorage;
    int flag = 1;

    char result_find_people_G;
    int result_find_people_A;

    char find[20];

    for(i = 0; i < 10; i++){

        system("cls");

        fflush(stdin);

        printf("O nome da %i pessoa:\n", i+1);
        fgets(pessoa[i].name, 100, stdin);

        printf("O sexo da %i pessoa:\n", i+1);
        pessoa[i].gender = TakeAndCheckGender();

        printf("A idade(em anos) da %i pessoa:\n", i+1);
        TakeAndCheckAge(&pessoa[i].age);
    }

    system("cls");

    while(flag == 1){

        fflush(stdin);

        printf("Voce quer achar pessoas por sexo ou por idade?\n");
        fgets(find, 20, stdin);

        result_check_genorage = FindASpecificWord(&find);

        if(result_check_genorage == 1){
            result_find_people_G = FindPeopleGender();
        }
        else
        {
            if(result_check_genorage == 0){
                result_find_people_A = FindPeopleAge();
            }
        }
        

        for(i = 0; i < 10; i++){
            if(result_check_genorage == 1){
                if(result_find_people_G == pessoa[i].gender){
                    printf("%s\n", pessoa[i].name);
                }
            }
            else{
                if(result_check_genorage == 0){
                    if(result_find_people_A == pessoa[i].age){
                        printf("%s\n", pessoa[i].name);
                    }
                }
            }
        }

        printf("Quer achar mais alguem?\n");
        printf("0 para fechar e 1 para continuar\n");
        scanf("%i%*c", &flag);
}
    system("pause");
    return 0;
}


char TakeAndCheckGender(){
    char gender[20];  

    int quant = 0;

    do
    {
        if(quant == 0){
            fgets(gender, 20, stdin);
        }
        else{
            printf("Tente de novo, comece com letras maiusculas\n");
            fgets(gender, 20, stdin);
        }
        
        quant++;
    } while (strcmp(gender, "Masculino\n") && strcmp(gender, "Feminino\n"));
   
    quant = 0;

    if(!strcmp(gender, "Masculino\n") || !strcmp(gender, "masculino\n")){
        return 'M';
    }
    else{
        if(!strcmp(gender, "Feminino\n") || !strcmp(gender, "feminino\n")){
            return 'F';
        }
    }

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

    int num;

    for(i = 0; i < len; i++){
        if(strstr(word,findWord[i])){
            fnd = strstr(word,findWord[i]);
        }
    }

    if((!strcmp("Sexo\n", fnd)) || (!strcmp("sexo\n", fnd))){
        num = 1;
    }
    else{
        if((!strcmp("Idade\n", fnd)) || (!strcmp("idade\n", fnd))){
            num = 0;
        }
    }

    return num;
}

char FindPeopleGender(){

    char gender;

    int quant = 0;
    char resultFind;

    printf("Diga o sexo que quer buscar (F para feminino e M para masculino):\n");
    do
    {
        if (quant == 0)
        {
            scanf("%c%*c", &gender);
        }
        else
        {
            printf("O argumento so pode conter M para masculino e F para Feminino\n");
            scanf("%c%*c", &gender);
        }
        quant++;

    } while ((gender != 'M') && (gender != 'F'));

    quant = 0;

    if (gender == 'F')
    {
        resultFind = 'F';
    }
    else
    {
        resultFind = 'M';
    }

    return resultFind;
}

int FindPeopleAge(){

    int age;

    int quant = 0;

    int resultFind;

    printf("Diga a idade que quer buscar:\n");
    do
    {
        if (quant == 0)
        {
            scanf("%i%*c", &age);
        }
        else
        {
            printf("O argumento so pode conter numeros positivos\n");
            scanf("%i%*c", &age);
        }
        quant++;

    } while (age <= -1);

    quant = 0;

    resultFind = age;

    return resultFind;
}

