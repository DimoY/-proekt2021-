#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

int first_menu();
int ok_login();
int signup(struct user_t* users_t,struct smetka_t *smetki_t);
int login(struct user_t* users_t,struct smetka_t *smetki_t);
void first_menu_navigator(int action, struct user_t *users_t,struct smetka_t *smetki_t);
void navigator(int action);
#endif