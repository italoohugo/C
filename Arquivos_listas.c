#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cores Cores;

struct cores {
  char* nomeCor;
  char* Codigos;
  Cores* prox;
} ;

int main(void) {
    FILE *arquivo;
    FILE *codigos;
    int i, tam;
    char linha[256];
    Cores* novaCor;
    Cores* lista;
    Cores* ultimo;

    printf("Integrando Arquivos e Listas Dinâmicas\n");

    codigos = fopen("codigos.txt","rt");
    arquivo = fopen("palavras.txt","rt");
	if (arquivo == NULL){
		printf("Erro na abertura do arquivo\n!");
		exit(1);
	}
	if (codigos == NULL){
		printf("Erro na abertura do arquivo\n!");
		exit(1);
	}

    lista = NULL;
	while(fgets(linha,256,arquivo)){
        novaCor = (Cores*) malloc(sizeof(Cores));
        tam = strlen(linha) + 1;
        novaCor->nomeCor = (char*) malloc(tam*sizeof(char));
        strcpy(novaCor->nomeCor, linha);
        novaCor->prox = lista;
        lista = novaCor;
	}
	fclose(arquivo);

    printf("\nConteúdo do Arquivo Texto");
    printf("\n");
    novaCor = lista;
    i = 1;
    while (novaCor != NULL) {
        printf("Cores %d: %s ", i, novaCor->nomeCor);
        novaCor = novaCor->prox;
        i++;
    }

    novaCor = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(novaCor->nomeCor);
        free(novaCor);
        novaCor = lista;
    }

    lista = NULL;
	while(fgets(linha,256,arquivo)){
        novaCor = (Cores*) malloc(sizeof(Cores));
        tam = strlen(linha) + 1;
        novaCor->nomeCor = (char*) malloc(tam*sizeof(char));
        strcpy(novaCor->nomeCor, linha);
        novaCor->prox = NULL;
        if (lista == NULL) {
            lista = novaCor;
        }
        else {
            ultimo->prox = novaCor;
        }
        ultimo = novaCor;
	}
    fclose(arquivo);

    printf("\nConteúdo do Arquivo Texto\n");
    novaCor = lista;
    i = 1;
    while (novaCor != NULL) {
        printf("Cores %d: %s", i, novaCor->nomeCor);
        novaCor = novaCor->prox;
        i++;
    }

    novaCor = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(novaCor->nomeCor);
        free(novaCor);
        novaCor = lista;
    }
    return 0;
}
