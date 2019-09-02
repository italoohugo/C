#include <stdio.h>

int soma_valor(int, int);

int main(void){
    int v1, v2, soma;
    printf("Programa soma numeros \n");
    printf("Informe um valor inteiro: ");
    scanf("%d",&v1);
    printf("Informe outro valor inteiro: ");
    scanf("%d",&v2);
    soma = soma_valor(v1,v2);
    printf("A soma de %d com %d e' igual a %d\n",v1,v2,soma);
    return 0;
}

//int soma_valor(int a, int b){
//    int s;
//    s = a + b;
//    return s;
//}

int soma_valor(int a, int b){
    return a + b;
}
