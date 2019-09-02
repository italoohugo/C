#include <stdio.h>

int main()
{
    int base;
    int altura;
    int area;

    printf("Digite a base: ");
    scanf("%i",&base);
    printf("Digite a altura: ");
    scanf("%i", &altura);

    area = base * altura;
    printf("O valor da area e: %i \n",area);
    return 0;
}
