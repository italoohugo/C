#include <stdio.h>
#include <time.h>

int fibo(int);

int main(void) {
  int num, f;
  float tempo;
  time_t tInicial, tFinal;

  printf("Hello Fibonacci\n");
  printf("Informe valor: ");
  scanf("%d", &num);
  tInicial = time(NULL);
  for (int i = 1; i <= num; i++) {
    f = fibo(i);
    printf("%d\t", f);
  }
  tFinal = time(NULL);
  tempo = difftime(tFinal, tInicial);
  printf("\nTempo: %f s\n", tempo);
  printf("\nFim do Programa!\n");
  return 0;
}

int fibo(int n) {
  if ((n == 1) || (n == 2))
    return 1;
  else
    return fibo(n-1) + fibo(n-2);
}
