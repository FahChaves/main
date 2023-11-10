#include <stdio.h>

#define INTEIRA 1
#define MEIA 2
#define MEIA_SOCIAL 3
#define INATIVO 4
#define MAX 200

struct data{

    int data;
    int mes;
    int ano;
};
    typedef struct data Data;

    struct Ingresso {
    char nome[20];
    char obra[30];
    int ticket;
    int tipo;
    Data dtIngresso;
    float hora;
};
typedef struct Ingresso Ingresso;

typedef struct{
    int obraEscolhidas[MAX];
    int qtdIngressos[MAX];
}IngressoStruct;

void comprarIngressos(Ingresso Ingressos[]){
    IngressoStruct igrs = {0};
    int tipo;
    int novaCompra;
    int obrasEscolhidas[MAX] = {0};
    int qtdIngressos[MAX] = {0};
    int valorTotal = 0;
    int tipoIngresso;
    int totalAPagar;
    int totalIngressos = 0;
    int valor;


    do{
        puts("\nEscolha uma obra desejada:");
        puts("1 - 150 anos de Santos Dumont");
        puts("2 - 100 ANOS DA ARTE MODERNA");
        puts("3 - INTELIGÊNCIA ARTIFICIAL (IA)");
        puts("4 - JOGOS OLÍMPICOS 2024");
        puts("________________________");
        printf("opção: ");



        scanf("%d",&tipo);

        if (tipo >= 1 && tipo <= MAX) {
            obrasEscolhidas[tipo - 1] = 1;

            printf("Digite a quantidade de ingressos desejada para esta obra: ");
            scanf("%d", &qtdIngressos[tipo - 1]);
        } else {
            printf("Escolha inválida. Tente novamente.\n");
        }

        puts("\nDeseja efetuar a compra de ingresso de mais alguma obra?\n Digite 1 para sim.\n Digete 2 para não.");
        scanf("%d", &novaCompra);

        }while(novaCompra == 1);

            //contagem de ingresso escolhida
        for(int i=0; i < MAX; i++){
          if (obrasEscolhidas[i] == 1){
            totalIngressos += qtdIngressos[i];
          }
        }

    printf("Escolha o tipo de ingresso\n1 - Inteira;\n2 - Meia;\n3 - Meia Social; ");
    scanf("%d", &tipoIngresso);

    if(tipoIngresso ==1){
        valor = 40;
        valorTotal = valor * totalIngressos;
    }else if(tipoIngresso == 2){
        valor = 20;
        valorTotal = valor * totalIngressos;
    }else
        printf("Ingresso gratuito, boa exposição!");


    int formaPagamento;
    puts("\n-------------------------------");
    puts("\nEscolha a forma de pagamento:");
    puts("1 - Dinheiro");
    puts("2 - Cartão de Crédito");
    puts("3 - Cartão de Débito");
    puts("4 - Pix");
    printf("Escolha a forma de pagamento (1-4): ");
    scanf("%d", &formaPagamento);
    puts("-------------------------------\n");
    printf("\nTotal de ingressos: %d\n", totalIngressos);
    printf("\nValor total da compra: R$%d\n", valorTotal);
    return 0;
}


void salvarDadosIngressos(Ingresso ingressos[], int ticket){
    FILE *fp;
    fp = fopen("Ingressos.txt", "w");
    puts("Salvando dados em arquivos...");
    fprintf(fp,"%d\n", ticket);

    for(int i=0; i<ticket; i++){
        Ingresso ingrs;
        ingrs = ingressos[i];
        fprintf(fp,"%s\n",ingrs.nome);
        fprintf(fp,"%d/%d/%d\n",ingrs.dtIngresso.data,ingrs.dtIngresso.mes,ingrs.dtIngresso.ano);
        fprintf(fp,"%d %d\n",ingrs.ticket, ingrs.tipo);
    }
    puts("Dados foram salvos com sucesso!");
    fclose(fp);
}

void carregarDadosIngressos(Ingresso ingressos[],int *pid){
    FILE *fp;
    fp = fopen("Ingressos.txt","r");
    if (fp != NULL){
        puts("Carregando dados do arquivo...");
        puts("Lendo informação de ticket...");
        int ticket;
        fscanf(fp,"%d\n",&ticket);
        *pid = ticket;
        puts("Lendo dados de compras de Ingressos...");
        int qtd = 0;
        while(!feof(fp)){
                Ingresso ingrs;
                fscanf(fp,"%[^\n]s",ingrs.nome);
                fscanf(fp,"%d %d\n",&ingrs.ticket, &ingrs.tipo);
                ingressos[ingrs.ticket] = ingrs;
                qtd++;
            }
             fclose(fp);
        puts("Dados carregados com sucesso...");
        printf("Foram carregados %d registros de compras de ingressos...\n",qtd);
    }else{
        puts("Arquivo inexistente ou erro de leitura de arquivo!");
    }
    }


