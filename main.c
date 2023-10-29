#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "visual.h"

#define TRUE 1
#define FALSE 2

int main(){
    setlocale(LC_ALL,"");
    int p1, p2, p3,p4, cpf;
    do{
        iniciarPesquisa();
        pPergunta();
        scanf("%d", &p1);

            switch(p1){
            case 1:
            puts("Extremamente Satisfeito(a);");
            break;
            case 2:
            puts("Satisfeito(a)");
            break;
            case 3:
            puts("nem satisfeito(a), nem insatisfeito(a)");
            break;
            case 4:
            puts("Pouco satisfeito");
            break;
            case 5:
            puts("Completamente insatisfeito");
            break;
            }
        sPergunta();
        scanf("%d",&p2);
            switch(p2){
            case 1:
            puts("Velocidade");
            break;
            case 2:
            puts("Eficiência");
            break;
            case 3:
            puts("Facilidade de acesso");
            break;
            case 4:
            puts("Comportamento do agente");
            break;
            }
        tPergunta();
        scanf("%d",&p3);
            switch(p3){
            case 1:
            puts("Extremamente Satisfeito(a);");
            break;
            case 2:
            puts("Satisfeito(a)");
            break;
            case 3:
            puts("nem satisfeito(a), nem insatisfeito(a)");
            break;
            case 4:
            puts("Pouco satisfeito");
            break;
            case 5:
            puts("Completamente insatisfeito");
            break;
            }
        qPergunta();
        scanf("%d",&p3);
            switch(p3){
            case 1:
            puts("Extremamente Satisfeito(a);");
            break;
            case 2:
            puts("Satisfeito(a)");
            break;
            case 3:
            puts("nem satisfeito(a), nem insatisfeito(a)");
            break;
            case 4:
            puts("Pouco satisfeito");
            break;
            case 5:
            puts("Completamente insatisfeito");
            break;
            }
        return(cpf);
        limparTela();
    }while(TRUE);
}
