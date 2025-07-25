#include<stdio.h>

int main(){

    unsigned int a;
    char *ptr=(char*)&a;

    scanf("%x",&a);

    for(int i=0;i<sizeof(a);i++){
        printf("address:%p content:0x%02X\n",(ptr+i),*(ptr+i));
    }
    
    return 0;
}