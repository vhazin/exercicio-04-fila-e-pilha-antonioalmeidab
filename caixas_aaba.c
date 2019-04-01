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

        int tamPilhaInventario = listaPilhas[pilhaInventario]->tamanho;
        int somaDireita = 0;
        int somaEsquerda = 0;

        if (nivelInventario < tamPilhaInventario){
            somaDireita += tamPilhaInventario - nivelInventario;
            somaEsquerda += tamPilhaInventario - nivelInventario;
        }

        int tamPilhaEsquerda, tamPilhaDireita;
        int referencia = 1;

        while (pilhaInventario + referencia < qtdPilhas){
            tamPilhaDireita = listaPilhas[pilhaInventario + referencia]->tamanho;
            if(tamPilhaDireita < pilhaInventario && tamPilhaDireita < nivelInventario){
                break;
            }
            if(tamPilhaDireita >= nivelInventario){
                somaDireita += tamPilhaDireita - nivelInventario;
                somaDireita += 1;
            }
            referencia++;
        }
        referencia = 1;
        while (pilhaInventario - referencia >= 0){
            if(tamPilhaEsquerda < pilhaInventario && tamPilhaEsquerda < nivelInventario){
                break;
            }
            tamPilhaEsquerda = listaPilhas[pilhaInventario - referencia]->tamanho;
            if(tamPilhaEsquerda >= nivelInventario){
                somaEsquerda += tamPilhaEsquerda - nivelInventario;
                somaEsquerda += 1;
            }
            referencia++;
        }
        

        int caixasRetiradas;
        if(somaDireita >= somaEsquerda){
            caixasRetiradas = somaEsquerda;
        }
        else{
            caixasRetiradas = somaDireita;
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