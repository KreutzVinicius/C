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

      if((arq = fopen( "arq.txt" , "rb" )) == NULL){
        printf("Erro na abertura do arquivo");
            exit(1);    
    }
    clearerr(arq);

    while (1){
        tarefa *novo;
        novo = (tarefa*)malloc(sizeof(tarefa));
        // fread(&novo, sizeof(novo), 1, arq);

        // if(fread(&novo, sizeof(novo), 1, arq) != 1)
        //     printf("Erro na leitura do arquivo");

        fread(&novo->id, sizeof(int),1,arq);
        fread(novo->dados.nome, strlen(lista->dados.nome)+1,1,arq);
        fread(&novo->dados.inicio.dia, sizeof(int),1,arq);
        fread(&novo->dados.inicio.mes, sizeof(int),1,arq);
        fread(&novo->dados.inicio.ano, sizeof(int),1,arq);
        fread(&novo->dados.inicio.hora, sizeof(int),1,arq);
        fread(&novo->dados.inicio.minuto, sizeof(int),1,arq);
        fread(&novo->dados.duracao, sizeof(int),1,arq);
        fread(&novo->dados.deadline.dia, sizeof(int),1,arq);
        fread(&novo->dados.deadline.mes, sizeof(int),1,arq);
        fread(&novo->dados.deadline.ano, sizeof(int),1,arq);
        fread(&novo->dados.deadline.hora, sizeof(int),1,arq);
        fread(&novo->dados.deadline.minuto, sizeof(int),1,arq);

        if (lista != NULL){
            mov=lista;
        while(mov->prox != NULL){
            mov = mov->prox;
        }
        mov->prox = novo;
        }else{
            lista = novo;
        }
        if(feof(arq) ) {
            break;
        }
        break;
    }
    free (mov);
    fclose(arq);
    return(lista);
}

void escreveArquivo (tarefa *lista){
    if((arq = fopen( "arq.txt" , "wb" )) == NULL){
        printf("Erro na abertura do arquivo");
            exit(1);    
    }
    tarefa *p;
    p = lista;
    while(p!=NULL){

        if( fwrite(&p, sizeof(p), 1,arq) != 1)
            printf("Erro na leitura do arquivo");
       

        // fwrite(&p->id, sizeof(int), 1 ,arq);
        // fwrite(p->dados.nome, strlen(lista->dados.nome)+1,1,arq);
        // fwrite(&p->dados.inicio.dia, sizeof(int),1,arq);
        // fwrite(&p->dados.inicio.mes, sizeof(int),1,arq);
        // fwrite(&p->dados.inicio.ano, sizeof(int),1,arq);
        // fwrite(&p->dados.inicio.hora, sizeof(int),1,arq);
        // fwrite(&p->dados.inicio.minuto, sizeof(int),1,arq);
        // fwrite(&p->dados.duracao, sizeof(int),1,arq);
        // fwrite(&p->dados.deadline.dia, sizeof(int),1,arq);
        // fwrite(&p->dados.deadline.mes, sizeof(int),1,arq);
        // fwrite(&p->dados.deadline.ano, sizeof(int),1,arq);
        // fwrite(&p->dados.deadline.hora, sizeof(int),1,arq);
        // fwrite(&p->dados.deadline.minuto, sizeof(int),1,arq);
        
        p = p->prox;
        }
        fclose(arq);
        return;
}
