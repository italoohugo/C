#include <stdio.h>

int main(void) {
  char resp1, resp2;

  printf("Neste momento, voc� est� antes do primeiro la�o\n");
  printf("Voc� quer entrar no primeiro la�o? ");
  scanf("%c", &resp1);
  getchar();
  while (resp1 == 's') {
    printf("\tVoc� est� dentro do primeiro la�o\n");
    printf("\tVoc� quer entrar no segundo la�o? ");
    scanf("%c", &resp2);
    getchar();
    while (resp2 == 's') {
      printf("\t\tVoc� est� dentro do segundo la�o\n");
      printf("\t\tVoc� quer continuar no segundo la�o? ");
      scanf("%c", &resp2);
      getchar();
    }
    printf("\tVoc� est� dentro do primeiro la�o\n");
    printf("\tVoc� quer continuar no primeiro la�o? ");
    scanf("%c", &resp1);
    getchar();
  }
  printf("Voc� saiu do programa\n");
  return 0;
}
