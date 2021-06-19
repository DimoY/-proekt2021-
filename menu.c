#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "crypt_func_and_reg_and_log.h"
#include "danni_i_funcii.h"
#include "menu.h"
int first_menu();
int ok_login();
int signup(struct user_t* users_t,struct smetka_t *smetki_t);
int login(struct user_t* users_t,struct smetka_t *smetki_t, struct transaction_t* transactions_t);
void first_menu_navigator(int action, struct user_t *users_t,struct smetka_t *smetki_t, struct transaction_t* transactions_t);
void navigator(int action);



int first_menu(){

    int option; 
    int flag = 0;
    while(flag == 0){
    printf("1:Log\n============\n2:Register\n============\n0:Exit\n============ \n");
    scanf("%d", option);
    getchar();

    if(option == 1 || option == 2){
        flag++;
        return option;
    }
    else if(option == 0){
        exit(0);
    }
    printf("You have selected invalite action. Please select again.\n");
    }
}

int ok_login(){
    int flag = 0;
    int option; 

        while(1){
            printf("\n1:Deposit\n============\n2:Withdraw\n============\n3:Transfer\n============\n0:Exit\n============\n");
            scanf( "%d" , option ); 
            if(option == 1 || option == 2 || option == 3 || option == 0){
                break;
            }
            printf("You have selected invalite action. Please select again.\n");
            }
    return option;

}




int login(struct user_t* users_t,struct smetka_t *smetki_t, struct transaction_t* transactions_t){
    char username[100];
    char username2[100];
    char pass[100];
    char option[100];
    int action = 0;

    printf("Username:");
    fgets(username, 100, stdin);
    username[strcspn(username, "\n")] = 0;
    
    printf("Password:");
    fgets(pass, 100, stdin);
    pass[strcspn(pass, "\n")] = 0;
    crypt(pass);

    while (action!=4)
    {
        if(check_user(users_t,username,pass) == 1){
        action =  ok_login();
        if(action == 1){
            printf("\n============\n");

            deposit(smetki_t, return_smetka_from_user(smetki_t, id_by_user(users_t,username))->spec);

        }
        else if(action == 2){
            printf("\n============\n");
            withdraw(smetki_t, return_smetka_from_user(smetki_t, id_by_user(users_t,username))->spec);
        }
        else if(action == 3){
            printf("\n============\n");
            printf("Name of accout to transfer:\n");
            scanf("%s",username2);
            transfer(transactions_t, smetki_t, return_smetka_from_user(smetki_t, id_by_user(users_t,username))->spec, username2);
            process_transaction(transactions_t->head, smetki_t);
        }
        else if(action == 4){
            printf("\n============\n");
            navigator(1);
        }
    }
    else{ 
        printf("No such account founded. Try again or Sign up:\n");
        label: fgets(option, 100, stdin);
        if(strstr(option,"Try again")){
            login(users_t,smetki_t,transactions_t);
        }
        else if(strstr(option, "Sign up")){
            signup(users_t,smetki_t);
        }
        else{
            printf("Invalide action. Please Try again or Sign up:\n");
            goto label;
        }
    }
    }
  return 0;
}
void first_menu_navigator(int action, struct user_t *users_t,struct smetka_t *smetki_t, struct transaction_t* transactions_t){
    if(action == 1){
        login(users_t,smetki_t,transactions_t);
        return;
    }
    else if(action == 2){
            signup(users_t,smetki_t);
            return;
        }     
}

void navigator(int action){    
    struct user_t* users_t = load_users();
    struct smetka_t* smetki_t = load_smetki();
    struct transaction_t* transactions_t = load_transactions();
    while(action != 3){
        action = first_menu();
        first_menu_navigator(action,users_t,smetki_t,transactions_t);
    }
 return; 
}