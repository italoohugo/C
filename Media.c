#include <stdio.h>

int main(){

    int nota1, nota2, nota3, media;

    printf("Digite a nota 1: \n");
    scanf("%i", &nota1);
    printf("Digite a nota 2: \n");
    scanf("%i", &nota2);
    printf("Digite a nota 3: \n");
    scanf("%i", &nota3);

    media = (nota1 + nota2 + nota3) / 3;
    printf("Media: %i \n",media);

    return 0;
}
