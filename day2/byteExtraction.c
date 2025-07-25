#include<stdio.h>

int main(){
    unsigned int hexNum;
    unsigned char a,b,c,d;

    //inputing hexNum
    scanf("%x",&hexNum);

    //extracting
    a=hexNum&0xFF; //lsb
    b=(hexNum>>8)&0xFF;
    c=(hexNum>>16)&0xFF;
    d=(hexNum>>24)&0xFF;

    //printing
    printf("bit 1: 0x%02X\n",a);
    printf("bit 2: 0x%02X\n",b);
    printf("bit 3: 0x%02X\n",c);
    printf("bit 4: 0x%02X\n",d);



    return 0;
}