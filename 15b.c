/***********************************
 * Nome: Giovani Garuffi Rondel    *
 * RA: 155559                      *
 * Lab 10b - DON'T PANIC - Part II *
 ***********************************/

 #include <stdio.h>
 #include <stdlib.h>

 /* Prototipos de funcoes utilizadas */
 int limitante_inferior(int perm[], int n);
 void peso_minimo(int perm[], int n, int peso_atual, int *peso_min, int lim_inf);
 int limitante_superior(int perm[], int n);
 int checa_ordenacao(int perm[], int n);

/* Funcao que checa se a sequencia esta ordenada */
 int checa_ordenacao(int perm[], int n){
    int i = 0;

    /* Checa se a sequencia ja esta ordenada */
    while(perm[i+1] - perm[i] == 1 && i < n - 1){
        i++;
    }
    /* Caso a contagem seja igual ao numero de elementos, retorne 1 */
    if(i == n - 1){
        return 1;
    }
    
    return 0;
}

 /* Funcao responsavel pela transposicao das strips */
 void transp(int fim_prim, int fim_seg, int perm[]){
    int k, aux[100], aux2[100];

    /* Aloca a parte correspondente a primeira strip */
    for(k = 0; k < fim_prim + 1; k++){
        aux[k] = perm[k]; 
    }
    /* Aloca em um vetor auxiliar a parte correspondente ao intervalo entre o fim da primeira strip e o fim da segunda */
    for(k = 0; k + fim_prim < fim_seg; k++){
        aux2[k] = perm[fim_prim + k + 1];
    }
    /* Transfere a parte entre o fim da primeira e o inicio da segunda strip */
    for(k = 0; k + fim_prim < fim_seg; k++){
        perm[k] = aux2[k];
    }
    /* Transfere a primeira strip */
    for(k = 0; k < fim_prim + 1; k++){
        perm[fim_seg - fim_prim + k] = aux[k];
    }
 }

 /* Calculo do limitante inferior */
 int limitante_inferior(int perm[], int n){
    int i = 0, maior = 0;

    /* Procura o elemento de maior valor da sequencia que nao esta em sua posicao correta */
    for(i = 0; i < n; i++){
        /* Compara se o indice eh o maior e se nao esta ordenado */
        if(perm[i] > maior && perm[i] != i + 1){
            maior = perm[i];
        }
    }
    /* Retorna o maior elemento nao ordenado */
    return maior;
 }

 void peso_minimo(int perm[], int n, int peso_atual, int *peso_min, int lim_inf){
    int i, j, k, aux_perm[100];

    /* Caso o vetor esteja ordenado */
    if(checa_ordenacao(perm, n)){
        /* Caso o peso atual seja menor do que o atual peso minimo, trocar os valores */
        if(peso_atual < *peso_min){
            *peso_min = peso_atual;
        }
    /* Caso contrario (sequencia ainda nao ordenada) */
    } else {
        /* Explora todas as possibiliades de primeira e segunda strip */
        for (i = 0; i < n - 1; i++){
            for (j = i + 1; j < n;  j++){
                /* Aloca em um auxiliar os valores atuais do vetor */
                for(k = 0; k < n; k++)
                    aux_perm[k] = perm[k];

                /* Calcula o novo limitante inferior */
                lim_inf = limitante_inferior(aux_perm, n);
                /* Checa se a soma do peso atual e o limitante inferior 
                   nao ultrapassam o peso minimo atual */
                if(*peso_min - peso_atual >= lim_inf){
                    /* Realiza a transposicao no vetor auxiliar */
                    transp(i, j, aux_perm);
                    /* Chama a recursao com a soma do novo peso e com o auxiliar como parametro */
                    peso_minimo(aux_perm, n, peso_atual + j + 1, peso_min, lim_inf);
                }
            }
        }
    }
 }
 
 int limitante_superior(int perm[], int n){
    int fim_prim, fim_seg, i;

    /* Calculo da posicao de fim da primeira strip da permutacao */
    fim_prim = 0;
    while(perm[fim_prim+1] - perm[fim_prim] == 1 && fim_prim < n){
        fim_prim++;
    }
    /* Encontra posicao final da segunda strip a ser trocada */
    fim_seg = fim_prim + 1;
    while((perm[0] - perm[fim_seg] != 1)&&(perm[fim_seg + 1] - perm[fim_prim] != 1)){
        fim_seg++;
    }
    /* Testa se existe algum indice final da primeira strip 
    que resolve dois breakpoints ao mesmo tempo */
    for(i = fim_prim + 1; i < fim_seg; i++){
        if((perm[fim_seg + 1] - perm[i] == 1) && (perm[0] - perm[fim_seg] == 1))
            fim_prim = i;
    }
    /* Traspoe as strips */
    transp(fim_prim,fim_seg,perm);

    /* Retorna o peso calculado */
    return fim_seg + 1;
}
 
 int main () {
    /* Declaracao de variaveis */
    int n, perm[100], perm2[100], i, lim_sup = 0, lim_inf = 0, peso_min = 0;
    
    /* Entrada do tamanho da permutacao */
    scanf("%d", &n);
    /* Leitura da permutacao */
    for(i = 0; i < n; i++){
        scanf("%d", &perm[i]);
    }
    /* Alocacao de um vetor auxiliar para calcular o peso minimo */
    for(i = 0; i < n; i++){
        perm2[i] = perm[i];
    }
    
    /* Calculo do limitante inferior a ser retornado */
    lim_inf = limitante_inferior(perm, n);
    
    /* Calculo do limitante superior, enquanto a sequencia nao esta ordenada */
    while(!checa_ordenacao(perm, n)){
        lim_sup += limitante_superior(perm, n);
    }
    
    /* Peso minimo inicial eh o limitante superior (maior valor possivel) */
    peso_min = lim_sup;
    
    /* Calculo do peso minimo possivel */
    peso_minimo(perm2, n, 0, &peso_min, lim_inf);
    
    /* Retorno dos valores desejados */
    printf("Limitante inferior: %d\n", lim_inf);
    printf("Peso: %d\n", peso_min);
    printf("Limitante superior: %d\n", lim_sup);
  
    return 0;
 }
