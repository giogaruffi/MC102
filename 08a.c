/* Nome: Giovani Garuffi Rondel
* RA: 155559
* Lab 08a - Amigos de amigos */

#include <stdio.h>

/* definir tamanho maximo da matriz de amizades */
#define MATRIZ 100

int main () {
   /* Declaracao de variaveis */
   int N, U, M[MATRIZ][MATRIZ], i, j, encontrado = 0, inicio = 0;
   
   /* Entrada do tamanho da matriz e da posicao do usuario */
   scanf("%d %d", &N, &U);
   
   /* Entrada da matriz de amizades */
   for( i = 0; i < N; i++ ){
       for ( j = 0; j < N; j++ ){
           scanf("%d", &M[i][j]);
       }
   }
   
   /* Verificacao da existencia de amigos dos amigos do usuario e sua sugestao */           
   for( j = 0; j < N; j++ ){
       if ( !M[U][j] ){
           encontrado = 0;
           for ( i = 0; i < N && !encontrado; i++ ){
               if ( M[i][j] && M[U][i] ){
                   if (!inicio){
                       printf("Sugestao de amigos:");
                   }
                   inicio = 1;
                   encontrado = 1;
                   printf(" %d", j);
               }
           }    
       }
   }
   
   /* Retorno caso nao forem encontrados amigos de amigos */
   if(!inicio){
       printf("Sem sugestao de novos amigos\n");
   }else{
       printf("\n");
   }
         
   return 0;
}
