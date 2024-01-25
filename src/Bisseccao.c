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
    float coeficiente_funcao[MAX_TAM_VETOR_COEFICIENTE]; //Armazena os coeficientes da função
    int expoente_funcao[MAX_TAM_VETOR_EXPOENTE]; //Armazena os expoentes da funcao
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


