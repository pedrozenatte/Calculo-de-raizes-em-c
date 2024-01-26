#include "Bisseccao.h"
#include "funcao.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ITERACOES 50 //Número de iterações para encontrar a raíz. OBS: Quanto maior o número de iterações, mais próxima da raíz será o resultado

//Estrutura
typedef struct funcao {
    int grau_funcao; //Armazena o grau da função
    float coeficientes_funcao[MAX_TAM_VETOR_COEFICIENTE]; //Armazena os coeficientes da função (EXCETO O CONSTANTE)
    int coeficiente_constante;
    double intervalo_encontro_raiz[2]; //O intervalo tem que ser fechado e contínuo em todos os pontos
} tipo_funcao;

//Função auxiliar para o encontro do valor médio entre dois intervalos
double encontra_valor_medio(double a, double b) {
    double medio = (a + b) / 2;
    return medio; 
}

//Função auxiliar para o encontro do valor da função em um determinado ponto
double funcao_determidado_ponto(double x, tipo_funcao *F, int grau, double valor, int indice_coef) { //Inicialmente o valor e o indice_coef começam em zero. O indice vai até o grau da função -1.
    //Estabelecendo um critério de parada
    if(grau == 0) {
        return (valor + F->coeficiente_constante);
    }
    else {
        valor = valor + (F->coeficientes_funcao[indice_coef] * (pow(x, grau)));
        grau--;
        indice_coef++;
        funcao_determidado_ponto(x, F, grau, valor, indice_coef);
    }
}

//Função para encontrar a raíz
double encontra_raiz(tipo_funcao *F) {
    //Variáveis importantes
    double medio = encontra_valor_medio(F->intervalo_encontro_raiz[0], F->intervalo_encontro_raiz[1]); //Encontrando um valor médio de acordo com o intervalo fornecido
    double raiz = medio; //A raíz é sempre associada ao valor médio
    double valores[3]; //Guarda os valores das funções nos intervalos e no ponto médio
    double sinal_multiplicacao[2]; //Guarda os valores das multiplicações nos pontos da funções com relação ao ponto médio
    
    //Vamos criar um loop até atingir o erro desejado 
    for(int i = 0; i < ITERACOES; i++) {
        //Encontrando os valores da função nos pontos do intervalo e no ponto médio
        valores[0] = funcao_determidado_ponto(F->intervalo_encontro_raiz[0], F, F->grau_funcao, 0, 0);
        valores[1] = funcao_determidado_ponto(F->intervalo_encontro_raiz[1], F, F->grau_funcao, 0, 0);
        valores[2] = funcao_determidado_ponto(medio, F, F->grau_funcao, 0, 0);

        //Analisando o sinal de acordo com o ponto médio
        sinal_multiplicacao[0] = valores[0] * valores[2]; //Dado o intervalo [A, B], estamos multiplicando "A" com o ponto médio entre [A, B]
        sinal_multiplicacao[1] = valores[1] * valores[2]; //Dado o intervalo [A, B], estamos multiplicando "B" com o ponto médio entre [A, B]
        //Testando o sinal e atualizando o intervalo de análise
        //OBS: Caso a multiplicação de um valor "A" com o ponto médio for menor que zero, significa que temos uma raíz entre tal valor e o ponto médio
        if(sinal_multiplicacao[0] < 0) { //Existe uma raíz entre o ponto A e o ponto médio, logo o intervalo de análise diminui para a esquerda
            F->intervalo_encontro_raiz[1] = medio;
            medio = encontra_valor_medio(F->intervalo_encontro_raiz[0], F->intervalo_encontro_raiz[1]);
            raiz = medio;
            
        }
        else if(sinal_multiplicacao[1] < 0) { //Existe uma raíz entre o ponto B e o ponto médio, logo o intervalo de análise diminui para a direita
            F->intervalo_encontro_raiz[0] = medio;
            medio = encontra_valor_medio(F->intervalo_encontro_raiz[0], F->intervalo_encontro_raiz[1]);
            raiz = medio;
        }
        else{
            printf("Problema no encontro da raiz\n");
        }
    }

    //A partir da saída do while, retornamos a raíz ou o ponto médio
    return raiz;
}