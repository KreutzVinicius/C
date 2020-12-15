#include <stdio.h>

void imprimeLista(lista *l); // imprime a lista xd
int profundidade (lista *l, int num); //calcula a distancia de uma chave especifica até o inicio
int contaLista (lista *l); // calcula quantos itens a lista possui
lista * insereFim(lista *l, int x); // insere um valor no fim da lista
lista * insereInicio (lista *l, int x); // insere um valor no inicio da lista
lista * remove (lista*l, int x);
lista * libera_lst(lista *l);
lista * inicializa(lista *l);


typedef struct reg lista;
    struct reg
    {
        int chave;
       lista * prox;
    };

int main(){
    lista *list;
    inicializa (list);

    
return 0;
}

void imprimeLista(lista *l){
    lista *p;
    p=l;

    while(p!=NULL){
        printf("%d -> ",p->chave);
        p = p->prox;
        }
        return;
}
int profundidade (lista *l, int num){
lista *p;
    p=l;
    int valor = 0;
    while (p !=NULL && p->chave != num){
        valor++;
        p = p->prox;
    }
return valor;
}

int contaLista (lista *l){
    lista *p;
    p=l;
    int count = 0;
    while (p !=NULL){
        count++;
        p = p->prox;
    }
    return count;
}

lista * insereFim(lista *l, int x){  
  lista *novo,*mov;
  novo = (lista*)malloc(sizeof(lista));
    novo->chave = x;
    novo->prox = NULL;
         if(l != NULL){
            mov=l;
            while(mov->prox != NULL){
                mov=mov->prox;
            } 
            mov->prox=novo; 
         }    
         else{
            l=novo;
        }
    return(l);
}

lista * insereInicio (lista *l, int x){
    lista *novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->chave = x;
    novo->prox = l;
return novo;
}

lista * remove (lista*l, int x){
    lista *p, *ant;
    p=l;
    ant = NULL;
 while (p !=NULL && x != p->chave){
        ant = p;
        p = p->prox;   
    }
    if (p == NULL){
        printf ("valor nao encontrado");
        return l;
    }else{
        if (ant == NULL){
            l == p -> prox;
        }
        else{
         ant->prox = p->prox;
        }
        free (p);
    }
    return l;
}
lista * libera_lst(lista *l){
    while (l !=NULL ){
        l = l->prox;
        free (l); 
    }
}
lista * inicializa(lista *l){
    l = NULL;
}
