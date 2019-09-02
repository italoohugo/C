#include <stdio.h>
#include <string.h>

typedef struct aluno Aluno;

struct aluno{
    long int matricula;
    char nome[81];
    char curso[52];
    char email[41];
    char login[21];
    char status;
};

void preencheAluno(Aluno* int);
void exibeAluno(Aluno*, int);

int main(void){
    int total;
    char resp;
    Aluno fulano[10];
    printf("Cadastro de Alunos\n");
    total=0;
    do{
        preencheAluno(fulano, total);
        total++;
        printf("Deseja cadastrar mais alguem (s/n)?");
        scanf("%c, &resp");
    }while(resp=='s');
    printf("\n= = =Alunos Cadastrados = = =\n");
    for(int i=0;i<total;i++){
        exibeAluno(fulano,i);
    }
    return 0;
}

void preencheAluno(Aluno* al, int i){
    printf("Informe a matricula do aluno:");
    scanf("%ld", &al[i].matricula);
    printf("Informe o nome do aluno:");
    scanf(" %80[^\n]",al[i].nome);
    printf("Informe o curso do aluno:");
    scanf(" %50[^\n]",al[i].curso);
    printf("Informe o login do aluno:");
    scanf(" %20[^\n]",al[i].login);
    printf("Informe o email do aluno:");
    scanf(" %40[^\n]",al[i].email);
    al[i].status = 'm';
    getchar();
}

void exibeAluno(Aluno* al, int i){
    char situacao[20];
    printf("Matricula: %ld\n", al[i].matricula);
    printf("Nome do aluno: %s\n", al[i].nome);
    printf("Email: %s\n", ai[i].email);
    printf("Login do aluno(SIGAA): %s\n",a[i].login);
    printf("Curso: %s\n", al[i].curso);
    if(al[i].status =='m'){
        strcpy(situacao, "Matriculado");
    }else if(al[i].status=='t'){
        strcpy(situacao, "Trancado";)
    }else{
        strcpy(situacao, "Nao informada");
    }
    printf("Situacao do aluno: %s\n",situacao);
    printf("\n");

}
