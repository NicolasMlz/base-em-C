#include <stdlib.h>
#include <stdio.h>

//Main
int main() {
    
    //Variaveis
    int t, n, alcance, lin, col, presos=0, i;
    char mundo[1000][1000];
    char espaco;

    //Scanear quantidade de casos de teste
    scanf("%d", &t);
    while(t--) {

        //Scanear tamanho da matriz e alcance de captura do ladrao
        scanf("%d%d", &n, &alcance);
        getchar();

        //Scanear composicao da matriz
        for(lin=0; lin<n; lin++) {
            for(col=0; col<n; col++) {
                scanf(" %c", &mundo[lin][col]);
            }
        }

        //Percorrer a matriz ate encontrar o policial
        for(lin=0; lin<n; lin++) {
            for(col=0; col<n; col++) {
                
                //Achou policial
                if(mundo[lin][col] == 'P') {

                    //Verificar se o policial consegue prender um bandido proximo
                    for(i=1; i<=alcance; i++) {

                        //Analise de ladroes na mesma linha
                        if(mundo[lin][col+i] == 'L') {

                            //Nao repetir mais de 1 bandido pro mesmo policial
                            mundo[lin][col+i] = "A";
                            presos++;
                            i=alcance+1;
                        }
                        else if(mundo[lin][col-i] == 'L') {
                            
                            //Nao repetir mais de 1 bandido pro mesmo policial
                            mundo[lin][col-i] = "A";
                            presos++;
                            i=alcance+1;
                        }
                    }
                }
            }
        }

        //Saida
        printf("%d\n", presos);

        //Zerar variaveis para resetar o looping
        presos=0;        

    }

    //Retorno do main
    return 0;
}