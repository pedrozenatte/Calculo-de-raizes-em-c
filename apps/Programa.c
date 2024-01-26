#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Funcao.h"
#include "Bisseccao.h"

int main() {

    tipo_funcao *F = criar_funcao();
    guarda_funcao(F);
    imprime_informacoes(F);
    double raiz = encontra_raiz(F);
    printf("Raiz final = %.20lf\n", raiz);
    return 0;
}