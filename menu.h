#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void navigator(int action);
int first_menu();
int ok_login();
int signup(struct user_t* users_t,struct smetka_t *smetki_t);
int login(struct user_t* users_t,struct smetka_t *smetki_t,struct transaction_t* transactions_t);
void first_menu_navigator(int action, struct user_t *users_t,struct smetka_t *smetki_t,struct transaction_t* transactions_t);
#endif