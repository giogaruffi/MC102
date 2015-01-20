/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 10a - LSCrypto */
 
 #include <stdio.h>
 /* Definir tamanhos maximos do texto */
 #define MAXLINHAS 15 
 #define MAXLETRAS 501
 
 /* Criar registro para contar repeticoes de cada letra */
 struct Letra {
    char letra;
    int num;
 };
  
 /* Funcao responsavel por ordenar as letras por repeticoes */
 void ordena(struct Letra vetor[], int n) {
    int i, j;
    struct Letra aux;
   
    /* Ordena registro de acordo com a ordenacao do tipo .letra */
    for (i = 1; i < n; i++) {
        aux = vetor[i];
        j = i - 1;
        while ((j >= 0) && (vetor[j].num < aux.num)) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = aux;
    }
 }
 
 /* Funcao responsavel por buscar e retornar o valor da letra a ser alterada */
 char buscaSequencial(struct Letra vetor[], int n, int chave) {
    int i;
    
    /* Busca no registro a chave pedida e retorna a letra para a troca */
    for ( i = 0; i < n; i++ ){
        if (vetor[i].letra == chave){
            /* Caso a posicao no vetor de contagem seja par, retornar a letra seguinte */
            if (!(i%2)){
                return vetor[i+1].letra;
            /* Caso a posicao no vetor de contagem seja impar, retornar a letra anterior */
            }else{
                return vetor[i-1].letra;
            }
        /* Verificacao de letras maiusculas (retorno igual ao caso das minusculas */
        } else if (vetor[i].letra - 32 == chave){
            if (!(i%2)){
                return vetor[i+1].letra - 32;
            }else{
                return vetor[i-1].letra - 32;
            }
        }    
    }
    return -1;
 }
 
 int main () {
    /* Declaracao de variaveis */
    char texto[MAXLINHAS][MAXLETRAS];
    int N, i, j;
    struct Letra letras[26];
    /* Entrada do numero de linhas de texto */
    scanf("%d\n", &N);
    /* Entrada do texto a ser criptografado */
    for ( i = 0; i < N; i++ ){
        fgets(texto[i], MAXLETRAS, stdin);
    }
    /* Inicializar o registro como uma sequencia de letras minusculas e a contagem como zero */
    for ( j = 0; j < 26; j++ ){
        letras[j].letra = j + 97;
        letras[j].num = 0;
    }
    /* Contagem das repeticoes de cada letra do texto */
    for ( i = 0; i < N; i++ ){
         for ( j = 0; texto[i][j] != '\0' && texto[i][j] != '\n'; j++ ){
            /* Caso as letras sejam maiusculas, conta-las como minusculas */
            if ( texto[i][j] <= 'Z' && texto[i][j] >= 'A' ){
                letras[texto[i][j] - 65].num++;
            } else if ( texto[i][j] <= 'z' && texto[i][j] >= 'a' ){
                letras[texto[i][j] - 97].num++;
            }
         }
    }
    /* Ordenar letras de acordo com o valor das contagens */
    ordena(letras, 26);
    /* Substituicao dos caracteres do texto com seu respectivo valor criptografado */
    for ( i = 0; i < N; i++ ){
        for ( j = 0; texto[i][j] != '\0' && texto[i][j] != '\n'; j++ ){
            /* Somente trocar caso o caractere seja uma letra */
            if ((texto[i][j] >= 'A' && texto[i][j] <= 'Z') || (texto[i][j] >= 'a' && texto[i][j] <= 'z'))
                texto[i][j] = buscaSequencial(letras, 26, texto[i][j]);
        }
    }
    /* Impressao do texto final criptografado */
    for ( i = 0; i < N; i++ ){
        printf("%s", texto[i]);
    }
    
    return 0;
 }
