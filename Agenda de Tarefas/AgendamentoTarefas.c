#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AgendamentoTarefas.h"

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
  printf ("|-----------------------------------------|\n\n");
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

tarefa * carregaArquivo ( tarefa *lista){
    tarefa *mov;

    if((arq = fopen( "arq.txt" , "rt" )) == NULL){
        printf("Erro na abertura do arquivo");
            exit(1);    
    }

    tarefa *novo,aux;
  

    while(fscanf(arq,"%d %s %d %d %d %d %d %d %d %d %d %d %d",&aux.id,aux.dados.nome,&aux.dados.inicio.ano,&aux.dados.inicio.dia,&aux.dados.inicio.hora,&aux.dados.inicio.mes,&aux.dados.inicio.minuto,&aux.dados.duracao,&aux.dados.deadline.minuto,&aux.dados.deadline.mes,&aux.dados.deadline.hora,&aux.dados.deadline.dia,&aux.dados.deadline.ano) == 13) { 
        if (lista == NULL){
        lista = (tarefa*)malloc(sizeof(tarefa));
        lista->id = aux.id ;
        strcpy(lista->dados.nome,aux.dados.nome);
        lista->dados.inicio.dia = aux.dados.inicio.dia;
        lista->dados.inicio.mes = aux.dados.inicio.mes;
        lista->dados.inicio.ano = aux.dados.inicio.ano;
        lista->dados.inicio.hora = aux.dados.inicio.hora;
        lista->dados.inicio.minuto = aux.dados.inicio.minuto;
        lista->dados.duracao = aux.dados.duracao;
        lista->dados.deadline.dia = aux.dados.deadline.dia;
        lista->dados.deadline.mes = aux.dados.deadline.mes;
        lista->dados.deadline.ano = aux.dados.deadline.ano;
        lista->dados.deadline.hora = aux.dados.deadline.hora;
        lista->dados.deadline.minuto = aux.dados.deadline.minuto;
        
        lista->prox = NULL;

        }else {        
            novo = (tarefa*)malloc(sizeof(tarefa));
            novo->id = aux.id ;
            strcpy(novo->dados.nome,aux.dados.nome);
            novo->dados.inicio.dia = aux.dados.inicio.dia;
            novo->dados.inicio.mes = aux.dados.inicio.mes;
            novo->dados.inicio.ano = aux.dados.inicio.ano;
            novo->dados.inicio.hora = aux.dados.inicio.hora;
            novo->dados.inicio.minuto = aux.dados.inicio.minuto;
            novo->dados.duracao = aux.dados.duracao;
            novo->dados.deadline.dia = aux.dados.deadline.dia;
            novo->dados.deadline.mes = aux.dados.deadline.mes;
            novo->dados.deadline.ano = aux.dados.deadline.ano;
            novo->dados.deadline.hora = aux.dados.deadline.hora;
            novo->dados.deadline.minuto = aux.dados.deadline.minuto;

            mov=lista;
            while(mov->prox != NULL){
                mov = mov->prox;
            }
            mov->prox = novo;
            novo->prox = NULL;  
        }
            

        if(feof(arq)) {
            break;
        }
    }
    fclose(arq);
    return(lista);
}


void escreveArquivo (tarefa *lista){
    if((arq = fopen( "arq.txt" , "wt" )) == NULL){
        printf("Erro na abertura do arquivo");
            exit(1);    
    }
    tarefa *p;
    p = lista;

    while(p!=NULL){
        fprintf(arq, "%d %s %d %d %d %d %d %d %d %d %d %d %d \n", p->id,p->dados.nome,p->dados.inicio.dia,p->dados.inicio.mes,p->dados.inicio.ano,p->dados.inicio.hora,p->dados.inicio.minuto,p->dados.duracao,p->dados.deadline.dia,p->dados.deadline.mes,p->dados.deadline.ano,p->dados.deadline.hora,p->dados.deadline.minuto);   
        p = p->prox;
        }
        fclose(arq);
        return;
}

tarefa * computaAgenda (tarefa *lista){
    tarefa *p= NULL, *agenda= NULL, *novo= NULL, *mov= NULL;
    char data1[12], data2[12] = "999999999999";
    p = lista;
    int cargaHoraria = 480; //480 minutos = 8 horas
    if (p != NULL){
        while (cargaHoraria > 0){
            while (p->prox != NULL){
                sprintf(data1, "%d%d%d%d%d",p->dados.deadline.ano, p->dados.deadline.mes, p->dados.deadline.dia, p->dados.deadline.hora,p->dados.deadline.minuto); 
                if (strcmp(data1,data2) < 0){
                    strcpy(data2,data1);
                }
                p = p->prox;
            } 
                p = lista;
                while (p != NULL){
                    sprintf(data1, "%d%d%d%d%d",p->dados.deadline.ano, p->dados.deadline.mes, p->dados.deadline.dia, p->dados.deadline.hora,p->dados.deadline.minuto);
                    if (strcmp(data1,data2) == 0){
                        cargaHoraria = cargaHoraria - p->dados.duracao;
                        if (agenda == NULL){

                            agenda = (tarefa*)malloc(sizeof(tarefa));
                            agenda->id = p->id ;
                            strcpy(agenda->dados.nome,p->dados.nome);
                            agenda->dados.inicio.dia = p->dados.inicio.dia;
                            agenda->dados.inicio.mes = p->dados.inicio.mes;
                            agenda->dados.inicio.ano = p->dados.inicio.ano;
                            agenda->dados.inicio.hora = p->dados.inicio.hora;
                            agenda->dados.inicio.minuto = p->dados.inicio.minuto;
                            agenda->dados.duracao = p->dados.duracao;
                            agenda->dados.deadline.dia = p->dados.deadline.dia;
                            agenda->dados.deadline.mes = p->dados.deadline.mes;
                            agenda->dados.deadline.ano = p->dados.deadline.ano;
                            agenda->dados.deadline.hora = p->dados.deadline.hora;
                            agenda->dados.deadline.minuto = p->dados.deadline.minuto;
                            
                            agenda->prox = NULL;
                            
                            p = removerTarefa(lista, agenda->id);
                            
                        }else {

                            novo = (tarefa*)malloc(sizeof(tarefa));
                            novo->id = p->id ;
                            strcpy(novo->dados.nome,p->dados.nome);
                            novo->dados.inicio.dia = p->dados.inicio.dia;
                            novo->dados.inicio.mes = p->dados.inicio.mes;
                            novo->dados.inicio.ano = p->dados.inicio.ano;
                            novo->dados.inicio.hora = p->dados.inicio.hora;
                            novo->dados.inicio.minuto = p->dados.inicio.minuto;
                            novo->dados.duracao = p->dados.duracao;
                            novo->dados.deadline.dia = p->dados.deadline.dia;
                            novo->dados.deadline.mes = p->dados.deadline.mes;
                            novo->dados.deadline.ano = p->dados.deadline.ano;
                            novo->dados.deadline.hora = p->dados.deadline.hora;
                            novo->dados.deadline.minuto = p->dados.deadline.minuto;

                            mov = agenda;
                            while (mov->prox != NULL){
                            mov = mov->prox;
                            }
                            mov->prox = novo;
                            novo->prox = NULL;
                            p = removerTarefa(lista, novo->id);
                        }
                    } 
                        p = p->prox;   
                }
        }
        return(agenda);
    } else printf("nao existem tarefas para serem concluidas");

    return 0;
}

void escreveDiarias (tarefa *lista){
    if((arq = fopen( "arqDiarias.txt" , "wt" )) == NULL){
        printf("Erro na abertura do arquivo");
            exit(1);    
    }
    tarefa *p;
    p = lista;

    while(p!=NULL){
        fprintf(arq, "%d %s %d %d %d %d %d %d %d %d %d %d %d \n", p->id,p->dados.nome,p->dados.inicio.dia,p->dados.inicio.mes,p->dados.inicio.ano,p->dados.inicio.hora,p->dados.inicio.minuto,p->dados.duracao,p->dados.deadline.dia,p->dados.deadline.mes,p->dados.deadline.ano,p->dados.deadline.hora,p->dados.deadline.minuto);
        p = p->prox;
        }
        fclose(arq);
        return;
}