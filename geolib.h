#define TAM_X 20
#define TAM_Y 40

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

    for (i=0; i<TAM_X; i++) {
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


void plotaPonto(TTela *tela, TPonto ponto) {
    tela->grid[ponto.x][ponto.y] = ponto.psimbolo;
}

void plotaLinha(TTela *tela, TLinha linha) {
    int x1 = linha.x1;
    int x2 = linha.x2;
    int y1 = linha.y1;
    int y2 = linha.y2;
    int nx, ny;
    int m;
    int direcao;
    int fimx, fimy;

    if (x1 > x2) {
        nx = x2;
        fimx = x1;
    } else {
        nx = x1;
        fimx = x2;
    }

    if (y1 < y2) {
        ny = y1;
        fimy = y2;
    } else {
        ny = y2;
        fimy = y1;
    }

    if (x1 == x2) {
        m = y2-y1;
    } else {
        m = (y2-y1)/(x2-x1);
    }

    while (nx <= fimx) {
        TPonto ponto;
        ponto.x = nx;
        ponto.y = ny;
        ponto.psimbolo = linha.psimbolo;
        plotaPonto(tela, ponto);

        nx += 1;
        printf("%d+%d ", ny, m);
        ny += m;

    }
}

void atualizaTela(TTela *tela, TVPontos pontos, TVLinhas linhas, TVQuadrados quadrados, TVTriangulos triangulos) {
    int i;

    for(i=0; i<pontos.quantidade; i++) {
        TPonto ponto = pontos.elementos[i];
        plotaPonto(tela, pontos.elementos[i]);
    }

    for(i=0; i<linhas.quantidade; i++) {
        TLinha linha = linhas.elementos[i];
        plotaLinha(tela, linhas.elementos[i]);
    }
}
