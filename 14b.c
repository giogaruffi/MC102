/**********************************
* Nome: Giovani Garuffi Rondel    *
* RA: 155559                      *
* Lab14b - Liber8                 *
***********************************/

#include <stdio.h>

/* Funcao responsavel por efetuar as explosoes */
void explosao(char area[][51], int linhas, int colunas, int bomb_x, int bomb_y, 
			  char bomba){
	/* Declaracao de variaveis auxiliares */
	int raio, i, j, aux_bomba, ini_horiz, ini_vert;

	/* Calculo do raio de alcance da explosao */
	raio = bomba - 48;

	/* Calculo do inicio da explosao para nao passar dos limites da matriz */
	ini_horiz = bomb_x - raio;
	if(ini_horiz < 0)
		ini_horiz = 0;
	ini_vert = bomb_y - raio;
	if(ini_vert < 0)
		ini_vert = 0;

	/* Percorrimento da area de explosao da bomba */
	for(i = ini_horiz; (i <= bomb_x + raio) && i < linhas; i++){
		for(j = ini_vert; (j <= bomb_y + raio) && j < colunas; j++){
			/* Caso encontre um valor numerico (bomba), efetue sua explosao */
			if(area[i][j] >= '1' && area[i][j] <= '9'){
				aux_bomba = area[i][j];
				area[i][j] = 'B';
				explosao(area,linhas,colunas,i,j,aux_bomba);
			}
			/* Caso seja um ponto vazio, explodir e transformar em 'x' */
			if(area[i][j] == '.'){
				area[i][j] = 'x';
			}
		}
	}
}

int main() {
	/* Declaracao da area de explosao, seus extremos e coordenadas da bomba */
	char area[50][51]; 
	int linhas, colunas, bomb_x, bomb_y, i;

	/* Leitura dos valores de extremos e da primeira bomba a ser acionada */
	scanf("%d %d", &linhas, &colunas);
	scanf("%d %d", &bomb_x, &bomb_y);

	/* Leitura da area de explosao */
	for (i = 0; i < linhas; i++){
		scanf("%s", area[i]);
	}

	/* Chamada da funcao recursiva de explosao */
	explosao(area, linhas, colunas, bomb_x-1, bomb_y-1, area[bomb_x-1][bomb_y-1]);

	/* Impressao da area apos explosoes */
	for (i = 0; i < linhas; i++){
		printf("%s\n", area[i]);
	}

	return 0;
}
