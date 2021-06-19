#ifndef FUNCTIONS_Z_INCLUDED
#define FUNCTIONS_Z_INCLUDED

void navigator(int action);
int first_menu();
int ok_login();
int signup(struct user_t* users_t,struct smetka_t *smetki_t,char smetka[250]);
int login(struct user_t* users_t,struct smetka_t *smetki_t, struct transaction_t* transactions_t,char smetka[250]);
void first_menu_navigator(int action, struct user_t *users_t,struct smetka_t *smetki_t, struct transaction_t* transactions_t,char smetka[250]);
#endif