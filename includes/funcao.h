#ifndef FUNCAO
#define FUNCAO

#define MAX_TAM_VETOR_COEFICIENTE 10 //Tamanho do vetor que guarda os coeficientes da função

//Estruturas
typedef struct funcao tipo_funcao;

//Funções
tipo_funcao *criar_funcao();
void destroi_funcao(tipo_funcao **F);
void guarda_funcao(tipo_funcao *F);
void imprime_informacoes(const tipo_funcao *F);

#endif // FUNCAO
