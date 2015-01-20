 #include <stdio.h>

 void troca(int *a, int *b) { 
    int aux;
    
    aux = *a;
    *a = *b;
    *b = aux;  
 }
 
 void bubbleSort(int vet[], int n) {
    int i, j, ordenado = 0;
    
    for ( i = n - 1; i > 0; i-- ) {
        for ( j = 0; j < i; j++ ) {
            if (vet[j] < vet[j + 1]){
                ordenado++;
            } else {
                troca(&vet[j + 1], &vet[j]);
            }
            if ( ordenado == n ){
                return;
            }
        }
    }
 }
 
 int main () {
    int k, n, vet[100];
    
    printf("Entre com o tamanho do vetor (1 < tamanho < 100): ");
    scanf("%d", &n);
    printf("Entre com os valores do vetor: ");
    for( k = 0; k < n; k++ )
        scanf("%d", &vet[k]);
    
    bubbleSort(vet, n);
    
    printf("Vetor ordenado: ");
    for ( k = 0; k < n; k++ )
        printf("%d ", vet[k]);
        
    printf("\n");
        
    return 0;
 }
