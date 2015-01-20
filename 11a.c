/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 11a - Copa do Mundo */
 
 #include <stdio.h>
 #include <string.h>
 /* Criar registro para alocar as informacoes de cada selecao */
 struct Copa {
    char nome[15];
    int gols_feitos;
    int gols_sofridos;
    int saldo;
    int pontos;
 };
 typedef struct Copa copa;
 /* Calcular a selecao melhor colocada para a ordenacao */
 int indiceMaior(copa selecao[][4], int pos, int inicio) {
    int j, max = inicio;
    
    for ( j = inicio + 1; j < 4; j++ ){
        /* Primeiro criterio: Pontuacao total */
        if (selecao[pos][max].pontos < selecao[pos][j].pontos){
            max = j;
        } else if (selecao[pos][max].pontos == selecao[pos][j].pontos) {
            /* Segundo criterio: Saldo de gols */
            if (selecao[pos][max].saldo < selecao[pos][j].saldo){
                max = j;
            }else if(selecao[pos][max].saldo == selecao[pos][j].saldo){
                /* Terceiro criterio: Mais gols feitos */
                if (selecao[pos][max].gols_feitos < selecao[pos][j].gols_feitos){
                    max = j;
                }else if (selecao[pos][max].gols_feitos == selecao[pos][j].gols_feitos){
                    /* Quarto critario: Ordem alfabetica */
                    if(strcmp(selecao[pos][max].nome,selecao[pos][j].nome) > 0){
                    max = j;
                    }
                }
            }
        }
    }
    return max;
 }        
 /* Trocar para a ordenacao */
 void troca(copa *a, copa *b) { 
    copa aux;
    
    aux = *a;
    *a = *b;
    *b = aux;  
 }
 /* Ordenar selecoes de cada grupo */
 void ordenarSelecao(copa selecao[][4], int pos) {
    int i, max;
    
    for (i = 0; i < 4; i++){
        max = indiceMaior(selecao, pos, i);
        troca(&selecao[pos][i], &selecao[pos][max]);
    }
 }
  
 /* Fazer o calculo dos gols a favor e contra de cada jogo, assim como o 
 saldo de gols do jogo e os pontos que cada time recebe */
 void Gols_Pontos (copa jogos[][2], copa selecao[][4]){
    int i, j;
    /* Zerar os dados da matriz de selecoes final que vai somar os 
    valores de cada jogo */  
    for(i=0;i<8;i++){
        for(j=0;j<4;j++){
            selecao[i][j].gols_feitos = 0;
            selecao[i][j].gols_sofridos = 0;
            selecao[i][j].saldo = 0;
            selecao[i][j].pontos = 0;
        }
    }
    
    for(i=0;i<48;i++){
        /* Calcular dos gols e saldo de cada selecao */
        jogos[i][0].gols_sofridos = jogos[i][1].gols_feitos;
        jogos[i][1].gols_sofridos = jogos[i][0].gols_feitos;
        jogos[i][0].saldo = jogos[i][0].gols_feitos - jogos[i][0].gols_sofridos;
        jogos[i][1].saldo = jogos[i][1].gols_feitos - jogos[i][1].gols_sofridos;
        /* Atribuir os pontos de vitoria e empate */
        if(jogos[i][0].gols_feitos == jogos[i][1].gols_feitos){
            jogos[i][0].pontos = 1;
            jogos[i][1].pontos = 1;
        }else if(jogos[i][0].gols_feitos > jogos[i][1].gols_feitos){
            jogos[i][0].pontos = 3;
            jogos[i][1].pontos = 0;
        }else{
            jogos[i][1].pontos = 3;
            jogos[i][0].pontos = 0;
        }
    }
 }
 /* Criar de cada grupo separadamente */
 void alocacaoGrupos(copa jogos[][2], copa selecao[][4]){
    int i, j, f;
 
    /* Copiar o nome de cada time dos 4 primeiros jogos para cada 
    grupo*/
    /* A seguir pular para 6 jogos depois, o que corresponde ao 
    proximo grupo */
    for(j=0,i=0;j<48;j+=6,i++){
        for(f=0;f<2;f++){
            strcpy(selecao[i][f].nome,jogos[j][f].nome);
            strcpy(selecao[i][f+2].nome,jogos[j+1][f].nome);
        }
    }
 }
 /* Somar os dados calculados de cada jogo para a selecao correspondente */
 void somarSelecao(copa jogos[][2], copa selecao[][4]){
    int i, j, f, g, l;
    
    /* Percorrer a matriz de selecoes definitiva */
    for(i=0,g=0;i<8;i++,g+=6){
        for(j=0;j<4;j++){
            /* Percorrer a matriz de jogos, com maximo de 6 jogos 
            para cada grupo */
            for(l=0;l<6;l++){
                for(f=0;f<2;f++){
                    /* Encontrar as vezes que a selecao aparece 
                    nos jogos e somar os dados calculados */
                    if(strcmp(selecao[i][j].nome,jogos[g+l][f].nome) == 0){
                        selecao[i][j].gols_feitos += jogos[g+l][f].gols_feitos;
                        selecao[i][j].gols_sofridos += jogos[g+l][f].gols_sofridos;
                        selecao[i][j].saldo +=jogos[g+l][f].saldo;
                        selecao[i][j].pontos +=jogos[g+l][f].pontos;
                    }
                }
            }
        }
    }
 }
 
 int main () {
    copa jogos[48][2],selecao[8][4];
    int i, j;
    /* Ler o resultado dos jogos e aloca-los em uma matriz 
    especifica de jogos */
    for(i=0;i<48;i++){
        scanf("%s %d x %d %s", jogos[i][0].nome, &jogos[i][0].gols_feitos, &jogos[i][1].gols_feitos, jogos[i][1].nome);
    }
    /* Calcular pontos obtidos e quantidade de gols para cada jogo 
    separadamente */
    Gols_Pontos(jogos, selecao);
    /* Separar as selecoes de cada grupo */
    alocacaoGrupos(jogos, selecao);    
    /* Transferir e somar todos os pontos calculados na matriz de 
    jogos para sua respectiva selecao */
    somarSelecao(jogos, selecao);
    /* Ordenar as selecoes de acordo com os criterios de desempate */   
    for(i=0;i<8;i++){
        ordenarSelecao(selecao,i);
    }
    /* Imprimir grupos ordenados, assim como os resultados de cada 
    selecao */ 
    for(i=0;i<8;i++){
        printf("Grupo %c:\n", i+65);
        for(j=0;j<4;j++){
            printf("%-15s %3d %3d %3d %3d\n", selecao[i][j].nome, selecao[i][j].pontos, selecao[i][j].gols_feitos, selecao[i][j].gols_sofridos, selecao[i][j].saldo);
        }
        printf("\n");
    }
    /* Imprimir os times escolhidos para a segunda fase */
    printf("Oitavas de final:\n");
    for(i=0;i<8;i+=2){
        printf("%15s x %s\n", selecao[i][0].nome, selecao[i+1][1].nome);
        printf("%15s x %s\n", selecao[i+1][0].nome, selecao[i][1].nome);
    }
    
 return 0;
 }
