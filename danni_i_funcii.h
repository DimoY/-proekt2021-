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

struct smetka{
    char spec[250];
    int balans;
    int user_id;
    struct smetka* next; 
};

struct smetka_t{
    struct smetka* head;
};
struct transaction{
    char cod[250];
    int transaction;
    char spec1[250];
    char spec2[250];
    struct transaction* next; 
};

struct transaction_t{
    struct transaction* head;
};
void add_user(struct user_t* user_t,char name[250],char pass[250]);
void remove_user(struct user_t* user_t,char name[250]);
void add_smetka(struct smetka_t* smetka_t,char spec[250],int user_id);
void add_transaction(struct transaction_t* smetka_t,char spec1[250],char spec2[250],int transaction,char cod[250]);
void remove_transaction(struct transaction_t* transaction_t,char cod[250]);
void remove_smetka(struct smetka_t* smetka_t,char spec[250]);
struct user* user_by_id(struct user_t* user_t,int id);
struct user* return_user_from_smetka(struct smetka* smetka,struct user_t* user_t);
struct smetka* smetka_by_spec(struct smetka_t* smetka_t,char spec[250]);
void return_users_from_trans(struct transaction* transaction,struct user_t* user_t,struct smetka_t* smetka_t,struct user* list[2]);
int check_user(struct user_t* user_t,char name[250],char pass[250]);
void transfer(struct smetka_t* smetka, char name_smetka1[], char name_smetka2[]);
void deposit(struct smetka_t* smetka, char name_smetka[]);
void withdraw(struct smetka_t* smetka, char name_smetka[]);
#endif


