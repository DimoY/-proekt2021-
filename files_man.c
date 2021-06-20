#include <stdio.h>
#include <stdlib.h>
#include "danni_i_funcii.h"

void save_user(struct user_t *users)
{
    FILE *fp = fopen("users.db", "w");

    for (struct user *user = users->head; user != NULL; user = user->next)
    {
        fwrite(user->name, sizeof(char), 100, fp);
        fwrite(user->pass, sizeof(char), 100, fp);
        fwrite(&user->id, sizeof(int), 1, fp);
    }

    fclose(fp);
}

struct user_t *load_users()
{
    struct user_t *users = malloc(sizeof(struct user_t));
    users->head = NULL;
    users->len = 0;

    FILE *fp = fopen("users.db", "r");
    if (fp == NULL)
    {
        return users;
    }

    struct user *tail = NULL;

    for (;;)
    {
        struct user *user = malloc(sizeof(struct user));
        int read_bytes = 0;
        read_bytes += fread(user->name, sizeof(char), 100, fp);
        read_bytes += fread(user->pass, sizeof(char), 100, fp);
        read_bytes += fread(&user->id, sizeof(int), 1, fp);
        user->next = NULL;

        if (read_bytes == 0)
        {
            free(user);
            break;
        }

        if (tail == NULL)
        {
            users->head = user;
        }
        else
        {
            tail->next = user;
        }

        tail = user;
        users->len++;
    }

    fclose(fp);

    return users;
}

void save_smetki(struct smetka_t *smetki)
{
    FILE *fp = fopen("smetki.db", "w");

    for (struct smetka *smetka = smetki->head; smetka != NULL; smetka = smetka->next)
    {
        fwrite(smetka->spec, sizeof(char), 20, fp);
        fwrite(&smetka->balans, sizeof(int), 1, fp);
        fwrite(&smetka->user_id, sizeof(int), 1, fp);
    }

    fclose(fp);
}

struct smetka_t *load_smetki()
{
    struct smetka_t *smetki = malloc(sizeof(struct smetka_t));
    smetki->head = NULL;

    FILE *fp = fopen("smetki.db", "r");
    if (fp == NULL)
    {
        return smetki;
    }

    struct smetka *tail = NULL;

    for (;;)
    {
        struct smetka *smetka = malloc(sizeof(struct smetka));
        int read_bytes = 0;
        read_bytes += fread(smetka->spec, sizeof(char), 20, fp);
        read_bytes += fread(&smetka->balans, sizeof(int), 1, fp);
        read_bytes += fread(&smetka->user_id, sizeof(int), 1, fp);
        smetka->next = NULL;

        if (read_bytes == 0)
        {
            free(smetka);
            break;
        }

        if (tail == NULL)
        {
            smetki->head = smetka;
        }
        else
        {
            tail->next = smetka;
        }

        tail = smetka;
    }

    fclose(fp);

    return smetki;
}

void save_transactions(struct transaction_t *transactions)
{
    FILE *fp = fopen("transactions.db", "w");

    for (struct transaction *txn = transactions->head; txn != NULL; txn = txn->next)
    {
        fwrite(txn->cod, sizeof(char), 250, fp);
        fwrite(&txn->transaction, sizeof(int), 1, fp);
        fwrite(txn->spec1, sizeof(char), 20, fp);
        fwrite(txn->spec2, sizeof(char), 20, fp);
    }

    fclose(fp);
}

struct transaction_t *load_transactions()
{
    struct transaction_t *transactions = malloc(sizeof(struct transaction_t));
    transactions->head = NULL;

    FILE *fp = fopen("transactions.db", "r");
    if (fp == NULL)
    {
        return transactions;
    }

    struct transaction *tail = NULL;

    for (;;)
    {
        struct transaction *transaction = malloc(sizeof(struct transaction));
        int read_bytes = 0;
        read_bytes += fread(transaction->cod, sizeof(char), 250, fp);
        read_bytes += fread(&transaction->transaction, sizeof(int), 1, fp);
        read_bytes += fread(transaction->spec1, sizeof(char), 20, fp);
        read_bytes += fread(transaction->spec2, sizeof(char), 20, fp);
        transaction->next = NULL;

        if (read_bytes == 0)
        {
            free(transaction);
            break;
        }

        if (tail == NULL)
        {
            transactions->head = transaction;
        }
        else
        {
            tail->next = transaction;
        }

        tail = transaction;
    }

    fclose(fp);

    return transactions;
}
