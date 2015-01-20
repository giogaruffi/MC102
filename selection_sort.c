 #include <stdio.h>
 
 int indiceMenor(int vet[], int n, int inicio) {
    int j, min = inicio;
    
    for ( j = inicio + 1; j < n; j++ ){
        if (vet[min] > vet[j])
            min = j;
    }
    
    return min;
 }        
 
 void troca(int *a, int *b) { 
    int aux;
    
    aux = *a;
    *a = *b;
    *b = aux;  
 }
 
 void selectionSort(int vet[], int n) {
    int i, min;
    
    for (i = 0; i < n - 1; i++){
        min = indiceMenor(vet, n, i);
        troca(&vet[i], &vet[min]);
    }
 }
 
 int main () {
    int i, n, vet[100];
    
    printf("Entre com o tamanho do vetor (1 < tamanho < 100): ");
    scanf("%d", &n);
    printf("Entre com os valores do vetor: ");
    for( i = 0; i < n; i++ )
        scanf("%d", &vet[i]);
    
    selectionSort(vet, n);
    
    printf("Vetor ordenado: ");
    for ( i = 0; i < n; i++ )
        printf("%d ", vet[i]);
        
    printf("\n");
        
    return 0;
 }
