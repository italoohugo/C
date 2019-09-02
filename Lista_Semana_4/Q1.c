#include <stdio.h>

int main(void) {
    char nome1[60], nome2[60];
    int idade1, idade2;

    printf("Programa quem é mais velho e mais novo \n");
    printf("\n");
    printf("Digite o primeiro nome: ");
    //fgets(nome1,59,stdin);
    scanf("%s[^\n]",&nome1);
    printf("Digite a idade: ");
    scanf("%d",&idade1);

    printf("Digite o segundo nome: ");
    //fgets(nome2,59,stdin);
    scanf("%s[^\n]",&nome2);
    printf("Digite a idade: ");
    scanf("%d",&idade2);

    if(idade1>idade2){
        printf("%s e' mais velho. \n",nome1);
        printf("%s e' mais novo. \n",nome2);
    }else{
        printf("%s e' mais velho. \n",nome2);
        printf("%s e' mais novo. \n",nome1);
    }


}
