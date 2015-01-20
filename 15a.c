/**********************************************
* Nome: Giovani Garuffi Rondel                *
* RA: 155559                                  *
* Laboratorio 15a - Transferencia de Bitcoins *
***********************************************/

#include <stdio.h>

#define SUBTRACAO 0
#define SOMA 1
#define JUNTAR 2
#define MAX_OPERACOES 9

/* Funcao responsavel por realizar as operacoes */
int verifica(char verificacao[], int operacoes[]){
   int i, total = 0,aux_mult = 1,aux = 0,flag = 0;
   
   /* Percorre o vetor de operacoes no sentido oposto */
   for(i = MAX_OPERACOES-1; i >= 0; i--){
       /* Realiza soma */
       if(operacoes[i] == SOMA){
           if(flag){
               aux += verificacao[i]*aux_mult;
               flag = 0;
               total += aux;
           }else{
               total += verificacao[i];
           }
       /* Realiza subtracao */   
       }else if(operacoes[i] == SUBTRACAO){
           if(flag){
               aux += verificacao[i]*aux_mult;
               flag = 0;
               total -= aux;
           }else{
               total -= verificacao[i];
           }
       /* Une dois caracteres */
       }else if(operacoes[i] == JUNTAR){
           if(!flag){
               aux_mult = 1;
               aux = 0;
               flag = 1;
           }
           aux += verificacao[i]*aux_mult;
           aux_mult*=10;
       }
   }
   /* Retorna o valor calculado */
   return total;
}

/* Funcao que combina as operacoes */
void combinacao(char verificacao[], int atual, int resultado, int operacoes[], int *flag){
   int i;
   
   /* Caso ja haja uma combinacao feita, veja se ela resulta no numero desejado */
   if(atual == MAX_OPERACOES){
       if(verifica(verificacao, operacoes) == resultado)
           *flag = 1;
   }else if (!(*flag)){
       /* Realiza as combinacoes das operacoes */
       for(i = SUBTRACAO; i <= JUNTAR; i++){
           operacoes[atual] = i;   
           combinacao(verificacao,atual+1,resultado,operacoes,flag);
       }
   }
}

int main (){
   char verificacao[10]; 
   int resultado, operacoes[MAX_OPERACOES], i, flag = 0;
 
   /* Entrada da sequencia de numeros e o resultado desejado */
   scanf("%s", verificacao);
   scanf("%d", &resultado);

   /* Transformacao dos valores em inteiros */
   for(i = 0; i < 9; i++)
       verificacao[i] -= '0';
   /* Considera a operacao anterior ao primeiro caracter como soma */
   operacoes[0] = SOMA;
   /* Chamada das combinacoes */
   combinacao(verificacao,1,resultado,operacoes,&flag);
 
   /* Caso seja encontrada uma chave, a transacao foi aceita */
   if(flag)
       printf("Transferencia aceita\n");
   else
       printf("Transferencia abortada\n");
 
   return 0; 
}
