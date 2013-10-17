#include "geolib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, i2, j2;

	TTela tela = criaTela();

	TVPontos pontos;
	TVLinhas linhas;
	TVQuadrados quadrados;
	TVTriangulos triangulos;
	char c;

	int x1, x2, y1, y2, posicao;
    char simbol;

	do{
		system("cls");
		printf("Coordenadas de Tela: Y:[0..%d] x X:[0..%d]", TAM_X-1, TAM_Y-1);
		printf("\n");
		printf("\n");
		printf("Selecione uma opcao:");
		printf("\n");
		printf("\n");
		printf("\n 1 - Incluir Ponto");
		printf("\n 2 - Excluir Ponto");
		printf("\n 3 - Incluir Linha");
		printf("\n 4 - Excluir Linha");
		printf("\n 5 - Incluir Triangulo");
		printf("\n 6 - Excluir Triangulo");
		printf("\n 7 - Incluir Retangulo");
		printf("\n 8 - Excluir Retangulo");
		printf("\n 9 - Exibir Grafico");
		printf("\n 10 - Sair");
		printf("\n");
		int opc;
		scanf("%d", &opc);
		switch( opc ){
			case 1:
				printf("Digite as coordenadas (x, y): ");
				scanf("%d %d", &x1, &y1);
				printf("Infome o simbolo a ser usado: ");
				scanf(" %c", &simbol);
				criaPonto(&pontos, x1, y1, simbol);
				atualizaTela(&tela, pontos, linhas, quadrados, triangulos);
				break;
			case 2:
				printf("Digite a posicao do elemento no vetor a ser removido: ");
				scanf("%d", &posicao);
				removePonto(&pontos, posicao);
				atualizaTela(&tela, pontos, linhas, quadrados, triangulos);
				break;
			case 3:
				printf("Digite as coordenadas de origem (x1, y1): ");
				scanf("%d %d", &x1, &y1);
				printf("Digite as coordenadas de destino (x2, y2): ");
				scanf("%d %d", &x2, &y2);
				printf("Infome o simbolo a ser usado: ");
				scanf(" %c", &simbol);
				criaLinha(&linhas, x1, y1, x2, y2, simbol);
				atualizaTela(&tela, pontos, linhas, quadrados, triangulos);
				break;
			case 4:
				break;
			case 5:
			    criaTriangulo(&triangulos, 10, 3, 5, 9, 10, 20, '*');
				atualizaTela(&tela, pontos, linhas, quadrados, triangulos);
				break;
			case 6:
				break;
			case 7:
			    criaQuadrado(&quadrados, 5, 5, 10, 10, 'x');
				atualizaTela(&tela, pontos, linhas, quadrados, triangulos);
				break;
			case 8:
				break;

			case 9:
				desenhaTela(tela);
				printf("\n\n");
				system("PAUSE");
				break;
			default:


				return 0;
				break;
		}
		// Atenção: Coordenada x diz respeito às linhas, e y às colunas
		// Não é como no plano cartesiano!
	}while( 1 );
}
