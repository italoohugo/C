#include <stdio.h>

int main(void){
    char letra;
    printf("Digite um caractere: ");
    scanf("%c",&letra);

    printf("Letra: %c ASCII: %d\n",letra,letra);

    letra = 86;
    printf("Letra: %c ASCII: %d\n",letra,letra);

    letra++;
    printf("Letra: %c ASCII: %d\n",letra,letra);

    return 0;
}
