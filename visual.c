#include<stdio.h>

void iniciarPesquisa(){
    puts("--------------------------");
    puts("--------PESQUISA----------");
    puts("-----------DE-------------");
    puts("--------SATISFAÇÃO--------");
    puts("--------------------------");
}

void  pPergunta(p1){
    puts("Nos fale o que achou sobre o nosso museu? (selecione um)\n");
    puts("1 - Extremamente Satisfeito(a)");
    puts("2 - Satisfeito(a)");
    puts("3 - nem satisfeito(a), nem insatisfeito(a)");
    puts("4 - Pouco satisfeito");
    puts("5 - Completamente insatisfeito");
}

void sPergunta(p2){
    puts("\nQual aspecto da sua experiência poderia ter sido melhor? (selecione um)\n");
    puts("1 - Velocidade");
    puts("2 - Eficiência");
    puts("3 - Facilidade de acesso");
    puts("4 - Comportamento do agente");
}

void tPergunta(p3){
    puts("\nComo avalia a exposição que visitou? (selecione um)\n");
    puts("1 - Extremamente Satisfeito(a)");
    puts("2 - Satisfeito(a)");
    puts("3 - nem satisfeito(a), nem insatisfeito(a)");
    puts("4 - Pouco satisfeito");
    puts("5 - Completamente insatisfeito ");
}

void qPergunta(p4){
    puts("\nComo você avalia a estrutura física do nosso museu? (selecione um)\n");
    puts("1 - Extremamente Satisfeito(a)");
    puts("2 - Satisfeito(a)");
    puts("3 - nem satisfeito(a), nem insatisfeito(a)");
    puts("4 - Pouco satisfeito");
    puts("5 - Completamente insatisfeito ");
}

void limparBuffer(){
    fflush(stdin);
    }
void limparTela(){
    char tecla;
    puts("Pressione qualquer tecla para continuar...");
    limparBuffer();
    getchar();
    system("cls");
}



void LerCpf(){
    FILE *cpf;
    cpf = fopen("visitantes.txt", "r");
    if(cpf == NULL){
        printf("CPF não cadastrado....");
     }
    fscanf(cpf,"Digite seu CPF %d",cpf);
    fclose(cpf);
}

