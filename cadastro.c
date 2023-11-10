
#include <stdio.h>
#include "cadastro.h"
#include <locale.h>
#include <stdbool.h>

void cadastroCliente(){
    puts("********************************************");
    puts("*                                          *");
    puts("*                 Cadastro                 *");
    puts("*                   DE                     *");
    puts("*                 Clientes                 *");
    puts("*                                          *");
    puts("*                                          *");
    puts("*                       MUSEU-MULTITEMATICO*");
    puts("********************************************");


}

bool validarCPF(const char *cpf) {
    int len = strlen(cpf);
    if (len != 11) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (!isdigit(cpf[i])) {
            return false;
        }
    }
    return true;
}

void registrarVisitante(struct Visitante visitante) {
    FILE *arquivo = fopen("visitantes.txt", "a");

     printf("Informe o nome completo: ");
    scanf(" %[^\n]", visitante.nome);


    do {
        printf("Digite o CPF (somente números, tudo junto, onze dígitos): ");
        scanf("%s", visitante.cpf);
    } while (!validarCPF(visitante.cpf));

    printf("Informe a idade: ");
    scanf("%d", &visitante.idade);


    fprintf(arquivo, "Nome: %s\n", visitante.nome);
    fprintf(arquivo, "CPF: %s\n", visitante.cpf);
    fprintf(arquivo, "Idade: %d\n", visitante.idade);

    fclose(arquivo);
}

struct Visitante carregarArquivo() {
    struct Visitante visitante;
    FILE *arquivo = fopen("visitantes.txt", "r");
    if (arquivo != NULL) {
        fscanf(arquivo, "Nome: %s\n", visitante.nome);
        fscanf(arquivo, "CPF: %s\n", visitante.cpf);
        fscanf(arquivo, "Idade: %d\n", &visitante.idade);
        fclose(arquivo);
    }
    return visitante;
}

void criarRecibo(struct Visitante visitante) {
    FILE *recibo = fopen("recibo.txt", "a");
    if (recibo != NULL) {
        fprintf(recibo, "\n=========================");
        fprintf(recibo, "\nRecibo do visitante %s\n", visitante.nome);
        fprintf(recibo, "Nome: %s\n", visitante.nome);
        fprintf(recibo, "CPF: %s\n", visitante.cpf);
        fprintf(recibo, "Idade: %d\n", visitante.idade);
        fprintf(recibo, "=========================\n");
        fclose(recibo);
    } else {
        printf("Não foi possível criar o recibo.\n");
    }
}
