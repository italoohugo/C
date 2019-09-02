// http://dontpad.com/flavius/programacao/listaDinamica2c
// salvar com o nome lista.h

/* Tipos abstratos de dados */
typedef struct lista Lista;

/* Funcao cria lista
 * Cria e retorna uma lista vazia
 * */
Lista* lst_cria(void);

/* Funcao libera lista
 * Percorre a lista, elemento a elemento, liberando a memoria utilizada
 * */
void lst_libera(Lista *l);

/* Funcao insere na lista
 * Insere elemento no inicio da lista
 * */
Lista* lst_insere(Lista *l, int i);

/* Funcao retira da lista
 * Retira um determinado valor existente na lista
 * */
Lista* lst_retira(Lista *l, int v);

/* Funcao testa lista vazia
 * Retorna 1 se a list aestiver vazia e 0 caso contrario
 * */
int lst_vazia(Lista *l);

/* Funcao busca na lista
 * Busca um valor na lista e retorna um ponteiro para o elemento
 * ou NULL se o elemento nao for encontrado
 * */
Lista* lst_busca(Lista *l, int v);

/* Funcao imprime lista
 * Exibe a lista na tela
 * */
void lst_imprime(Lista *l);

/* Funcao imprime lista de forma recursiva
 * Exibe a lista na tela
 * */
void lst_imprime_rec(Lista *l);

