#include <stdio.h>

int main(void)
{
    int i, n;
    float nota,somaNota, media;

    somaNota = 0;
    i = 1;
    printf("Quantas notas? ");
    scanf("%d",&n);
    while (i <= n){
        printf("Informe a nota %d: ",i);
        scanf("%f", &nota);
        somaNota = somaNota + nota;
        i = i + 1;
    }
    media = somaNota / n;
    printf("Sua media foi: %.1f\n", media);
    if (media >= 7.0){
    printf("Parabéns! voce foi aprovado!\n");
    } else {
        printf("Pena, voce foi reprovado\n");
    }
    printf("Fim do programa!");

    return 0;
}
