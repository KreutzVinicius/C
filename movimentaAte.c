void movimentaAte (Fila * f, No* c){
    int i = 0, j=0;
    No* primeiro;
    f->ini = primeiro;
    while (i==0){
    if (f->ini->info == c->info){
        printf("veiculo passou");
        i = 1;

        while (j==0){
            if (f->ini == primeiro){
                printf("fila na ordem original");
                j=1;

            } else {
                No* t;
                t = f->ini;
                f->ini = t->prox;

            if (f->ini == NULL)
                f->fim = NULL;

                f->fim = t;
            }

        }   
    } else {
        No* t;
        t = f->ini;
        f->ini = t->prox;

    if (f->ini == NULL)
         f->fim = NULL;

        f->fim = t;
    }
    }
}