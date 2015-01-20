/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 05b - Killing the Messenger */
 
 #include <stdio.h>
 
 int main () {
    /* Declaracao de variaveis */
    char mRNA[101], oligo[26];
    int R, O, s, k = 0, t, temp, marcador_igual, silenciado = 0, sucesso = 0;
    /* Entrada do numero de bases do RNA mensageiro e do oligonucleotideo */
    scanf("%d %d", &R, &O);
      
    /* Entrada das bases presentes no RNA mensageiro e no oligonucleotideo */
    scanf("%s\n", mRNA);
    scanf("%s", oligo);
    
    /* Inverter o oligonucleotideo, uma vez que a comparacao com o mRNA se da ao contrario */ 
    for ( s = 0; s < O/2; s++ ){
        temp = oligo[O - s - 1];
        oligo[O - s - 1] = oligo[s];
        oligo[s] = temp;
    }
    
    /* Troca do valor das bases do oligonucleotideo, para que essas fiquem possivelmente iguais as do mRNA */ 
    for ( s = 0; s < O; s++ ){
        if (oligo[s] == 'A'){
            oligo[s] = 'U';
        }else if (oligo[s] == 'U'){
            oligo[s] = 'A';
        }else if (oligo[s] == 'G'){
            oligo[s] = 'C';
        }else if (oligo[s] == 'C'){
            oligo[s] = 'G';
        }
    }
    
    /* Verificacao do silenciamento: checagem se oligonucleotideo decodificado eh substring do mRNA */
    while((k < R) && (silenciado < O)){      
        marcador_igual = k;
        t = 0;
        silenciado = 0; 
        while (mRNA[marcador_igual] == oligo[t] && (silenciado < O)){
            silenciado++;
            t++;
            marcador_igual++;       
            if(silenciado == O){
                printf("Silenciado em %d\n", k + 1);
                sucesso = 1;
            }
        }
        k++;
    }
     
    /* Se o silenciamento nao ocorreu, flag "sucesso" continua igual a 0 */   
    if ( !sucesso )
        printf("Nao silenciado\n");        
              
    return 0;
 }
