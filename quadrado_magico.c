#include <stdio.h>

int menu_principal();
void ler_matriz(int m[][3]);
void gerar_matriz(int m[][3]);
void exibir_matriz(int m[][3]);
void validade(int m[][3]);
void quadrado_magico(int m[][3]);

int matriz[3][3];
int resp_menu;

int main (void){
    int opcao;
    do{
        opcao = menu_principal();
    }while(opcao!=0);

}

int menu_principal(){
    printf("-------QUADRADO MAGICO-------\n\n"
           "1 - LER MATRIZ(USUARIO) \n"
           "2 - GERAR MATRIZ(AUTOMATICO)\n"
           "0 - SAIR\n");
    printf("COMANDO: ");
    scanf("%d",&resp_menu);
    switch(resp_menu){
        case 1:
            ler_matriz(matriz);
            exibir_matriz(matriz);
            validade(matriz);
            return 1;
        case 2:
            gerar_matriz(matriz);
            exibir_matriz(matriz);
            validade(matriz);
            return 1;
        case 0:
            printf("saindo do programa...");
            return 0;

    }
}

void gerar_matriz(int m[][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            m[i][j] = 1 + rand()%9;
        }
    }
}

void exibir_matriz(int m[][3]){
    printf("\n------LISTA-----\n");
    printf("----------------\n");
    for(int i=0; i<3; i++){
        printf("|");
        for(int j=0; j<3; j++){
            printf("%4d", m[i][j]);
        }
    printf("  |\n");
    }
    printf("----------------\n");
    printf("\n");
}

void ler_matriz(int m[][3]){
    int x = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d %d: ",i+1,j+1);
            scanf("%d",&x);
            m[i][j] = x;
        }
    }
}

void validade(int m[][3]){
    int cont=0;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(i!=j){
                if(m[i] == m[j]){
                    cont++;
                }
            }
        }
    }
    if(cont>0){
        printf("LISTA INVALIDA %d\n",cont);
    }

}


