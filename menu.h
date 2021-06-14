#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct user{
    char name[100];
    char pass[100];
    struct user * next;
};

struct user_t{
    struct user* head;
    int len;
};

int first_menu();
int login(struct user_t* users_t);
int signup(struct user_t* users_t);
int ok_login();
void first_menu_navigator(int action, struct user_t* users_t);
void navigator();

#endif
