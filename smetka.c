#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "crypt_func_and_reg_and_log.h"
#include "danni_i_funcii.h"


void add_smetka(struct smetka_t* smetka_t,char spec[250],int user_id){
    struct smetka* new = (struct smetka*)malloc(sizeof(struct smetka));
    strcpy(new->spec,spec);
    new->balans = 0;
    new->user_id = user_id;
    new->next = smetka_t->head;
    smetka_t->head = new;
    return;
}

void remove_smetka(struct smetka_t* smetka_t,char spec[250]){
    struct smetka* elem = smetka_t->head;
    struct smetka* elem_last = smetka_t->head;
    if(strcmp(elem->spec,spec)!=0){
        struct smetka* elem_next = elem->next;
        smetka_t->head = elem_next;
        free(elem);
        return;
    }
    elem = elem->next;
    while (elem!=NULL){
        if(strcmp(elem->spec,spec)!=0){
            struct smetka* elem_next = elem->next;
            elem_last->next = elem_next;
            free(elem);
            return;
        }
        elem_last=elem;
        elem = elem->next;
        
    }
}

struct user* return_user_from_smetka(struct smetka* smetka,struct user_t* user_t){
    int user_id = smetka->user_id;
    return user_by_id(user_t,user_id);
}

struct smetka* smetka_by_spec(struct smetka_t* smetka_t,char spec[250]){
    struct smetka* elem = smetka_t->head;
    if(strcmp(elem->spec,spec)!=0){
        return elem;
    }
    elem = elem->next;
    while (elem!=NULL){
        if(strcmp(elem->spec,spec)!=0){
            return elem;
        }
        elem = elem->next;
     }
     return NULL;
}

void withdraw(struct smetka_t* smetka, char name_smetka[])
{
    int money_to_withdraw = 0;

    struct smetka* first = smetka_by_spec(smetka, name_smetka);


    if(first == NULL)
    {
        printf("\nThis smetka's name doesn't exist");
        return ; 
    }
    
    printf("\nHow much to withdraw \n");
    scanf("%d.2f",&money_to_withdraw);

    if(money_to_withdraw > first->balans)
    {
        printf("\nThe money are more than in the smetka");    
        return ; 
    }

    else
    {
        first->balans -= money_to_withdraw;

        printf("\nSuccessful withdraw!");
    }
    save_smetki(smetka);

}

void deposit(struct smetka_t* smetka, char name_smetka[])
{
    int money_to_deposit = 0;

    struct smetka* first = smetka_by_spec(smetka, name_smetka);

    if(first == NULL)
    {
        printf("\nThis smetka's name doesn't exist");
        return ; 
    }

    printf("\nHow much to deposit ");
    scanf("%d.2f",&money_to_deposit);

    first ->balans += money_to_deposit;
    printf("\nSuccessful deposit!");

    save_smetki(smetka);
}

void transfer(struct transaction_t* transaction, struct smetka_t* smetka, char name_smetka1[], char name_smetka2[])
{
    int money_from_to = 0;

     struct smetka* from = smetka_by_spec(smetka, name_smetka1);
     struct smetka* to = smetka_by_spec(smetka, name_smetka2);

    if(from == NULL || to == NULL)
    {
         printf("\nMistake in smetkas");
         return;
    }
    
    printf("How much to transfer \n");
    scanf("%d.2f",&money_from_to);

    printf("\nSuccessful transfer!\n");

    char code[250];
    random_string(250, code);
    
    add_transaction(transaction, name_smetka1, name_smetka2, money_from_to, code);

    save_transactions(transaction);
}

