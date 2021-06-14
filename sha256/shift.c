#include <stdio.h>
#include <stdlib.h>

unsigned int shift(unsigned int one, unsigned int shifter){
    return one>>shifter;
}

unsigned int xor(unsigned int one,unsigned int two){
    return one^two;
}

unsigned int rotate(unsigned int one,unsigned int rotations){
    int Lsb;

    while(rotations--){
      Lsb = one & 1;
      one = (one >> 1) &(~(1<<sizeof(unsigned int)));
      one=one|(Lsb<<sizeof(unsigned int));
   }
   return one;
}
unsigned int add(unsigned int one,unsigned int two, unsigned int three,unsigned int four){
    unsigned long int  sum= (unsigned long int)one+(unsigned long int)two+(unsigned long int)three+(unsigned long int)four;
    return (unsigned int) sum;
}

void printBits(unsigned int num)
{
    printf("\n");
    for(int bit=0;bit<(sizeof(unsigned int) * 8); bit++)
    {
        printf("%i ", num & 0x01);
        num = num >> 1;
    }
    printf("\n");
}

int main()
{

    int one = 0b00000000000111000000000000011111;
    int two = 0b00000000000000000000000000000000;
    int three = 0b10000100000000000000000000000000;
    int four = 0b10000010000000000000000000000000;
    
    printBits(one);
    printBits(shift(one,10));
    printBits(rotate(one,20));
    printBits(xor(one,two));
    printBits(add(one,two,three,four));
    return 0;
}
