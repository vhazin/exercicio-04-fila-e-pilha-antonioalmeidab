#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
    int tamanho;
}pilha;

int main(void) {
    int totalCaixas, qtdPilhas, numPilha;
    int nivelInventario;
    int pilhaInventario;

    scanf("%d", &totalCaixas);

    while(totalCaixas != 0){
        scanf("%d", &qtdPilhas);


        pilha *listaPilhas[qtdPilhas];
        for(numPilha = 0; numPilha < qtdPilhas; numPilha++){
            int caixasnaPilha, nivelAtual;
            scanf("%d", &caixasnaPilha);

            pilha *novaPilha = malloc(sizeof(pilha));
            listaPilhas[numPilha] = novaPilha;
            novaPilha->tamanho = caixasnaPilha;
            
            for(nivelAtual = 0; nivelAtual < caixasnaPilha; nivelAtual++){
                int dado;
                scanf("%d", &dado);
                if(dado == 1){
                    nivelInventario = nivelAtual + 1;
                    pilhaInventario = numPilha;
                }
            }
        }

        int caixasRetiradas = 0;
        int tamPilhaInventario = listaPilhas[pilhaInventario]->tamanho;

        if (nivelInventario < tamPilhaInventario){
            caixasRetiradas += tamPilhaInventario - nivelInventario;
        }
        if (pilhaInventario != 0 && pilhaInventario != qtdPilhas - 1){
            int tamPilhaEsquerda, tamPilhaDireita;
            tamPilhaDireita = listaPilhas[pilhaInventario + 1]->tamanho;
            tamPilhaEsquerda = listaPilhas[pilhaInventario - 1]->tamanho;

            if (tamPilhaEsquerda >= nivelInventario && tamPilhaDireita >= nivelInventario){
                caixasRetiradas = caixasRetiradas + 1;
                if(tamPilhaEsquerda <= tamPilhaDireita){
                    int auxiliar = auxiliar;
                    caixasRetiradas += auxiliar - nivelInventario;
                    if (nivelInventario == 1){
                        caixasRetiradas += 1;
                    }

                    int referencia = 2;
                    while (pilhaInventario - referencia >= 0){
                        int tamMaisEsquerda = listaPilhas[pilhaInventario - referencia]->tamanho;
                        if(tamMaisEsquerda >= auxiliar){
                            caixasRetiradas += 1;
                            caixasRetiradas += tamMaisEsquerda - auxiliar;
                            auxiliar = tamMaisEsquerda;
                        }
                        else if(tamMaisEsquerda == nivelInventario){
                            caixasRetiradas += 1;
                        }
                        else{
                            break;
                        }
                        referencia++;
                    }
                }
                else{
                    int auxiliar = tamPilhaDireita;                    
                    caixasRetiradas += auxiliar - nivelInventario;
                    if (nivelInventario == 1){
                        caixasRetiradas += 1;
                    }
                    int referencia = 2;
                    while (pilhaInventario + referencia < qtdPilhas){
                        int tamMaisDireita = listaPilhas[pilhaInventario + referencia]->tamanho;
                        if(tamMaisDireita >= auxiliar){
                            caixasRetiradas += 1;
                            caixasRetiradas += tamMaisDireita - auxiliar;
                            auxiliar = tamMaisDireita;
                        }
                        else if(tamMaisDireita == nivelInventario){
                            caixasRetiradas +=1 ;
                        }
                        else{
                            break;
                        }
                        referencia++;
                    }
                }
            }
        }
        scanf("%d", &totalCaixas);
        if(totalCaixas == 0){
            printf("%d", caixasRetiradas);
        }
        else{
            printf("%d\n", caixasRetiradas);
        }
        
    }
    return 0;
}