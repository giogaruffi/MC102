/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 10b - DON'T PANIC - Part I */

 #include <stdio.h>
 #include <stdlib.h>

 /* Funcao responsavel pela transposicao das strips */
 int transp(int fim_prim, int fim_seg, int perm[]){
    int k, m = 1, aux[100], aux2[100];
    
    /* Aloca em um vetor auxiliar a parte correspondente ao intervalo entre o fim da primeira strip e o fim da segunda */
    for(k = 1; k + fim_prim <= fim_seg; k++){
        aux[k] = perm[fim_prim + k];
    }
    /* Aloca a parte correspondente a primeira strip */
    for(k = 1; k <= fim_prim; k++){
        aux2[k] = perm[k]; 
    }
    /* Transfere a parte entre o fim da primeira e o inicio da segunda strip */
    for(k = 1; k <= fim_seg - fim_prim; k++){
        perm[k] = aux[k];
    }
    /* Transfere a primeira strip */
    for(k = fim_seg - fim_prim + 1; k <= fim_seg; k++){
        perm[k] = aux2[m++];
    }     
 /* Retorna o valor do peso */
 return fim_seg;           
 }
 
 int main () {
    /* Declaracao de variaveis */
    int n, perm[100], i, l = 1, fim = 0, peso = 0, fim_prim = 1, fim_seg;
    
    /* Entrada do tamanho da permutacao */
    scanf("%d", &n);
    /* Zerar primeira posicao */
    perm[0] = 0;
    /* Leitura da permutacao */
    for(i = 1; i < n + 1; i++){
        scanf("%d", &perm[i]);
    }
    /* Impressao do vetor inicial */
    printf("(");
    for(i = 1; i < n; i++){
        printf("%d ", perm[i]);
    }
    printf("%d)\n", perm[i]);
    
    /* Verificacao se há ordenacao inicial */
    fim = 1;
    while(perm[fim+1] - perm[fim] == 1){
        fim++;
    }
    
    /* Loop de ordenacao */
    while(fim != n){
        /* Calculo da posicao de fim da primeira strip da permutacao */
        l = 1;
        fim_prim = l;
        while(perm[l+1] - perm[l] == 1){
            fim_prim = l+1;
            l++;
        }
	    /* Encontra posicao final da segunda strip a ser trocada */
	    fim_seg = fim_prim + 1;
	    while((perm[1] - perm[fim_seg] != 1)&&(perm[fim_seg + 1] - perm[fim_prim] != 1)){
	    	fim_seg++;
	    }
	    /* Testa se existe algum ndice final da primeira strip 
	    que resolve dois breakpoints ao mesmo tempo */
	    for(i = fim_prim + 1; i < fim_seg; i++){
	    	if((perm[fim_seg + 1] - perm[i] == 1) && (perm[1] - perm[fim_seg] == 1))
	    		fim_prim = i;
        }
	    /* Calculo do peso total */
        peso += transp(fim_prim,fim_seg,perm);
        
        /* Verificacao do fim da ordenacao */
        fim = 1;
        while(perm[fim+1] - perm[fim] == 1){
            fim++;
        }
        
        /* Impressao do vetor ao longo das permutacoes */
        printf("(");
        for(i = 1; i < n; i++){
            printf("%d ", perm[i]);
        }
        printf("%d)\n", perm[i]);
    }
       
    /* Impressao do peso total */
    printf("Peso: %d\n", peso);
  
    return 0;
 }
