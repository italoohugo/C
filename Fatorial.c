#include <stdio.h>

int fat (int);
int main(void){
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