#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt_func_and_reg_and_log.h"
#include "danni_i_funcii.h"
#include "menu.h"

int signup(struct user_t* users_t,struct smetka_t *smetki_t){
    char username[100];
    char pass[100];
    int id = 0;
    printf("Username:");
    fgets(username,100,stdin);
    username[strcspn(username, "\n")] = 0;
    printf("Password:");
    fgets(pass,100,stdin);
    pass[strcspn(pass, "\n")] = 0;
    crypt(pass);   
    id = add_user(users_t,username,pass);
    char word[250];
    random_string(250,word);
    add_smetka(smetki_t,word,id); 
    save_user(users_t);
    save_smetki(smetki_t);
    return 0;
}