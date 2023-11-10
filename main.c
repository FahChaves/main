#include <stdio.h>
#include "cadastro.h"
#include <locale.h>
#include "visual.h"

#include "Ingressos.h"
#include "Obras.h"

#define MAX 1000
#define TRUE 1
#define FALSE 0


int main (){

     setlocale(LC_ALL, "Portuguese");

    int cadastrarLoop;
    int inicio;
    struct Visitante visitante;
    struct Visitante visitantes[MAX_VISITANTES];
    int numVisitantes = 0;

    FILE *arquivo = fopen("visitantes.txt", "w");
    if (arquivo != NULL) {
        fclose(arquivo);
    } else {
        printf("Não foi possível abrir.\n");
        return 1;
    }

    while(inicio == 1);
    do {
     cadastroCliente();
     registrarVisitante(&visitantes[numVisitantes]);

     printf("\n=========================");
        printf("\nInformações do visitante:\n");
        printf("Nome - %s\n", visitantes[numVisitantes].nome);
        printf("CPF - %s\n", visitantes[numVisitantes].cpf);
        printf("Idade - %d\n", visitantes[numVisitantes].idade);
        printf("=========================\n");

   criarRecibo(visitante);
     numVisitantes++;

    printf("\nHá mais algum visitante a ser cadastrado?\n");
    printf("Digite a tecla 1 se sim. Digite 2 se não:");
    scanf(" %d", &cadastrarLoop);

    } while (cadastrarLoop == 1);
     int p1,p2,p3,p4;
   int escolha;
   char cpfPesquisa[CPF_TAMANHO];
    // compra de ingresso
      Ingresso ingressos[MAX];
    int ticket = 0;
    char obra[30];
    int opc;

        do {
            imprimirCabecalho();
            exibirMenu();
            scanf("%d", &opc);
            Ingresso ingrs;
            switch (opc) {
                case 1:
                    comprarIngressos(ingressos);
                    break;
                case 2: // SAIR
                    break;
                    return 0;
                default:  puts("Opção inexistente, tente novamente!");
                limparTela();
            }
        printf("Deseja iniciar o sistema de compra? \nSe sim, digite: 1 \nCaso não pressione 0 para continuar...\n");
        scanf("%d", &inicio);
        } while (inicio == 1);
        printf("\n======================\n");
        printf("Tenha uma ótima diverção!");
        printf("\n=======================\n");

    //iniciando a pesquisa
   do {
        FILE *pesquisa = fopen("gravar.txt", "a");
        if (pesquisa == NULL) {
            printf("Não foi possível abrir o arquivo gravado...");
            return 1;
        }

        int cpfValido;

        do {
            printf("\n");
            iniciarPesquisa();
            printf("\n---------------------------");
            printf("\nDigite o CPF para pesquisa: ");
            scanf("%s", cpfPesquisa);


            cpfValido = 0;
            for (int i = 0; i < numVisitantes; i++) {
                if (strcmp(cpfPesquisa, visitantes[i].cpf) == 0) {
                    cpfValido = 1;
                    break;
                }
            }

            if (cpfValido) {
                printf("CPF válido, pode prosseguir com a pesquisa.\n");

        pPergunta();
        scanf("%d", &p1);
            switch(p1){
            case 1:
            puts ("Extremamente Satisfeito(a);");
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
            limparTela();
        fprintf(pesquisa,"Resposta da primeira pergunda: %d", p1);
        fprintf(pesquisa,"Resposta da segunda pergunda: %d", p2);
        fprintf(pesquisa,"Resposta da terceira pergunda: %d",p3);
        fprintf(pesquisa,"Resposta da quarta pergunda: %d", p4);

        fclose(pesquisa);

        printf("Deseja continuar a pesquisa?/n Digite 1 para sim, ou Digite 0 para não");
        scanf("%d",&escolha);

         } else {
                printf("CPF inválido. Tente novamente.\n");
            }
        } while (!cpfValido);

        }while(escolha == 1);

    }
