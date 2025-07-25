#include<stdio.h>

int main(){
    unsigned int a;
    char *c=(char*)&a;

    scanf("%x",&a);

    if(*c==(a&0xFF)){
        printf("Little Endian\n");
    }else{
        printf("Big Endian");
    }

    return 0;
}