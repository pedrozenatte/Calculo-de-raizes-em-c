#ifndef FUNCAO
#define FUNCAO

#define MAX_TAM_VETOR_COEFICIENTE 10 //Tamanho do vetor que guarda os coeficientes da função

//Estruturas
typedef struct funcao tipo_funcao;

//Funções
tipo_funcao *criar_funcao(); //Cria a função 
void destroi_funcao(tipo_funcao **F); //Deleta a função
void guarda_funcao(tipo_funcao *F); //Permite que o usuária forneça as informações da função
/*A função acima (guarda_funcao(tipo_funcao *F)), apenas funcionará como deve caso a expressão matemática esteja
passada na seguinte forma: AX^y + BX^y-1 + CX^y-2... + Constante. CUIDADO COM CASOS COMO: X^3 + X + 4, por
exemplo, uma vez que o coeficiente B equivale a ZERO.
Além disso, o intervalo a ser passado precisa estar em ordem crescente, isto é, do menor para o maior*/
void imprime_informacoes(const tipo_funcao *F);

#endif // FUNCAO
