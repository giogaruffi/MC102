/* Nome: Giovani Garuffi Rondel
* RA: 155559
* Lab 08b - Processamento de imagens */

#include <stdio.h>
#include <string.h>

/* Definindo tamanho maximo das imagens */
#define MAX_TAM 400

/* Le uma imagem em formato PGM a partir da entrada padrao.
* Retorna 1 se a leitura for realmente de um arquivo PGM
* e 0 caso contrario.
* VOCE NAO DEVE ALTERAR ESTA FUNCAO                       */
int ler_pgm(int img[][MAX_TAM], int *W, int *H, int *MaxV,
           int *F, double *Px, double *Py) {
   char nome_formato[3];
   char c;
   int i,j;

   /* Le o formato da imagem. P2 indica o formato PGM */
   scanf("%s ", nome_formato);
   if (strcmp(nome_formato, "P2") != 0)
       return 0;

   /* Le o '#', que indica um comentario, e os numeros indicando
   * o filtro e o parametro, se houver */
   scanf("%[#]c", &c);
   scanf("%d", F);
   if (*F == 4) {
       scanf("%lf %lf", Px, Py);
   } 

   /* Le dimensoes e intensidade maxima da imagem */
   scanf("%d", W);
   scanf("%d", H);
   scanf("%d", MaxV);

   /* Le o valor de cada pixel da imagem */
   for (i = 0; i < (*H); i++) {
       for (j = 0; j < (*W); j++) {
           scanf("%d", &img[i][j]);
       }
   }

   return 1;
}

/* Escreve a imagem em formato pgm na saida padrao 
* VOCE NAO DEVE ALTERAR ESTA FUNCAO               */
void escrever_pgm(int img[][MAX_TAM], int W, int H, int MaxV) {
   int i, j;

   /* Escreve os atributos da imagem */
   /* Tipo da imagem: P2 significa pgm*/
   printf("P2\n");
   /* Dimensoes e intensidade maxima da imagem */
   printf("%d %d %d\n", W, H, MaxV);

   /* Escreve os pixels da imagem */
   for (i = 0; i < H; i++) {
       printf("%d", img[i][0]);
       for (j = 1; j < W; j++) {
           printf(" %d", img[i][j]);
       }
       printf("\n");
   }
}

/* Negativo */
void negativo(int img[][MAX_TAM], int W, int H, int MaxV) {
   int i, j;
   
   /* Transformar cada pixel em seu oposto, ou seja, subtrair o seu valor do maximo dado */    
   for( i = 0; i < H; i++ ){
       for( j = 0; j < W; j++){
           img[i][j] = MaxV - img[i][j];
       }
   }
   
  return; 
}

/* Rotacao de 180 graus */
void rotacao180(int img[][MAX_TAM], int W, int H) {
   int i, j, aux;
   
   /* Trocar as posicoes dos pixels na horizontal, em primeiro lugar */    
   for( i = 0; i < H; i++ ){
       for( j = 0; j < W/2; j++ ){ 
           aux = img[i][j];
           img[i][j] = img[i][W - 1 - j];
           img[i][W - 1 - j] = aux;
       }
   }
   
   /* Trocar as posicoes dos pixels na vertical, girando-os ao todo em 180 graus */
   for( j = 0; j < W; j++ ){
       for( i = 0; i < H/2; i++ ){ 
           aux = img[i][j];
           img[i][j] = img[H - 1 - i][j];
           img[H - 1 - i][j] = aux;
       }
   }
  
   return;
}

/* Deteccao de bordas */
void detectaBorda(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j, result[MAX_TAM][MAX_TAM];
   
    /* Calculo da intensidade da posicao apos o filtro em uma matriz auxiliar
    * Preservar valores originais para os proximos calculos */    
    for( i = 1; i < H - 1; i++ ){
        for ( j = 1; j < W - 1; j++ ){
            result[i][j] = (-1 * img[i - 1][j - 1]) + (-4 * img[i - 1][j]) + (-1 * img[i - 1][j + 1]) + (-4 * img[i][j - 1]) + (20 * img[i][j]) + (-4 * img[i][j + 1]) + (-1 * img[i + 1][j - 1]) + (-4 * img[i + 1][j]) + (-1 * img[i + 1][j + 1]);
            if( result[i][j] > MaxV ){
                result[i][j] = MaxV;
            }
            if( result[i][j] < 0 ){
                result[i][j] = 0;
            }
        }
    }
   
    /* Alocacao dos valores calculados apos o filtro de volta para a matriz original */
    for( i = 1; i < H - 1; i++ ){
        for ( j = 1; j < W - 1; j++ ){
            img[i][j] = result[i][j];
        }   
    }
    
    return;
}

/* Cisalhamento */
void cisalhamento(int img[][MAX_TAM], int W, int H, double Px, double Py) {  
    int x, y, result[MAX_TAM][MAX_TAM];
    double x_apos, y_apos, resto;
    
    /* Alteracao dos valores da matriz auxiliar para a verificacao de falta de mapeamento na imagem final */
    for( y = 0; y < H; y++ ){
        for( x = 0; x < W; x++){
            result[y][x] = -1;
        }
    }
    
    /* Alocacao das novas posicoes calculadas para a matriz auxiliar, assim como o arredondamento desses valores para baixo */
    for( y = 0; y < H; y++ ){
        for( x = 0; x < W; x++){
            x_apos = x + (Px * y);
            resto = x_apos - (int)x_apos;
            if(resto){
                x_apos -= resto;
            }
            y_apos = y + (Py * x);
            resto = y_apos - (int)y_apos;
            if(resto){
                y_apos -= resto;
            }
            if ((x_apos < W) && (y_apos < H)){
                result[(int)y_apos][(int)x_apos] = img[y][x];
            }
        }
    }
    
    /* Transferencia dos valores da matriz auxiliar para a matriz final resultante, com a alteracao dos pixels nao mapeados para 0 */
    for( y = 0; y < H; y++ ){
        for( x = 0; x < W; x++){
            if(result[y][x] == -1){
                img[y][x] = 0;
            } else {
            img[y][x] = result[y][x];
            }
        }
    }
    
    return;
}

/* VOCE NAO DEVE ALTERAR A FUNCAO PRINCIPAL */
int main() {
   /* Matriz que armazena os pixels da imagem */
   int img[MAX_TAM][MAX_TAM]; 
   /* Atributos da imagem */
   int W, H, MaxV;
   /* Identificador do filtro a ser utilizado */
   int F;
   /* Parametro a ser passado para o cisalhamento */
   double Px, Py;

   /* Le a imagem */
   if (ler_pgm(img, &W, &H, &MaxV, &F, &Px, &Py) != 1) {
       printf("Error: nao foi possivel ler a imagem\n");
       return 0;
   }

   /* Seleciona o filtro */
   switch (F) {
       case 1:
           negativo(img, W, H, MaxV);
           break;
       case 2:
           rotacao180(img, W, H);
           break;
       case 3:
           detectaBorda(img, W, H, MaxV);
           break;
       case 4:
           cisalhamento(img, W, H, Px, Py);
           break;
   }

   /* Escreve a imagem */
   escrever_pgm(img, W, H, MaxV);

   return 0;
}
