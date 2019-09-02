#include <stdio.h>

void troca_valor(int*, int*);

int main(void){
    int a,b;
    printf("Programa que troca dois valores inteiros\n");
    printf("");
    printf("Informe dois valores inteiros\n");
    printf("Valor de A:");
    scanf("%d",&a);
    printf("Valor de B:");
    scanf("%d",&b);
    printf("Valores originais: A=%d e B=%d \n ",a,b);
    troca_valor(&a,&b);
    printf("Valores trocados: A=%d e B=%d \n ",a,b);


}

void troca_valor(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;

}
