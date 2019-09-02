#include <stdio.h>

int main(void) {
  char resp1, resp2;

  printf("Neste momento, você está antes do primeiro laço\n");
  printf("Você quer entrar no primeiro laço? ");
  scanf("%c", &resp1);
  getchar();
  while (resp1 == 's') {
    printf("\tVocê está dentro do primeiro laço\n");
    printf("\tVocê quer entrar no segundo laço? ");
    scanf("%c", &resp2);
    getchar();
    while (resp2 == 's') {
      printf("\t\tVocê está dentro do segundo laço\n");
      printf("\t\tVocê quer continuar no segundo laço? ");
      scanf("%c", &resp2);
      getchar();
    }
    printf("\tVocê está dentro do primeiro laço\n");
    printf("\tVocê quer continuar no primeiro laço? ");
    scanf("%c", &resp1);
    getchar();
  }
  printf("Você saiu do programa\n");
  return 0;
}
