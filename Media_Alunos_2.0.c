#include <stdio.h>

int main (void){

    float media, nota;
    float soma_nota = 0;
    int alunos = 0;
    int notas = 0;
    printf("Digite a quant alunos: ");
    scanf("%i",&alunos);
    while(alunos!=0){
        printf("Digite a quant notas: ");
        scanf("%i",&notas)
        while(notas!=0){
            printf("Digite a nota: \n");
            scanf("%f",&nota);
            soma_nota= soma_nota+nota;
            notas = notas-1;
        }
        printf("Media: %f \n",media);
        if(media>=7.0){
            printf("Parabéns, você foi Aprovado! \n");
            }else
        {
            printf("Você foi Reprovado!\n");
        }
        alunos = alunos-1;
    }
}

