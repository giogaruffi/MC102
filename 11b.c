/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 11b - BibTeX */
 
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 /* Struct para alocar cada artigo dado */ 
 struct article{
    char label[451];
    char title[501];
    char author[501];
    char journal[101];
    char year[51];
    char volume[51];
    char number[51];
    char pages[51];
    int pos;
    int ver_vol;
    int ver_num;
    int ver_pag;
 };
 typedef struct article article;
 /* Funcao que retorna o indice do artigo de acordo com a ordem lexicografica */
 int indiceMenor(article vet[], int n, int inicio) {
    int j, min = inicio;
    
    for ( j = inicio + 1; j < n; j++ ){
        /* Testa a ordem alfabetica */
        if(strcmp(vet[min].title,vet[j].title) > 0){
            min = j;
        /* Caso o titulo seja igual, deve vir antes o que veio primeiro na entrada */
        }else if(strcmp(vet[min].title,vet[j].title) == 0){
            if(vet[min].pos > vet[j].pos){
                min = j;
            }
        }
    }
    
    return min;
 }        
 /* Funcao que troca a posicao dos artigos em ordem alfabetica */
 void troca(article *a, article *b) { 
    article aux;
    
    aux = *a;
    *a = *b;
    *b = aux;  
 }
 /* Funcao responsavel pela ordenacao dos titulos em ordem alfabetica */
 void SortNome(article vet[], int n) {
    int i, min;
    
    for (i = 0; i < n - 1; i++){
        min = indiceMenor(vet, n, i);
        troca(&vet[i], &vet[min]);
    }
 }
 /* Funcao responsavel pela alocacao de cada parametro do artigo para um vetor
 resposta */
 void alocaEntrada (char teste[], char parametro[]){
    int i=0,j=0;
    
    while(teste[i] != '{'){
        i++;
    }
    i++;
    while(teste[i] != '}'){
        parametro[j] = teste[i];
        i++;
        j++;
    }
    parametro[j] = '\0';
 }   
 
 int main () {
    /* Declaracao de variaveis */
    int N, i = 0;
    article *lista;
    /* Tamanho do teste se deve ao valor maximo da entrada de titulo somado com
    o resto dos caracteres da linha */
    char teste[515];
    char lixo;
    
    /* Entra com o numero de artigos a serem ordenados e um caracter "%", que eh
    descartado */
    scanf("%c %d", &lixo, &N);
    
    /* Aloca dinamicamente um vetor de artigos para serem ordenados */
    lista = malloc(N*sizeof(article));
    for(i=0;i<N;i++){
        /* Zera flags de existencia dos parametros volume, numero e paginas, 
        que nem sempre estao presentes */
        lista[i].ver_vol = 0;
        lista[i].ver_num = 0;
        lista[i].ver_pag = 0;
        /* Conta a posicao de cada artigo segundo a ordem da entrada */
        lista[i].pos = i;
        /* Entra com a linha denominada "label" */
        scanf("%s", lista[i].label);
        /* Enquanto a string teste nao alcanca a ultima linha do bloco de cada
        artigo, que apresenta o simbolo "}" */ 
        while(teste[0] != '}'){
            /* Leitura da linha inteira como teste */
            fgets(teste, 515, stdin);
            /* Verifica qual eh o parametro presente em cada linha e aloca na
            posicao correta do registro de artigos */
            if(strstr(teste,"author")){
                alocaEntrada(teste, lista[i].author);
            }else if(strstr(teste,"title")){
                alocaEntrada(teste, lista[i].title);
            }else if(strstr(teste,"journal")){
                alocaEntrada(teste, lista[i].journal);
            }else if(strstr(teste,"year")){
                alocaEntrada(teste, lista[i].year);
            }else if(strstr(teste,"volume")){
                /* Caso exista o parametro volume, a flag eh erguida */
                lista[i].ver_vol = 1;
                alocaEntrada(teste, lista[i].volume);
            }else if(strstr(teste,"number")){
                /* Caso exista o parametro numero, a flag eh erguida */
                lista[i].ver_num = 1;
                alocaEntrada(teste, lista[i].number);
            }else if(strstr(teste,"pages")){
                /* Caso exista o parametro paginas, a flag eh erguida */
                lista[i].ver_pag = 1;
                alocaEntrada(teste, lista[i].pages);
            }        
        }
        /* Altera o valor inicial do teste para que o loop se mantenha */
        teste[0] = 'x';
    }
    /* Ordena os artigos lexicograficamente pelo titulo */
    SortNome(lista,N);
    /* Imprime os artigos ordenados */
    for(i=0;i<N;i++){
        printf("%s, %s, %s, ", lista[i].title, lista[i].author, lista[i].journal);
        /* Caso alguma flag indique a presenca de algum dos parametros nao 
        obrigatorios, eles sao impressos */
        if(lista[i].ver_vol){
            printf("%s, ", lista[i].volume);
        }
        if(lista[i].ver_num){
            printf("%s, ", lista[i].number);
        }
        if(lista[i].ver_pag){
            printf("%s, ", lista[i].pages);
        }
        printf("%s.\n", lista[i].year);
        printf("\n"); 
    }
    /* Desalocacao da memoria */
    free(lista);
 
    return 0;
 }
