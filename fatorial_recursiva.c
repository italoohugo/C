#include <stdio.h>
#include <time.h>

//USANDO FUNÇÃO RECURSIVA

int fat (int);
int recursiva(void);
int iterativa(void);

int main(void){
    clock_t inicio_r, fim_r, inicio_i, fim_i;
    /*Iniciamos a contagem*/
    inicio_r=clock();
    printf("USANDO FUNCAO RECURSIVA\n");
    recursiva();
    /*Fim da contagem*/
    fim_r=clock();
    printf("\nTempo: %f\n",(float)(fim_r - inicio_r)/CLOCKS_PER_SEC);
    /*Iniciamos a contagem*/
    inicio_i=clock();
    printf("USANDO FUNCAO ITERATIVA\n");
    iterativa();
    /*Fim da contagem*/
    fim_i=clock();
    printf("\nTempo: %f\n",(float)(fim_i - inicio_i)/CLOCKS_PER_SEC);
}

int recursiva(void){
    int n,result;
    printf("Informe um valor Inteiro: ");
    scanf("%d",&n);
    result = fat(n);
    printf("%d!=%d",n,result);
    return 0;
}

int fat(int n ){
    if(n==0){
        return 1;
    }
    else{
        return n*fat(n-1);
    }
}
//USANDO FUNÇÃO ITERATIVA

int iterativa(void){
    int fat, n;
    printf("Informe um valor Inteiro: ");
    scanf("%d", &n);

    for(fat=1; n>1; n=n-1){
        fat = fat * n;
    }

    printf("%d!=%d",n,fat);
    return 0;
}


