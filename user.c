#include "danni_i_funcii.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void add_user(struct user_t* user_t,char name[250],char pass[250]){
    struct user* new = (struct user*)malloc(sizeof(struct user));
    strcpy(new->pass,pass);
    strcpy(new->name,name);
    new->next = user_t->head;
    user_t->head = new;
    user_t->len+=1;
    return;
}

void remove_user(struct user_t* user_t,char name[250]){
    struct user* elem = user_t->head;
    struct user* elem_last = user_t->head;
    if(strcmp(elem->name,name)!=0){
        struct user* elem_next = elem->next;
        user_t->head = elem_next;
        free(elem);
        user_t->len-=1;
        return;
    }
    elem = elem->next;
    while (elem!=NULL){
        if(strcmp(elem->name,name)!=0){
            struct user* elem_next = elem->next;
            elem_last->next = elem_next;
            free(elem);
            user_t->len-=1;
            return;
        }
        elem_last=elem;
        elem = elem->next;
        
    }
}

struct user* user_by_id(struct user_t* user_t,int id){
    id = user_t->len-id;
    struct user* elem = user_t->head;
    if(id == 0){
        return elem;
    }
    elem = elem->next;
    int i = 0;
    while (elem!=NULL){
        i++;
        if(id == i){
            return elem;
        }
        elem = elem->next;
        
    }
    return NULL;
}
int check_user(struct user_t* user_t,char name[250],char pass[250]){
    struct user* elem = user_t->head;
    while (elem!=NULL){
        if(!strcmp(elem->name,name) && !strcmp(elem->pass,pass)){
            return 1;
        }
        elem = elem->next;
        
    }
    return 0;
}