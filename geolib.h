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
    if (pontos->quantidade == 5) {
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

void plotaPonto(TTela *tela, TPonto ponto, char psimbolo) {
    tela->grid[ponto.x][ponto.y] = ponto.psimbolo;
}


void atualizaTela(TTela *tela, TVPontos pontos, TVLinhas linhas, TVQuadrados quadrados, TVTriangulos triangulos) {
    int i;

    for(i=0; i<pontos.quantidade; i++) {
        TPonto ponto = pontos.elementos[i];
        plotaPonto(tela, pontos.elementos[i], pontos.elementos[i].psimbolo);
    }
}
