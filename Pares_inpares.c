#include <stdio.h>

int main(){
    int n = 0;
    printf("Digite o valor maximo: ");
    scanf("%i",&n);
    printf("Pares: \n");
    for(int i=0;i<n;i++){
        if(i%2==0){
            printf("%i \n",i);
        }
    }
    printf("Inpares: \n");
    for(int j=0;j<n;j++){
        if(j%3==0){
            printf("%i \n",j);
        }
    }




}
