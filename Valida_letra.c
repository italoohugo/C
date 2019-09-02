#include <stdio.h>

int ehletra(char);
int ehnumero(char);
int tipo_carac(char);

int main(void){
    char letra;

    printf("Digite um caractere: ");
    scanf("%c",&letra);
    printf("Caractere lido: %c\n",letra);
    printf("Codigo ASCII: %d\n",letra);

    if(ehletra(letra)){
        printf("%c e' uma letra\n",letra);
    }
    else if(ehnumero(letra)){
        printf("%c e' um numero\n",letra);
    }
    else{
        printf("%c e' um caractere especial\n",letra);
    }

    return 0;
}

int ehletra(char c){
    if(c>='A' && c<='Z'){
        return 1;
    }
    else if (c>='a' && c<='z'){
        return 1;
    }
    else{
        return 0;
    }
}

int ehnumero(char c){
    if(c>='0' && c<='9'){
        return 1;
    }
    else{
        return 0;
    }
}





/*
int tipo_carac(char c){
    if(c>='A' && c<='Z'){
        printf("%c e' uma letra\n",c);
    }
    else if (c>='a' && c<='z'){
        printf("%c e' uma letra\n",c);
    }
    else if(c>=48 && c<=57){
        printf("%c e' um digito\n",c);
    }
    else{
        printf("%c e' um caractere especial",c);
    }
}
*/
