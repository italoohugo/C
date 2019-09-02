#include <stdio.h>
#include <time.h> //BIBLIOTECA DA HORA DO SISTEMA
#include <stdlib.h> // BIBLIOTECA DO SRAND (SORTEIO)


void gerarlista(int n, int *lista);
void exibirlista(int n, int *lista);
void shuffle(int n, int *lista);
int choice(int n, int *lista);
//vet2mat
//mat2vet

int main (void){
    int n;
    srand(time(NULL)); //AQUI O SRAND PEGA A HORA DO SISTEMA PARA USAR NO SORTEIO
    printf("Digite a quant de numeros: ");
    scanf("%d",&n);
    int lista[n];
    printf("LISTA SEM ALTERACAO: \n");
    gerarlista(n, lista);
    exibirlista(n, lista);
    printf("LISTA EMBARALHADA:\n");
    shuffle(n, lista);
    exibirlista(n, lista);
    choice(n, lista);
    return 0;
}

void gerarlista(int n, int *lista){
    for(int i=0; i<n; i++){
        lista[i]= i+1;
    }
}

void exibirlista(int n, int *lista){
    for(int i=0; i<n; i++){
        printf("%d\t",lista[i]);
    }
    printf("\n");
}

void shuffle(int n, int *lista){
    for(int i=0; i<n; i++){
        int sorteio = rand()%n;
        int temp = lista[i];
        lista[i] = lista[sorteio];
        lista[sorteio]=temp;
    }
}

int choice(int n, int *lista){
    int sorteio;
    sorteio = 1 + rand()%n; // EM %n VC DEFINE O PARAMETRO DO SORTEIO, SE N FOR 6, ELE VAI SORTEAR DE 1 A 6 POR EXEMPLO
    printf("\n");
    printf("SORTEIO: %d\n",sorteio);
}
