#include <stdio.h>
#include <time.h> //BIBLIOTECA DA HORA DO SISTEMA
#include <stdlib.h> // BIBLIOTECA DO SRAND (SORTEIO)

int main(void) {
    int moeda;  // 1 - Cara e 2 - Coroa

    int jog;      // Opcao do jogador
    int vitorias = 0, derrotas = 0, n = 0;
    printf("Quer jogar quantas vezes? ");
    scanf("%d",&n);
    srand(time(NULL)); //AQUI O SRAND PEGA A HORA DO SISTEMA PARA USAR NO SORTEIO
    for(int i=0;i<n;i++){
        printf("Jogo Cara ou Coroa\n\n");
        printf("Escolha: \n");
        printf("\t 1 - Cara ou \n\t 2 - Coroa\n");
        scanf("%d", &jog);
        moeda = 1 + rand()%2; // EM %2 VC DEFINE O PARAMETRO DO SORTEIO, SE QUISER SORTEAR DE 1 A 6 POR EXEMPLO
        printf("%d\n", moeda);
        if ((jog == 1)&&(moeda == 1)){
            printf("Deu Cara, você ganhou!\n");
            vitorias = vitorias+1;
        }else if ((jog == 1) && (moeda == 2)){
            printf("Deu Coroa, você perdeu!\n");
            derrotas=derrotas+1;
        }else if ((jog == 2) && (moeda == 2)){
            printf("Deu Coroa, você ganhou!\n");
            vitorias = vitorias+1;
        }else{
            printf("Deu Cara, você perdeu!\n");
            derrotas=derrotas+1;
        }
    }
    printf("Vitorias: %d \n",vitorias);
    printf("Derrotas: %d \n",derrotas);
    return 0;
}
