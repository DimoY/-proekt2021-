#include "danni_i_funcii.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int add_user(struct user_t* user_t,char name[250],char pass[250]){
    if(user_by_name(user_t,name)==1){
        return -1;
    }
    struct user* new = (struct user*)malloc(sizeof(struct user));
    strcpy(new->pass,pass);
    strcpy(new->name,name);
    new->next = user_t->head;
    user_t->head = new;
    user_t->len+=1;
    return user_t->len;
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

int user_by_name(struct user_t* user_t,char name[100]){
    struct user* elem = user_t->head;
    while (elem!=NULL){
        if(strcmp(elem->name,name)==0){
            return 1;
        }
        elem = elem->next;
     }
     return 0;
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
int id_by_user(struct user_t* user_t,char name[100]){
    struct user* elem = user_t->head;
    int i = 1;
    while (elem!=NULL){
        if(strcmp(elem->name,name)==0){
            return i;
        }
        elem = elem->next;
        i++;
     }
     return -1;
}
int check_user(struct user_t* user_t,char name[100],char pass[100]){
    
    if(user_t->head != NULL){
        struct user* elem = user_t->head;

        if(strcmp(elem->name,name)==0 && strcmp(elem->pass,pass)==0){
            return 1;
        }
        elem = elem->next;
        while (elem!=NULL){
            if(strcmp(elem->name,name)==0 && strcmp(elem->pass,pass)==0){
                return 1;
            }
            elem = elem->next;   
        }
    }
    return 0;
}
struct smetka* return_smetka_from_user(struct smetka_t* smetka,int id){
    struct smetka* elem = smetka->head;
    while (elem!=NULL){
        if(elem->user_id = id){
            return elem;
        }
        elem = elem->next;
     }
    return NULL;
}