#include <stdio.h>
#include <stdlib.h>

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
    tarefa * prox;
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

int tam = 0;

int main(){

	int op,i,tmp,id;

    tarefa *lista;
    lista = inicializa (lista);

	do{
		mostraMenu();
		scanf("%d",&op);
		switch(op){
			case 1:
                lista = adicionarTarefa(lista);
				break;
			case 2:
				imprimeTodos(lista);
				break;
			case 3:
                imprimeTodos(lista);
                printf("Por favor digite o ID de uma tarefa");
                scanf("%d", &id);
				lista = removerTarefa(lista, id);
				break;
			case 4:
                imprimeTodos(lista);
                printf("Por favor digite o ID de uma tarefa");
                scanf ("%d", &id);
                lista = editaTarefa (lista, id);
				break;
			case 5:
				//carregar arquivo de tarefas
				break;
			case 6:
				//gerar arquivo de tarefas
				break;
            case 7:
                //computar a agenda do dia
                break;
            case 8:
                //salvar a agenda do dia
                break;
			case 0:
				printf("Obrigado por usar o nosso programa!\n"); 
                libera_lst(lista);
				break;

			default:
				printf("OPCAO NAO CADASTRADA!\n");  
				system("pause");
				break;

		}
	}while(op!=0);
}

void mostraMenu(){
  printf ("|-----------------------------------------|\n");
  printf ("|           CADASTRO DE TAREFAS           |\n");
  printf ("|_________________________________________|\n");
  printf ("|            MENU DE OPÇÕES               |\n");
  printf ("|-----------------------------------------|\n");
  printf ("| 1 -INCLUIR NOVA TAREFA                  |\n");
  printf ("| 2 -VISUALIZAR TAREFAS CADASTRADAS       |\n");
  printf ("| 3 -EXCLUIR TAREFA                       |\n");
  printf ("| 4 -EDITAR TAREFA                        |\n");
  printf ("| 5 -CARREGAR ARQUIVO DE TAREFAS          |\n");
  printf ("| 6 -GERAR ARQUIVO DE TAREFAS             |\n");
  printf ("| 7 -COMPUTAR AGENDA DO DIA               |\n");
  printf ("| 8 -SALVARA AGENDA DO DIA                |\n");
  printf ("| 0 –SAIR                                 |\n");
  printf ("|-----------------------------------------|\n");
}

void imprimeTodos (tarefa *lista){
    tarefa *p;
    p = lista;

    while(p!=NULL){
        printf(" Tarefa: %s ID: %d \n", p->dados.nome ,p->id);
        printf(" Inicio: ");
        imprimeTempo(p->dados.inicio);
        printf(" \n Duração: %d minutos", p->dados.duracao);
        printf(" \n Deadline: ");
        imprimeTempo(p->dados.deadline);
        printf("\n---------------------------\n");
        
        p = p->prox;
        }
        return;
}

 tarefa * adicionarTarefa (tarefa *lista){
    tarefa *novo,*mov;
    
    int id;

       if(lista != NULL){
        novo = (tarefa*)malloc(sizeof(tarefa));
        populaTarefa(novo);
        mov=lista;
        id = mov->id;
        printf("id original = %d\n", id);
        while(mov->prox != NULL){
            id = mov->prox->id;
            printf("id atual = %d\n", mov->id);
            mov = mov->prox;
            printf("prox id: %d\n",mov->id);
        }
        novo->id = id+1;
        printf("id novo = %d\n", novo->id);
        mov->prox = novo;
        novo -> prox = NULL;
        }
         
    if(lista == NULL) {
        lista = (tarefa*)malloc(sizeof(tarefa));
        populaTarefa(lista);
        lista->id = 1;
    }
    

    return(lista);
}

void populaTarefa (tarefa *lista){
    printf("Nome da atividade:");
    scanf ("%s", lista->dados.nome);
    printf("\nHorario de Inicio:");
    populaHorario(&lista->dados.inicio);
    printf("\nDuração da tarefa(minutos):");
    scanf("%d", &lista->dados.duracao);
    printf("\nHorario de Deadline:");
    populaHorario(&lista->dados.deadline);
   }

void populaHorario (tempo *horario){
    printf("\nDia ");
    scanf("%d", &horario->dia);
    printf("Mes ");
    scanf("%d", &horario->mes);
    printf("Ano ");
    scanf("%d", &horario->ano);
    printf("Hora ");
    scanf("%d", &horario->hora);
    printf("Minuto ");
    scanf("%d", &horario->minuto);
}
tarefa * editaTarefa (tarefa *lista, int id){
    tarefa *p;
    p=lista;
 while (p !=NULL && id != p->id){
        p = p->prox;   
    }
    if (p == NULL){
        printf ("valor nao encontrado");
    }else{
         populaTarefa(p);
        }
    return lista;
}

 tarefa * removerTarefa (tarefa *lista,int id){
    tarefa *p, *ant;
    p=lista;
    ant = NULL;
 while (p !=NULL && id != p->id){
        ant = p;
        p = p->prox;   
    }
    if (p == NULL){
        printf ("valor nao encontrado");
        return lista;
    }else{
        if (ant == NULL){
            lista = p->prox;
        }
        else{
         ant->prox = p->prox;
        }
        free (p);
    }
    return lista;
}

tarefa * inicializa(tarefa *l){
    l = NULL;
 
    return(l);
}

tarefa * libera_lst(tarefa *l){
    while (l !=NULL ){
        l = l->prox;
        free (l); 
    }
}

void imprimeTempo (tempo horario){
    printf ("%d/%d/%d %d:%d", horario.dia, horario.mes, horario.ano, horario.hora, horario.minuto);
}