#define TAM_X 20
#define TAM_Y 40
#include <stdio.h>

struct TTela {
    char grid[TAM_X][TAM_Y];
};

struct TPonto {
    int x, y;
    char psimbolo;
};

struct TVPontos {
    TPonto elementos[5];
    int quantidade;
    TVPontos()
    { quantidade = 0; }
};

struct TLinha {
    int x1, y1; //Origem
    int x2, y2; //Destino
    char psimbolo;
};

struct TVLinhas {
    TLinha elementos[5];
    int quantidade;
    TVLinhas()
    { quantidade = 0; }
};

struct TQuadrado {
    int x1, y1; //Canto superior esquerdo
    int x2, y2; //Canto inferior direito
    char psimbolo;
};

struct TVQuadrados {
    TQuadrado elementos[5];
    int quantidade;
    TVQuadrados()
    { quantidade = 0; }
};

struct TTriangulo {
    int x1, y1; //Vértice 1
    int x2, y2; //Vértice 2
    int x3, y3; //Vértice 3
    char psimbolo;
};

struct TVTriangulos {
    TTriangulo elementos[5];
    int quantidade;
    TVTriangulos()
    { quantidade = 0; }
};


TTela criaTela() {
    int i, j;
    TTela tela;

    for (i=0; i<TAM_X; i++)
        for (j=0; j<TAM_Y; j++)
            tela.grid[i][j] = ' ';

    return tela;
}

void desenhaTela(TTela tela) {
    int i, j;
    printf(" ");
    for (i=0; i<TAM_Y; i++) {
        printf("%d",i%10);
    }

    printf("\n");

    for (i=0; i<TAM_X; i++) {
        printf("%d", i%10);
        for (j=0; j<TAM_Y; j++) {
            printf("%c", tela.grid[i][j]);
        }
        printf("\n");
    }
}

void criaPonto(TVPontos *pontos, int x, int y, char psimbolo) {
    if (pontos->quantidade >= 5) {
        printf("Quantidade máxima de pontos já foi atingida!");
        return;
    }

    TPonto ponto;
    ponto.x = x;
    ponto.y = y;
    ponto.psimbolo = psimbolo;

    pontos->elementos[pontos->quantidade] = ponto;
    pontos->quantidade += 1;
}

// A remoção é feita pela posição, e vai ser igual para todas as formas geométricas
void removePonto(TVPontos *pontos, int posicao) {
    printf("aqui");
    if (posicao >= pontos->quantidade) {
        printf("Nao existe um elemento enssa posicao!");
        return;
    }

    if (pontos->quantidade == 1) {
        pontos->quantidade = 0;
    } else {
        pontos->elementos[posicao] = pontos->elementos[pontos->quantidade-1];
        pontos->quantidade -= 1;
    }
}

void criaLinha(TVLinhas *linhas, int x1, int y1, int x2, int y2, char psimbolo) {
    if (linhas->quantidade >= 5) {
        printf("Quantidade máxima de linhas já foi atingida!");
        return;
    }

    TLinha linha;
    linha.x1 = x1;
    linha.y1 = y1;
    linha.x2 = x2;
    linha.y2 = y2;
    linha.psimbolo = psimbolo;

    linhas->elementos[linhas->quantidade] = linha;
    linhas->quantidade += 1;
}

void criaTriangulo(TVTriangulos *triangulos, int x1, int y1, int x2, int y2, int x3, int y3, char psimbolo) {
     if (triangulos->quantidade >= 5) {
        printf("Quantidade maxima de triangulos ja foi atingida!");
        return;
     }

     TTriangulo triangulo;
     triangulo.x1 = x1;
     triangulo.y1 = y1;
     triangulo.x2 = x2;
     triangulo.y2 = y2;
     triangulo.x3 = x3;
     triangulo.y3 = y3;
     triangulo.psimbolo = psimbolo;

     triangulos->elementos[triangulos->quantidade] = triangulo;
     triangulos->quantidade += 1;
}

void criaQuadrado(TVQuadrados *quadrados, int x1, int y1, int x2, int y2, char psimbolo) {
    if (quadrados->quantidade >= 5) {
        printf("Quantidade máxima de linhas já foi atingida!");
        return;
    }

    if ((x1 != x2) && (y1 != y2)) {
    TQuadrado quadrado;
    quadrado.x1 = x1;
    quadrado.y1 = y1;
    quadrado.x2 = x2;
    quadrado.y2 = y2;
    quadrado.psimbolo = psimbolo;

    quadrados->elementos[quadrados->quantidade] = quadrado;
    quadrados->quantidade += 1;
    }

    else
        printf("Nao e possivel formar um retangulo com esses pontos.");
}

void plotaPonto(TTela *tela, TPonto ponto) {
    tela->grid[ponto.x][ponto.y] = ponto.psimbolo;
}

void plotaLinha(TTela *tela, TLinha linha) {
    int x1 = linha.x1;
    int y1 = linha.y1;
	int x2 = linha.x2;
    int y2 = linha.y2;
    int nx, ny, m, fimx, fimy, incx = 1;

    if ( x1 > x2 ) {
        nx = x2;
        ny = y2;
        fimx = x1;
        m = (y2-y1)/(x2-x1);
    } else if ( x1 < x2 ) {
		nx = x1;
		ny = y1;
		fimx = x2;
		m = (y2-y1)/(x2-x1);
	} else {
        nx = x1+1;
        fimx = x2;
        incx = 0;
        m = 1;

        if ( y1 > y2 ){
			ny = y2;
			fimy = y1;
        } else {
			ny = y1;
			fimy = y2;;
        }
    }

    while ( nx <= fimx || (ny <= fimy && x1 == x2) ){
        TPonto ponto;
        ponto.x = nx;
        ponto.y = ny;
        ponto.psimbolo = linha.psimbolo;
        plotaPonto(tela, ponto);

        printf("%d %d - ",ny, fimy);

        nx += incx;
        ny += m;
    }

}

void plotaTriangulo (TTela *tela, TTriangulo triangulo) {
     int x1 = triangulo.x1;
     int x2 = triangulo.x2;
     int x3 = triangulo.x3;
     int y1 = triangulo.y1;
     int y2 = triangulo.y2;
     int y3 = triangulo.y3;
     char psimbolo = triangulo.psimbolo;

     TLinha linha1;
     linha1.x1 = x1;
     linha1.x2 = x2;
     linha1.y1 = y1;
     linha1.y2 = y2;
     linha1.psimbolo = psimbolo;
     plotaLinha(tela, linha1);

     TLinha linha2;
     linha2.x1 = x2;
     linha2.x2 = x3;
     linha2.y1 = y2;
     linha2.y2 = y3;
     linha2.psimbolo = psimbolo;
     plotaLinha(tela, linha2);

     TLinha linha3;
     linha3.x1 = x1;
     linha3.x2 = x3;
     linha3.y1 = y1;
     linha3.y2 = y3;
     linha3.psimbolo = psimbolo;
     plotaLinha(tela, linha3);
}

void plotaQuadrado (TTela *tela, TQuadrado quadrado) {
     int x1 = quadrado.x1;
     int x2 = quadrado.x2;
     int y1 = quadrado.y1;
     int y2 = quadrado.y2;
     char psimbolo = quadrado.psimbolo;
     int nx1, nx2, ny1, ny2, mx, my;

             TLinha linha1;
             linha1.x1 = x1-1;
             linha1.x2 = x1-1;
             linha1.y1 = y1;
             linha1.y2 = y2;
             linha1.psimbolo = psimbolo;
             plotaLinha(tela, linha1);

             TLinha linha2;
             linha2.x1 = x1;
             linha2.x2 = x2;
             linha2.y1 = y1;
             linha2.y2 = y1;
             linha2.psimbolo = psimbolo;
             plotaLinha(tela, linha2);

             TLinha linha3;
             linha3.x1 = x2-1;
             linha3.x2 = x2-1;
             linha3.y1 = y1;
             linha3.y2 = y2;
             linha3.psimbolo = psimbolo;
             plotaLinha(tela, linha3);

             TLinha linha4;
             linha4.x1 = x1;
             linha4.x2 = x2;
             linha4.y1 = y2;
             linha4.y2 = y2;
             linha4.psimbolo = psimbolo;
             plotaLinha(tela, linha4);


}

void atualizaTela(TTela *tela, TVPontos pontos, TVLinhas linhas, TVQuadrados quadrados, TVTriangulos triangulos) {
    int i;

    *tela = criaTela();
    for(i=0; i<pontos.quantidade; i++) {
        TPonto ponto = pontos.elementos[i];
        plotaPonto(tela, pontos.elementos[i]);
    }

    for(i=0; i<linhas.quantidade; i++) {
        TLinha linha = linhas.elementos[i];
        plotaLinha(tela, linhas.elementos[i]);
    }

    for(i=0; i<quadrados.quantidade; i++) {
        TQuadrado quadrado = quadrados.elementos[i];
        plotaQuadrado(tela, quadrados.elementos[i]);
    }

    for(i=0; i<triangulos.quantidade; i++) {
        TTriangulo triangulo = triangulos.elementos[i];
        plotaTriangulo(tela, triangulos.elementos[i]);
    }
}
