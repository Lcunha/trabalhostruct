#include <stdio.h>
#include "geolib.h"

int main() {
    TTela tela;
    int i, j;

    tela = criaTela();

    TVPontos pontos;
    TVLinhas linhas;
    TVQuadrados quadrados;
    TVTriangulos triangulos;

    criaPonto(&pontos, 0, 0,'l');
    criaPonto(&pontos, 1, 1,'i');
    criaPonto(&pontos, 2, 2, 'n');
    criaPonto(&pontos, 3, 3, 'h');
    criaPonto(&pontos, 4, 4,'a');

    atualizaTela(&tela, pontos, linhas, quadrados, triangulos);
    desenhaTela(tela);

    return 0;
}
