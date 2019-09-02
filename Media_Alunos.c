#include <stdio.h>

int main (void){

    float n1, n2, n3, media;
    int n = 0;
    printf("Digite quant, alunos: ");
    scanf("%i",&n);
    while(n!=0){
        printf("Informe as 3 notas: \n");
        scanf("%f",&n1);
        scanf("%f",&n2);
        scanf("%f",&n3);
        media = (n1+n2+n3)/3;
        printf("Media: %f \n",media);
        if(media>=7.0){
            printf("Parabéns, você foi Aprovado! \n");
            }else
        {
            printf("Você foi Reprovado!\n");
        }
        n = n-1;
    }
}

