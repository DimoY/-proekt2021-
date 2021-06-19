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
    struct transaction* before; 
};

struct transaction_t{
    struct transaction* head;
    struct transaction* tail;
};
int add_user(struct user_t* user_t,char name[250],char pass[250]);
void remove_user(struct user_t* user_t,char name[250]);
void add_smetka(struct smetka_t* smetka_t,char spec[250],int user_id);
void add_transaction(struct transaction_t* smetka_t,char spec1[250],char spec2[250],int transaction,char cod[250]);
void remove_smetka(struct smetka_t* smetka_t,char spec[250]);
int user_by_name(struct user_t* user_t,char name[100]);
struct user* user_by_id(struct user_t* user_t,int id);
struct user* return_user_from_smetka(struct smetka* smetka,struct user_t* user_t);
struct smetka* smetka_by_spec(struct smetka_t* smetka_t,char spec[250]);
int check_user(struct user_t* user_t,char name[250],char pass[250]);
void save_user(struct user_t *users);
struct user_t *load_users();
void save_smetki(struct smetka_t *smetki);
struct smetka_t *load_smetki();
void save_transactions(struct transaction_t *transactions);
struct transaction_t *load_transactions();
void withdraw(struct smetka_t* smetka, char name_smetka[]);
void deposit(struct smetka_t* smetka, char name_smetka[]);
void transfer(struct transaction_t* transaction, struct smetka_t* smetka, char name_smetka1[], char name_smetka2[]);
void process_transaction(struct transaction *txn, struct smetka_t *smetki);
void process_transactions(struct transaction_t *txn_list, struct smetka_t *smetki);
#endif


