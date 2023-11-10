typedef struct data Data;

struct data {
    int data;
    int mes;
    int ano;
};

typedef struct Ingresso {
    char nome[20];
    char obra[30];
    int ticket;
    int valor;
    Data dtTicket;
    float hora;
} Ingresso;

void comprarIngressos(Ingresso Ingressos[]);
void printIngresso(Ingresso ingrs);
void printIngresso2(Ingresso ingressos[], int ticket);
void salvarDadosIngressos(Ingresso ingressos[], int ticket);
void carregarDadosIngressos(Ingresso ingressos[], int *pid);
typedef struct obras;
