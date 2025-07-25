#include<stdio.h>

int main(){
    unsigned int a=1;
    char *c=(char*)&a;

    if(*c==1){
        printf("Little Endian\n");
    }else{
        printf("Big Endian");
    }

    return 0;
}