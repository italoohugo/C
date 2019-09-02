
#include <stdio.h>

int main(void) {
    char nome1[60], nome2[60];
    int idade1, idade2, calculo;

    printf("Programa Diferença de Idade \n");
    printf("\n");

    printf("Digite o primeiro nome: ");
    fgets(nome1, 59 ,stdin);
    printf("Digite a idade: ");
    scanf("%d",&idade1);

    printf("Digite o segundo nome: ");
    fgets(nome2, 59 ,stdin);
    printf("Digite a idade: ");
    scanf("%d",&idade2);

    if(idade1>idade2){
        calculo=idade1-idade2;
        printf("A diferenca de idade e' de %d anos. \n",calculo);
    }else{
        calculo=idade2-idade1;
        printf("A diferenca de idade e' de %d anos. \n",calculo);
    }


}
