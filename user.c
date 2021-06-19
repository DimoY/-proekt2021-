#include "danni_i_funcii.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int add_user(struct user_t* user_t,char name[250],char pass[250]){
    if(user_by_name(user_t,name)!=NULL){
        return -1;
    }
    struct user* new = (struct user*)malloc(sizeof(struct user));
    strcpy(new->pass,pass);
    strcpy(new->name,name);
    new->next = user_t->head;
    user_t->head = new;
    user_t->len+=1;
    new->id = user_t->len;
    return user_t->len;
}

struct user* user_by_name(struct user_t* user_t,char name[100]){
    struct user* elem = user_t->head;
    while (elem!=NULL){
        if(strcmp(elem->name,name)==0){
            return elem;
        }
        elem = elem->next;
     }
     return NULL;
}


int id_by_user(struct user_t* user_t,char name[100]){
    struct user* elem = user_t->head;
    while (elem!=NULL){
        if(strcmp(elem->name,name)==0){
            return elem->id;
        }
        elem = elem->next;
     }
     return -1;
}
int check_user(struct user_t* user_t,char name[100],char pass[100]){
    struct user* elem = user_by_name(user_t,name);
    if(elem!=NULL){
        if(strcmp(pass,elem->pass)==0){
            return 1;
        }
    }
    return 0;
}
struct smetka* return_smetka_from_user(struct smetka_t* smetka,int id){
    struct smetka* elem = smetka->head;
    while (elem!=NULL){
        if(elem->user_id == id){
            return elem;
        }
        elem = elem->next;
     }
    return NULL;
}
