#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt_func_and_reg_and_log.h"
#include "danni_i_funcii.h"
#include "menu.h"

void Login(struct user_t* users_t){
    char username[251];
    char pass[250];
    fgets(username,250,stdin);
    username[strcspn(username, "\n")] = 0;
    fgets(pass,250,stdin);
    pass[strcspn(pass, "\n")] = 0;
    crypt(pass);
    if(check_user(users_t,username,pass)==1){
        printf("logedin\n");
    }else{
        printf("unable\n");
    }
}
int main(int argc, char const *argv[])
{
    FILE *fp;
    fp = fopen("users.db","w+");
    char word[250];
    random_string(250,word);
    struct user_t users_t = {NULL};
    struct smetka_t smetka_t = {NULL};
    struct transaction_t transaction_t = {NULL};
    navigator(0);
    printf("found %s",user_by_id(&users_t,2)->name);
    return 0;
}
