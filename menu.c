#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include "crypt_func_and_reg_and_log.h"
#include "danni_i_funcii.h"

int first_menu(){

    char option[10]; 
    int flag = 0;

    while(flag == 0){
    printf("Sign in\nSign up\nExit\n");
    fgets(option, 10, stdin);

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

int login(struct user_t* users_t){
    char username[251];
    char pass[250];
    
    printf("Username:");
    fgets(username, 251, stdin);
    username[strcspn(username, "\n")] = 0;
    
    printf("Password:");
    fgets(pass, 250, stdin);
    pass[strcspn(pass, "\n")] = 0;
    crypt(pass);
    
    if(check_user(users_t,username,pass) == 1){
        int action =  ok_login();
        if(action == 1){
            printf("Deposit sUS");
            //deposit
        }
        else if(action == 2){
            printf("Withdrawal sUS");
            //withdrawal
        }
        else if(action == 3){
            printf("Transfer sUS");
            //transfer
        }
        else if(action == 4){
            printf("Transaction processing sUS");
           //transaction processing
        }
        else if(action == 5){
            printf("Log out sUS");
            //Log out
            //free(everything)
            first_menu();

        }
    }
    else printf("No such account foundet\n Try again or Sign up:");
  return 0;
}

int signup(struct user_t* users_t){
    char username[251];
    char pass[250];
    printf("Username:");
    fgets(username,250,stdin);
    username[strcspn(username, "\n")] = 0;
    printf("password:");
    fgets(pass,250,stdin);
    pass[strcspn(pass, "\n")] = 0;
    crypt(pass);
    add_user(users_t,username,pass);
    return 0;
}

int ok_login(){
    char option[25]; 
    int flag = 0;

    while(flag == 0){
    printf("Deposit\nWithdrawal\nTransfer\nTransaction Processing\nLog out\n");
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
    else if(strstr(option,"Transaction Processing")){
        flag++;
        return 4;
    }
    else if(strstr(option,"Log out")){
        flag++;
        return 5;
    }
    printf("You have selected invalite action. Please select again.\n");
    }
}

void first_menu_navigator(int action, struct user_t *users_t){
    if(action == 1){
        login(users_t);
    }
    else{
        if(action == 2){
            signup(users_t);
        }
        else{
            navigator(3);
        }       
    }
}

void navigator(int action){
    struct user_t users_t = {NULL};
    if(action == 3){
        return ;
    }
    action = first_menu();
    first_menu_navigator(action,&users_t);
        
}
