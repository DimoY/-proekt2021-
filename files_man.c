#include <stdio.h>
#include <stdlib.h>
#include "danni_i_funcii.h"

void save_usering(struct user_t *users){
    FILE *fp = fopen("users.db", "w");
    for (struct user *user = users->head; user != NULL; user = user->next)
    {
        fwrite(user->name, sizeof(char), 100, fp);
        fwrite(user->pass, sizeof(char), 100, fp);
    }

    fclose(fp);
}