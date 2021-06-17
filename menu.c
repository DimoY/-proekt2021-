#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "crypt_func_and_reg_and_log.h"
#include "danni_i_funcii.h"
#include "menu.h"

int first_menu(){

    char option[50]; 
    int flag = 0;

    while(flag == 0){
    printf("Sign in\nSign up\nExit\n");
    fgets(option, 50, stdin);

    if(strstr(option,"Sign in")){
        flag++;
        return 1;
    }
    else if(strstr(option,"Sign up")){
        flag++;
        return 2;
    }
    else if(strstr(option,"Exit")){
        flag++;
        return 3;
    }
    printf("You have selected invalite action. Please select again.\n");
    }
}

int ok_login(){
    char option[25]; 
    int flag = 0;

    while(flag == 0){
    printf("Deposit\nWithdrawal\nTransfer\nLog out\n");
    fgets(option, 25, stdin);

    if(strstr(option,"Deposit")){
        flag++;
        return 1;
    }
    else if(strstr(option,"Withdrawal")){
            flag++;
            return 2;
    }   
    else if(strstr(option,"Transfer")){
        flag++;
        return 3;
    }
    else if(strstr(option,"Log out")){
        flag++;
        return 4;
    }
    printf("You have selected invalite action. Please select again.\n");
    }
}


int login(struct user_t* users_t,struct smetka_t *smetki_t){
    char username[100];
    char pass[100];
    char option[100];

    printf("Username:");
    fgets(username, 100, stdin);
    username[strcspn(username, "\n")] = 0;
    
    printf("Password:");
    fgets(pass, 100, stdin);
    pass[strcspn(pass, "\n")] = 0;
    crypt(pass);
//printing first menu after every run 
    if(check_user(users_t,username,pass) == 1){
        int action =  ok_login();
        if(action == 1){
            deposit(&smetki_t, username);
            return;
        }
        else if(action == 2){
            printf("Withdrawal sUS\n");
            withdraw(&smetki_t, username);
            return;
        }
        else if(action == 3){
            printf("Transfer sUS\n");
            //transfer(struct transaction_t* transaction, struct smetka_t* smetka, char name_smetka1[], char name_smetka2[]);
            return;
        }
        else if(action == 4){
            navigator(1);
        }
    }
    else{ printf("No such account founded. Try again or Sign up:\n");
        label: fgets(option, 100, stdin);
        if(strstr(option,"Try again")){
            login(&users_t,&smetki_t);
        }
        else if(strstr(option, "Sign up")){
            signup(&users_t,&smetki_t);
        }
        else{
            printf("Invalide action. Please Try again or Sign up:\n");
            goto label;
        }
    }

  return 0;
}

int signup(struct user_t* users_t,struct smetka_t *smetki_t){
    static int users_ids = 1;
    char username[100];
    char pass[100];
    
    printf("Username:");
    fgets(username,100,stdin);
    username[strcspn(username, "\n")] = 0;
    printf("Password:");
    fgets(pass,100,stdin);
    pass[strcspn(pass, "\n")] = 0;
    crypt(pass);   
    add_user(&users_t,username,pass);
    add_smetka(&smetki_t,username,users_ids++); 
    save_user(&users_t);
    save_smetki(&smetki_t);
    return 0;
}


void first_menu_navigator(int action, struct user_t *users_t,struct smetka_t *smetki_t){
    if(action == 1){
        login(&users_t,&smetki_t);
    }
    else if(action == 2){
            signup(&users_t,&smetki_t);
        }     
}

void navigator(int action){
    int i = 0;
        struct user_t* users_t = load_users();
        struct smetka_t* smetki_t = load_smetki();
    while(action != 3){
        action = first_menu();
        first_menu_navigator(action,&users_t,&smetki_t);
    }
 return; 
}
