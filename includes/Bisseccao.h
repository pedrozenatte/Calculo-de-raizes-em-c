#ifndef BISSECCAO
#define BISSECCAO

#include "funcao.h"

/*Esse método leva em conta um intervalo definido e contínuo de uma função, ou seja, é necessário saber
aproximadamente onde a raíz está, sendo uma raíz por vez. 
ATENÇÃO: Se no intervalo existir mais de uma raíz, ocorrerá um problema no encontro da raíz*/
double encontra_raiz(tipo_funcao *F);


#endif //BISSECCAO