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

    // Aten��o: Coordenada x diz respeito �s linhas, e y �s colunas
    // N�o � como no plano cartesiano!

    criaPonto(&pontos, 0, 0,'x');
    criaPonto(&pontos, 7, 3,'o');
    criaPonto(&pontos, 5, 5, '+');

    criaLinha(&linhas, 17, 15, 10, 5, '*');

    atualizaTela(&tela, pontos, linhas, quadrados, triangulos);
    desenhaTela(tela);

    return 0;
}
