#include <stdio.h>

typedef struct Tempo tempo;
struct Tempo{
    int dia, mes, ano, hora, minuto;
};

typedef struct reg data;
struct reg{
	char nome[60];
	tempo inicio;
    int duracao;
    tempo deadline;
};

typedef struct Tarefa tarefa;
struct Tarefa{
    int id;
    data dados;
    tarefa *prox;
};

void mostraMenu(); 
void imprimeTodos (tarefa *lista);
tarefa * adicionarTarefa (tarefa *lista); 
void populaTarefa (tarefa *lista);
void populaHorario (tempo *horario);
tarefa * editaTarefa (tarefa *lista, int id);
tarefa * removerTarefa (tarefa *lista, int id);
tarefa * inicializa(tarefa *l);
tarefa * libera_lst(tarefa *l);
void imprimeTempo (tempo horario);
tarefa  * carregaArquivo (tarefa *lista);
void escreveArquivo (tarefa *lista);

FILE *arq;