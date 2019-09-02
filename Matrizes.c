#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheMatriz(int m[][3]);
void exibeMatriz(int m[][3]);
void soma(int a[][3], int b[][3], int c[][3]);

int main(void) {
  int a[3][3], b[3][3], c[3][3];
  srand(time(NULL));
  printf("Programa Matrizes\n");

  preencheMatriz(a);
  printf("\n    Matriz A\n");
  exibeMatriz(a);

  preencheMatriz(b);
  printf("\n    Matriz B\n");
  exibeMatriz(b);

  soma(a, b, c);
  printf("\n    Matriz C\n");
  exibeMatriz(c);
  return 0;
}

void preencheMatriz(int m[][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      m[i][j] = 1 + rand()%20;
    }
  }
}

void exibeMatriz(int m[][3]) {
  for (int i = 0; i < 3; i++) {
    printf("|");
    for (int j = 0; j < 3; j++) {
      printf("%4d", m[i][j]);
    }
    printf("  |\n");
  }
}

void soma(int a[][3], int b[][3], int c[][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
}

