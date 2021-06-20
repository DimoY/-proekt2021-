#include "crypt_func_and_reg_and_log.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void random_string(int leng,char* word){
    char sym[]=RAND_STR;
    for(int i=0;i<leng-1;i++){
        int m = rand()%78;
        word[i] = sym[m];
    }
    word[leng-1] = '\0';
}

void crypter(char* e){
    //impl https://en.wikipedia.org/wiki/Adler-32
    int A=e[0]+1;
    int B=A;
    for(int i =1;e[i]!='\0';i++){
        A=(e[i]+A);
        B=(A+B);
    }
    sprintf(e, "%d", (B<<16)|A);
}
void crypt(char* pass){
    crypter(pass);
}

