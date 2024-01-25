#include "Bisseccao.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_TAM_VETOR_COEFICIENTE 10 //Tamanho do vetor que guarda os coeficientes da função
#define MAX_TAM_VETOR_EXPOENTE 10 //Tamanho do vetor que guarda os expoentes da função
#define ERRO 10e-4 //Erro para o encontro da raíz. OBS: Quanto menor o número, mais perto do valor real será a raíz

//Estrutura
typedef struct funcao {
    int grau_funcao; //Armazena o grau da função
    float coeficientes_funcao[MAX_TAM_VETOR_COEFICIENTE]; //Armazena os coeficientes da função
    int expoentes_funcao[MAX_TAM_VETOR_EXPOENTE]; //Armazena os expoentes da funcao
    int coeficiente_constante;
} tipo_funcao;

//Funções de criação e destruição
tipo_funcao *criar_funcao() {
    tipo_funcao *F = (tipo_funcao *) calloc(1, sizeof(tipo_funcao));

    return F;
}

void destroi_funcao(tipo_funcao **F) {
    free(*F);
    *F = NULL;
}

//Funções especiais
void guarda_funcao(tipo_funcao *F) {
    printf("Grau da Funcao: ");
    scanf("%d", &F->grau_funcao);
    fflush; //Boa prática de programação para limpar o buffer do teclado e evitar erros advindos do scanf

    //Guardando as informações dentro dos vetores
    for(int i = 1; i <= F->grau_funcao; i++) {
        printf("%d° Coeficiente: ", i);
        scanf("%f", &F->coeficientes_funcao[i-1]);
        fflush;

        printf("%d° Expoente: ", i);
        scanf("%d", &F->expoentes_funcao[i-1]);
        fflush;
    }
    printf("Coeficiente constante: ");
    scanf("%d", &F->coeficiente_constante);
    printf("\n");
}

void imprime_informacoes(const tipo_funcao *F) {
    printf("Grau da funcao: %d\n", F->grau_funcao);
    
    for(int i = 0; i < F->grau_funcao; i++) {
        printf("%d° Coeficiente: %.2f\n", i+1, F->coeficientes_funcao[i]);
        printf("%d° Expoente: %d\n", i+1, F->expoentes_funcao[i]);
    }
    printf("Coeficiente constante: %d\n\n", F->coeficiente_constante);
    
    printf("Formato de funcao: ");
    //Formato de função
    for(int i = 0; i < F->grau_funcao; i++) {
        printf("%.2fX^%d + ", F->coeficientes_funcao[i], F->expoentes_funcao[i]);
    }
    printf("%d\n", F->coeficiente_constante);
}