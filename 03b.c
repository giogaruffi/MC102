/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 03b - Fringe */
 
 #include <stdio.h>

 int main () {
    /* Declaracao de variaveis */
    int M, S, anterior, atual, contagem0 = 0, contagem1 = 0, sincronia = 0, contagemfixa = 0, mols;
   
    /* Entrada dos valores em Mols e o numero de fases em sincronia necessarios para a abertura do portal */
    scanf("%d %d", &M, &S);
          
    /* Remocao da primeira fase (nao confiavel) */ 
    scanf("%d", &atual);
    anterior = atual;
   
    while ( atual == anterior ) {      
        scanf("%d", &atual );
    }    

    /* Loop de contagem de fases */
    while ( atual != -1 ) {                
        
    /* Comparacao com o valor anterior da contagem para analisar se existe repeticao de fase */       
        if ( atual != anterior && atual ) {
    /* Contagem de repeticoes de fase e contagem do tempo de fase '1'*/           
            if ( contagem1 == contagem0 ) {
                if ( contagem1 != contagemfixa ) {
                    sincronia = 1;
                }    
                sincronia++;
                contagemfixa = contagem1;
            }
            contagem1 = 1;
        }
        if ( atual != anterior && !atual ) {
     /* Contagem de repeticoes de fase e contagem do tempo de fase '0' */     
            if ( contagem0 == contagem1 ) {
                if ( contagem0 != contagemfixa ) {
                    sincronia = 1;
                } 
                sincronia++;
                contagemfixa = contagem0;
            }
            contagem0 = 1; 
        }
        
    /* Contagem dos valores de cada fase */    
        if ( atual == anterior && atual ) {
            contagem1++;
        }            
       
        if ( atual == anterior && !atual ) {
            contagem0++;
        }
        anterior = atual;
        scanf("%d", &atual);
    }           
        
    /* Verificacao da sincronia */
    if ( sincronia >= S ) {
        mols = M * contagemfixa;
        printf("%d mols\n", mols);
                          
    } else {
        printf("Portal nao abriu\n");
    }
 
    return 0;
}
