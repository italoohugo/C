// http://dontpad.com/flavius/programacao/listaDinamica2b
// salvar com o nome programa.c

#include <stdio.h>
#include "lista.h"

int main(void)
{
	Lista *prim;
	prim = lst_cria();
	printf("\tInserindo o 23...\n");
	prim = lst_insere(prim, 23);
	printf("\tInserindo o 45...\n");
	prim = lst_insere(prim, 45);
	printf("\tInserindo o 56...\n");
	prim = lst_insere(prim, 56);
	printf("\tInserindo o 78...\n");
	prim = lst_insere(prim, 78);
	printf("\n\n");
	printf("Lista:\n");
	lst_imprime(prim);
	printf("\n\n");
	printf("\tRetirando o 78...\n");
	prim = lst_retira(prim, 78);
	printf("Lista:\n");
	lst_imprime(prim);
	printf("\n\n");
	printf("\tRetirando o 23...\n");
	prim = lst_retira(prim, 23);
	printf("Lista:\n");
	lst_imprime(prim);
	printf("\n\n");
	printf("\tInserindo o 99...\n");
	prim = lst_insere(prim, 99);
	printf("Lista:\n");
	lst_imprime(prim);
	printf("\n\n");
	printf("Lista invertida: \n");
	lst_imprime_rec(prim);
	printf("\n\n");
	lst_libera(prim);
	return 0;
}


