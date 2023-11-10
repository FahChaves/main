#include <locale.h>
#include <stdbool.h>
#define CPF_TAMANHO 12
#define IDADE_TAMANHO 3
#define MAX_NOME_COMPLETO 100
#define MAX_VISITANTES 100
typedef struct cadastro Cadastro;


struct Visitante {
    char nome[MAX_NOME_COMPLETO];
    char sobrenome[120];
    char cpf[CPF_TAMANHO];
    int idade;
    int cadastrarLoop;
    int  localVisitante;
    int auxiliar;
};

salvarArquivo(struct Visitante visitante);
struct Visitante carregarArquivo();
void criarRecibo(struct Visitante visitante);
void cadastroCliente();


