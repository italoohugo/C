#include <stdio.h>
#include <time.h>

//USANDO FUNÇÃO RECURSIVA

int fat_r(int);
void fat(int);
int recursiva(void);
int iterativa(void);

int main(void){
    iterativa();
    recursiva();
}

int recursiva(void){
    int n,result;
    clock_t inicio_r, fim_r;
    printf("USANDO FUNCAO RECURSIVA\n");

    printf("Informe um valor Inteiro: ");
    scanf("%d",&n);

    /*Iniciamos a contagem*/
    inicio_r=clock();

    result = fat_r(n);
    printf("%d!=%d",n,result);

    /*Fim da contagem*/
    fim_r=clock();
    printf("\nTempo: %f\n",(float)(fim_r - inicio_r)/CLOCKS_PER_SEC);

    return 0;
}

int fat_r(int n ){
    if(n==0){
        return 1;
    }
    else{
        return n*fat_r(n-1);
    }
}
//USANDO FUNÇÃO ITERATIVA

int iterativa(void){
    int fatorial;
    int n;
    clock_t inicio_i, fim_i;
    printf("USANDO FUNCAO ITERATIVA\n");
    printf("Informe um valor Inteiro: ");
    scanf("%d", &n);
    /*Iniciamos a contagem*/
    inicio_i=clock();

    fat(n);

    /*Fim da contagem*/
    fim_i=clock();
    printf("\nTempo: %f\n",(float)(fim_i - inicio_i)/CLOCKS_PER_SEC);

    return 0;
}


void fat(int n){
    double value = 1;
    for(int i =1 ;i <=n; i++){
        value = value * i;
        printf("value> %.lf",value);
    }

}
