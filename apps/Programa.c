#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Bisseccao.h"

int main() {

    tipo_funcao *F = criar_funcao();
    guarda_funcao(F);
    imprime_informacoes(F);


    return 0;
}