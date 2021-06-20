#include "danni_i_funcii.h"
#include <stdlib.h>
#include <string.h>

void add_transaction(struct transaction_t *transaction_t, char spec1[10], char spec2[10], int transaction, char cod[250])
{
    struct transaction *new = (struct transaction *)malloc(sizeof(struct transaction));
    strcpy(new->spec1, spec1);
    strcpy(new->spec2, spec2);
    strcpy(new->cod, cod);
    new->transaction = transaction;
    new->next=NULL;
    if (!transaction_t->head)
    {
        transaction_t->head = new;
        transaction_t->tail = new;
        return;
    }

    new->before = transaction_t->tail;
    transaction_t->tail->next = new;
    transaction_t->tail = new;
}
