#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt_func_and_reg_and_log.h"
#include "danni_i_funcii.h"

void Register(struct user_t* users_t){
    char username[251];
    char pass[250];
    fgets(username,250,stdin);
    username[strcspn(username, "\n")] = 0;
    fgets(pass,250,stdin);
    pass[strcspn(pass, "\n")] = 0;
    crypt(pass);
    add_user(users_t,username,pass);
    
}
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
    struct transaction_t transaction_t = {NULL,NULL};
    Register(&users_t);
    Register(&users_t);
    printf("found %s",user_by_id(&users_t,2)->name);
    save_user(&users_t);
    load_users();
    add_smetka(&smetka_t, "Dimo", 23);
    add_smetka(&smetka_t, "Qna", 23);
    save_smetki(&smetka_t);
    load_smetki();
    save_transactions(&transaction_t);
    load_transactions();
    deposit(&smetka_t, "Dimo");
    withdraw(&smetka_t, "Dimo");
    transfer(&transaction_t, &smetka_t, "Dimo", "Qna");
    process_transactions(&transaction_t, &smetka_t);
    transfer(&transaction_t, &smetka_t, "Qna", "Dimo");
    process_transactions(&transaction_t, &smetka_t);
    return 0;
}

