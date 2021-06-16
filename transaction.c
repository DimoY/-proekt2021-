#include "danni_i_funcii.h"
#include <stdlib.h>
#include <string.h>

void add_transaction(struct transaction_t* smetka_t,char spec1[250],char spec2[250],int transaction,char cod[250]){
    struct transaction* new = (struct transaction*)malloc(sizeof(struct transaction));
    strcpy(new->spec1,spec1);
    strcpy(new->spec2,spec2);
    strcpy(new->cod,cod);
    new->transaction = transaction;
    new->next = smetka_t->head;
    smetka_t->head = new;
    return;
}
void remove_transaction(struct transaction_t* transaction_t,char cod[250]){
    struct transaction* elem = transaction_t->head;
    struct transaction* elem_last = transaction_t->head;
    if(strcmp(elem->cod,cod)!=0){
        struct transaction* elem_next = elem->next;
        transaction_t->head = elem_next;
        free(elem);
        return;
    }
    elem = elem->next;
    while (elem!=NULL){
        if(strcmp(elem->cod,cod)!=0){
            struct transaction* elem_next = elem->next;
            elem_last->next = elem_next;
            free(elem);
            return;
        }
        elem_last=elem;
        elem = elem->next;
        
    }
}

