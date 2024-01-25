#ifndef BISSECCAO
#define BISSECCAO

//Estruturas
typedef struct funcao tipo_funcao;

//Funções
tipo_funcao *criar_funcao();
void destroi_funcao(tipo_funcao **F);
void guarda_funcao(tipo_funcao *F);
void imprime_informacoes(const tipo_funcao *F);


#endif