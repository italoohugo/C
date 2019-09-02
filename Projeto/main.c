#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//void salvar_gasto(struct gastos*);
//void salvar_ganho(struct ganhos*);

struct ganhos{
    char descricao[60];
    float entrada;
    int dia,mes,ano;
};


struct gastos{
    char descricao[60];
    float entrada;
    int dia,mes,ano;
};

//ASSINATURAS FUNÇOES

int menu_principal(void);
int menu_ganhos (void);
int menu_gastos (void);
int menu_relatorios(void);
int menu_sobre(void);
int validar_apagar(char);

//FUNCOES GANHOS

int ganhos_registrar(void);
int ganhos_apagar(void);
int ganhos_visualizar(void);

//FUNÇOES GASTOS

int gastos_registrar(void);
int gastos_apagar(void);
int gastos_visualizar(void);

//FUNÇOES RELATORIO

//

//FUNÇOES VALIDACAO

int valida_data(int dia, int mes, int ano);


//ARQUIVOS

FILE *ganhos_entrada;
FILE *ganhos_descricao;
FILE *ganhos_data;

FILE *gastos_entrada;
FILE *gastos_descricao;
FILE *gastos_data;



//VARIAVEIS GLOBAL

float ganhos_total;
float gastos_total;



int main (void)
{
    setlocale(LC_ALL, "Portuguese");
    int op;
    do{
        //system("cls");
        op = menu_principal();
    }while(op!=0);

}

int menu_principal(){
    int op;
    printf("-----------------------------------------------------------------------\n");
    printf("------------------------BEM-VINDO AO SIG-FINANCE----------------------- \n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n");
    printf("-----------------------------MENU PRINCIPAL----------------------------\n");
    printf("- ESCOLHA UM DOS COMANDOS: \n");
    printf("1 - GANHOS \n");
    printf("2 - GASTOS \n");
    printf("3 - RELATORIOS \n");
    printf("4 - SOBRE\n");
    printf("0 - SAIR\n");
    printf("-----------------------------------------------------------------------\n");
    printf("COMANDO: ");
    scanf("%d", &op);

    switch(op){
        case 1:
            while(menu_ganhos());
            return 1;
        case 2:
            while(menu_gastos());
            return 1;
        case 3:
            menu_relatorios();
            return 1;
        case 4:
            menu_sobre();
            return 1;
        case 0:
            printf("Saindo do programa...\n");
            return 0;

    }


}

int menu_ganhos (){
    int opcao;
    printf("-----------------------------------------------------------------------\n");
    printf("------------------------------MENU GANHOS------------------------------\n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n");
    printf("- ESCOLHA UM DOS COMANDOS: \n");
    printf("1 - REGISTRAR GANHOS \n");
    printf("2 - APAGAR GANHOS\n");
    printf("3 - VISUALIZAR GANHOS \n");
    printf("0 - SAIR\n");
    printf("-----------------------------------------------------------------------\n");
    printf("COMANDO: ");
    scanf("%d",&opcao);
    switch (opcao){
        case 1:
            ganhos_registrar();
            return 1;
        case 2:
            ganhos_apagar();
            return 1;
        case 3:
            ganhos_visualizar();
            return 1;
        case 0:
            printf("Saindo do Menu ganhos...\n");
            printf("\n");
            return 0;

    }


}

int menu_gastos (){
    printf("-----------------------------------------------------------------------\n");
    printf("------------------------------MENU GASTOS------------------------------\n");
    printf("-----------------------------------------------------------------------\n");
    int resp_menu_gastos;
    printf("\n");
    printf("- ESCOLHA UM DOS COMANDOS: \n");
    printf("1 - REGISTRAR GASTOS \n");
    printf("2 - APAGAR GASTOS\n");
    printf("3 - VISUALIZAR GASTOS \n");
    printf("0 - SAIR\n");
    printf("-----------------------------------------------------------------------\n");
    printf("COMANDO: ");
    scanf("%d",&resp_menu_gastos);
    switch (resp_menu_gastos) {
        case 1:
            gastos_registrar();
            return 1;
        case 2:
            gastos_apagar();
            return 1;
        case 3:
            gastos_visualizar();
            return 1;
        case 0:
            printf("Saindo do Menu gastos...\n");
            printf("\n");
            return 0;
        }

    }

int menu_relatorios(){
    float ganhos_exibir;
    float gastos_exibir;
    char superavit[12] ="SUPERAVIT";
    char deficit [12] = "DEFICIT";
    float diferenca;
    float razao;

    char status[12];
    printf("-----------------------------------------------------------------------\n");
    printf("------------------------------RELATORIOS-------------------------------\n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n");

    FILE* fp_ganhos = fopen("ganhos_total.txt","rb");
    fscanf(fp_ganhos,"%f",&ganhos_exibir);
    if(fp_ganhos == NULL){
        printf("Nao existe dados de ganhos e gastos salvos\n\n");
        return 0;
        exit(1);
    }
    FILE* fp_gastos = fopen("gastos_total.txt","rb");
    fscanf(fp_gastos,"%f",&gastos_exibir);
    if(fp_gastos == NULL){
        printf("Nao existe dados de ganhos e gastos salvos\n\n");
        return 0;
        exit(1);
    }

    printf("\f GANHOS: R$%.2f \n",ganhos_exibir);
    printf("\f GASTOS: R$%.2f \n",gastos_exibir);

    if (ganhos_exibir >= gastos_exibir){
        diferenca = ganhos_exibir - gastos_exibir;

        printf("\f SUAS CONTAS ESTAO EM SUPERAVIT\n");
        printf("\f SEU %s E' DE R$%.2f \n",superavit,diferenca);

        razao = (diferenca/gastos_exibir)*100;
        printf("\f PORCENTAGEM: %.0f PORCENTO \n",razao);

        if(razao >= 10.00000 && razao <= 30.00000){
            printf("\f STATUS: BOM \n");
        }if(razao > 30.00000 && razao <= 50.00000){
            printf("\f STATUS: OTIMO \n");
        }if(razao > 50.00000) {
            printf("\f STATUS: EXCELENTE \n");
            printf("\f PARABENS: VOCE E' UM MESTRE EM POUPAR DINHEIRO, CONTINUE ASSIM \n");
        }


    }else{
        diferenca = gastos_exibir - ganhos_exibir;
        printf("\f SUAS CONTAS ESTAO EM DEFICIT\n");
        printf("\f SEU %s E' DE R$%.2f \n",deficit,diferenca);

        razao = (diferenca/ganhos_exibir)*100;
        printf("\f PORCENTAGEM: %.0f PORCENTO \n",razao);
        if(razao >= 10.00000 && razao <= 30.00000){
            printf("\f STATUS: RUIM \n");
        }if(razao > 30.00000 && razao <= 50.00000){
            printf("\f STATUS: MUITO RUIM \n");
        }if(razao > 50.00000){
            printf("\f STATUS: PESSIMO \n");
            printf("\f CUIDADO: GASTAR MAIS DO QUE GANHA PODE ATRAPLHAR SERIAMENTE A SUA VIDA\n");
        }
    }


    printf("\n");
    fclose(fp_ganhos);
    fclose(fp_gastos);
    return 0;
}


int menu_sobre(){
    printf("-----------------------------------------------------------------------\n");
    printf("--------------------------------SOBRE----------------------------------\n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n");
    printf("------SIG-Finance: Um Sistema de Controle de Financas Domesticas-------\n"
           "\n"
           "O presente programa tem como objetivo realizar o acompanhamento do fluxo\n"
           " financeiro em uma residencia, evitandoo descontrole de gastos.\n"
           "O programa registra seus ganhos e gastos; gera um relatorio com deficit\n"
           "ou superavit, se for o caso; mostra seu status de consumidor; etc.\n"
           "\n"
           "Desenvolvedor: ITALO HUGO DA SILVA\n"
           "");
    printf("\n");
    return 0;

}



int ganhos_registrar(){
    /*
    float entrada_ganhos;
    char descricao_ganhos[250];
    int dia, mes, ano;
     */
    float x;
    float aux;
    struct ganhos novo_ganho;


    printf("-----------------------------------------------------------------------\n");
    printf("---------------------------REGISTRAR GANHOS----------------------------\n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n");
    printf("ESCREVA UMA DESCRICAO:");
    scanf(" %[^\n]", novo_ganho.descricao);
    //gets(*descricao_ganhos);
    //scanf("%s",&*descricao_ganhos);
    //fgets(*descricao_ganhos,59,stdin);

    do {
        printf("DIGITE A DATA:\n");
        printf("DIA:");
        scanf("%d", &novo_ganho.dia);
        printf("MES:");
        scanf("%d", &novo_ganho.mes);
        printf("ANO:");
        scanf("%d", &novo_ganho.ano);
    }while(valida_data(novo_ganho.dia,novo_ganho.mes,novo_ganho.ano));


    printf("DIGITE O VALOR:");
    scanf("%f",&novo_ganho.entrada);

    x = novo_ganho.entrada;

    FILE* fp1 = fopen("ganhos_total.txt","rb");
    fscanf(fp1,"%f",&ganhos_total);
    fclose(fp1);


    FILE* fp2 = fopen("ganhos_total.txt","wb");
    aux = ganhos_total + x;
    fprintf(fp2,"%f",aux);
    fclose(fp2);


    salvar_ganho(&novo_ganho);
    printf(">>>>> GANHO REGISTRADO COM SUCESSO <<<<<\n\n");

//    ganhos_entrada = fopen("ganhos_entrada.txt","a");
//    fprintf(ganhos_entrada,"%.2f\n",entrada_ganhos);
//    fclose(ganhos_entrada);
//
//    ganhos_descricao = fopen("ganhos_descricao.txt","a");
//    fprintf(ganhos_descricao,"%s\n",descricao_ganhos);
//    fclose(ganhos_descricao);
//
//    ganhos_data = fopen("ganhos_data.txt","a");
//    fprintf(ganhos_data,"%i/%i/%i\n",dia,mes,ano);
//    fclose(ganhos_data);
//
//
//
//    printf("\n");
//    printf("- ENTRADA REGISTRADA COM SUCESSO!\n");
//    printf("\n");
//
//    //getch();
}


int ganhos_apagar (){
    char resp;
    printf("-----------------------------------------------------------------------\n");
    printf("-----------------------------APAGAR GANHOS-----------------------------\n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n");
    printf("- TEM CERTEZA QUE DESEJA EXCLUIR OS REGISTROS DE GANHOS?\n");
    do {
        printf("Responda com S para SIM e N para NAO:\n");
        printf("COMANDO:");
        scanf(" %[^\n]", &resp);
    }while(validar_apagar(resp));

    printf("\n");

    if (resp == 'S' || resp == 's') {
        remove("ganhos_binario.txt");
        remove("ganhos_total.txt");
    }
}



int validar_apagar(char resp){
    if (resp == 'S'){
        return 0;
    }if (resp == 's'){
        return 0;
    }if (resp == 'N'){
        return 0;
    }if (resp == 'n')
        return 0;
    else{
        return 1;
    }

}

//int ganhos_visualizar (){
//    int i = 0;
//    char entrada[40];
//    printf("-----------------------------------------------------------------------\n");
//    printf("---------------------------VISUALIZAR GANHOS---------------------------\n");
//    printf("-----------------------------------------------------------------------\n");
//    printf("\n");
//
//    ganhos_entrada = fopen("ganhos_entrada.txt","r");
//
//    if (ganhos_entrada == NULL) {
//        printf("Erro na abertura do arquivo!\n");
//        printf("Nao eh possivel continuar esse programa...\n");
//        return 0;
//    }
//
//
//    while (fscanf(ganhos_entrada, "%s\n", entrada) != EOF) {
//        printf("%d. %s\n", i+1, entrada);
//        i += 1;
//    }
//
//
//    printf("\n");
//}

int ganhos_visualizar(){
    printf("-----------------------------------------------------------------------\n");
    printf("---------------------------VISUALIZAR GANHOS---------------------------\n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n");
    FILE* fp = fopen("ganhos_binario.txt","rb");
    if(fp == NULL){
        printf("Nao existe ganhos salvos\n");
        return 0;
        exit(1);
    }
    struct ganhos* aux = (struct ganhos*) malloc(sizeof(struct ganhos));
    while(fread(aux, sizeof(struct ganhos),1,fp)){
        printf("Descricao: %s\n",aux->descricao);
        printf("Valor da entrada: R$%.2f \n",aux->entrada);
        printf("Data da entrada: %d/%d/%d \n\n",aux->dia,aux->mes,aux->ano);
    }
    fclose(fp);
}

int gastos_registrar (){
//    float entrada_gastos;
//    char descricao_gastos[250];
//    int dia, mes, ano;
    float x;
    float aux;

    struct ganhos novo_gasto;

    printf("-----------------------------------------------------------------------\n");
    printf("---------------------------REGISTRAR GASTOS----------------------------\n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n");
    printf("ESCREVA UMA DESCRICAO:");
    scanf(" %[^\n]", novo_gasto.descricao);


    do {
        printf("DIGITE A DATA:\n");
        printf("DIA:");
        scanf("%d", &novo_gasto.dia);
        printf("MES:");
        scanf("%d", &novo_gasto.mes);
        printf("ANO:");
        scanf("%d", &novo_gasto.ano);
    }while(valida_data(novo_gasto.dia,novo_gasto.mes,novo_gasto.ano));

    printf("DIGITE O VALOR:");
    scanf("%f",&novo_gasto.entrada);

    x = novo_gasto.entrada;

    FILE* fp1 = fopen("gastos_total.txt","rb");
    fscanf(fp1,"%f",&gastos_total);
    fclose(fp1);


    FILE* fp2 = fopen("gastos_total.txt","wb");
    aux = gastos_total + x;
    fprintf(fp2,"%f",aux);
    fclose(fp2);


    salvar_gasto(&novo_gasto);
    printf(">>>>> GASTO REGISTRADO COM SUCESSO <<<<<\n\n");

//    gastos_entrada = fopen("gastos_entrada.txt","a");
//    fprintf(gastos_entrada,"%.2f\n",entrada_gastos);
//    fclose(gastos_entrada);
//
//    gastos_descricao = fopen("gastos_descricao.txt","a");
//    fprintf(gastos_descricao,"%s\n",descricao_gastos);
//    fclose(gastos_descricao);
//
//    gastos_data = fopen("gastos_data.txt","a");
//    fprintf(gastos_data,"%i/%i/%i\n",dia,mes,ano);
//    fclose(gastos_data);
//
//
//    printf("\n");
//    printf("- ENTRADA REGISTRADA COM SUCESSO!\n");
//    printf("\n");
//    //getch();


}


int gastos_apagar (){
    char resp;
    printf("-----------------------------------------------------------------------\n");
    printf("-----------------------------APAGAR GASTOS-----------------------------\n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n");
    printf("- TEM CERTEZA QUE DESEJA EXCLUIR OS REGISTROS DE GASTOS?\n");
    do {
        printf("Responda com S para SIM e N para NAO:\n");
        printf("COMANDO:");
        scanf(" %[^\n]", &resp);
    }while(validar_apagar(resp));

    printf("\n");

    if (resp == 'S' || resp == 's') {
        remove("gastos_binario.txt");
        remove("gastos_total.txt");
    }
}

//int gastos_visualizar(){
//    int i = 0;
//    char entrada[40];
//    printf("-----------------------------------------------------------------------\n");
//    printf("---------------------------VISUALIZAR GASTOS---------------------------\n");
//    printf("-----------------------------------------------------------------------\n");
//    printf("\n");
//
//    gastos_entrada = fopen("gastos_entrada.txt","r");
//
//    if (gastos_entrada == NULL) {
//        printf("Erro na abertura do arquivo!\n");
//        printf("Nao eh possivel continuar esse programa...\n");
//        return 0;
//    }
//
//
//    while (fscanf(gastos_entrada, "%s\n", entrada) != EOF) {
//        printf("%d. %s\n", i+1, entrada);
//        i += 1;
//    }
//
//    printf("\n");
//}

int gastos_visualizar(){
    printf("-----------------------------------------------------------------------\n");
    printf("---------------------------VISUALIZAR GASTOS---------------------------\n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n");

    FILE* fp = fopen("gastos_binario.txt","rb");
    if(fp == NULL){
        printf("Nao existe gastos salvos\n");
        return 0;
        exit(1);
    }
    struct gastos* aux = (struct gastos*) malloc(sizeof(struct gastos));
    while(fread(aux, sizeof(struct gastos),1,fp)){
        printf("Descricao: %s\n",aux->descricao);
        printf("Valor da entrada: R$%.2f \n",aux->entrada);
        printf("Data da entrada: %d/%d/%d \n\n",aux->dia,aux->mes,aux->ano);
    }
    fclose(fp);
}

void salvar_gasto(struct gastos* g) {
    FILE *fp = fopen("gastos_binario.txt", "ab");
    if (fp == NULL) {
        printf("Arquivo nao existe");
        exit(1);
    }
    fwrite(g, sizeof(struct gastos), 1, fp);
    fclose(fp);
}

void salvar_ganho(struct ganhos* g){
    FILE* fp = fopen("ganhos_binario.txt","ab");
    if(fp==NULL){
        printf("Arquivo nao existe");
        exit(1);
    }
    fwrite(g, sizeof(struct ganhos),1,fp);
    fclose(fp);

}


// VALIDAÇÕES

int valida_data(int dia, int mes, int ano) {
    if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)) //verifica se os numeros sao validos
    {
        if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) //verifica se o ano e bissexto
        {
            return 0;
        }
        if (dia <= 28 && mes == 2) //verifica o mes de feveireiro
        {
            return 0;
        }
        if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) //verifica os meses de 30 dias
        {
            return 0;
        }
        if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) //verifica os meses de 31 dias
        {
            return 0;
        }
        else
        {
            printf("DATA INVALIDA, TENTE NOVAMENTE.\n");
            return 1;
        }
    }
    else
    {
        printf("DATA INVALIDA, TENTE NOVAMENTE.\n");
        return 1;
    }
}

/*

REFERENCIAS:

VALIDA A DATA: https://www.vivaolinux.com.br/script/Funcao-para-validacao-de-datas

FLAVIUS: http://dontpad.com/flavius/programacao

 */

