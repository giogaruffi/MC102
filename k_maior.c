 #include <stdio.h>
 
 int indiceMaior(int vet[], int n, int inicio) {
    int j, max = inicio;
    
    for ( j = inicio + 1; j < n; j++ ){
        if (vet[max] < vet[j])
            max = j;
    }
    
    return max;
 } 
 
 void troca(int *a, int *b) { 
    int aux;
    
    aux = *a;
    *a = *b;
    *b = aux;  
 }
 
 void k_esimo(int vet[], int n, int k) {
    int max, aux_k;
    
    for (aux_k = 0; aux_k < k; aux_k++){
        max = indiceMaior(vet, n, aux_k);
        troca(&vet[aux_k], &vet[max]);
    }
 }
 
 int main () {
    int l, k, n, vet[100];
    
    printf("Entre com o tamanho do vetor (1 < tamanho < 100): ");
    scanf("%d", &n);
    printf("Entre com os valores do vetor: ");
    for( l = 0; l < n; l++ )
        scanf("%d", &vet[l]);
    printf("Entre com o valor de k: ");
    scanf("%d", &k);
 
    k_esimo(vet, n, k);
    
    printf("Valor procurado: ");
    printf("%d\n", vet[k - 1]);
        
    return 0;
 }
