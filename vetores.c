#include <stdio.h>
#include <math.h>

float calcMedia(int, float[]);
float calcDesvPadrao(int, float, float[]);
float LeitorDeVetor(int, float[]);

int main(void) {
  int num;
  float media, dp;
  float valor[100];
  printf("Programa Calcula Média\n");
  printf("Quantos valores (max. 100)? ");
  scanf("%d", &num);
  LeitorDeVetor(num, valor);
  media = calcMedia(num, valor);
  dp = calcDesvPadrao(num, media, valor);
  printf("Média: %.2f\n", media);
  printf("Desvio Padrão: %.2f\n", dp);
  return 0;
}

float calcMedia(int num, float *valor) {
  float soma = 0.0;
  for (int i = 0; i < num; i++) {
    soma += valor[i];
  }
  return (soma / num);
}

float calcDesvPadrao(int num, float media, float* valor) {
  float soma = 0.0;
  for (int i = 0; i < num; i++) {
    soma += ((valor[i] - media) * (valor[i] - media));
  }
  return sqrt(soma / num);
}

float LeitorDeVetor(int num, float* valor){
    for (int i = 0; i < num; i++) {
        printf("Valor %d: ", i+1);
        scanf("%f", &valor[i]);
      }
}
