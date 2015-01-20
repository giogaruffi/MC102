 #include <stdio.h>
 
 void insertion(int vet[], int i){
    int j, aux = vet[i];
    
    for (j = i - 1; (j >= 0) && (vet[j] < aux); j--)
        vet[j + 1] = vet[j];
        
    vet[j + 1] = aux;
 }
 
 void insertionSort(int vet[], int n) {
    int i;
    
    for (i = 0; i < n; i++)
        insertion(vet, i);
 }
 
 int main () {
    int k, n, vet[100];
    
    printf("Entre com o tamanho do vetor (1 < tamanho < 100): ");
    scanf("%d", &n);
    printf("Entre com os valores do vetor: ");
    for( k = 0; k < n; k++ )
        scanf("%d", &vet[k]);
    
    insertionSort(vet, n);
    
    printf("Vetor ordenado: ");
    for ( k = 0; k < n; k++ )
        printf("%d ", vet[k]);
        
    printf("\n");
        
    return 0;
 }
