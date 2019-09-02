#include <stdio.h>

float media (float);
int main (void){
    float media;
    int n1,n2,n3;

    printf("Digite a primeira nota: ");
    scanf("%d", &n1);
    printf("Digite a segunda nota: ");
    scanf("%d", &n2);
    printf("Digite a terceira nota: ");
    scanf("%d", &n3);

    media = (n1 + n2 + n3)/3;
    printf("Media: %f",media);
    return 0;
    }
