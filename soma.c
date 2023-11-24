#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
    char num[1024];
    char c[1];
    int sz;
}numero;

void soma(char *x, char *y, int sz, char *s){
    int carry = 0, e = 0;
    numero carga;
    memset(s,'\0',sz+1);
    for(int i = sz-1; i >= 0; i--){
        e = (x[i] - '0') + carry + (y[i] - '0');
        if(e >= 10){
            carry = e/10;
            s[i] = (e%10) + '0';
        }
        else{
            carry = 0;
            s[i] = e + '0';
        }
    }
    if(carry != 0){
        carga.c[0] = '1';
        strcat(carga.c,s);
        strcpy(s,carga.c);
    }


}

void igualando(char *n, int sz, int pot){
    numero zeros;
    memset(zeros.num,'\0', 1024);
    memset(zeros.num,'0', pot-sz);
    strcat(zeros.num,n);
    strcpy(n,zeros.num);
}

int potencia(int size){
    int x;
    for(int i = 1; i < 10; i++){
        x = pow(2,i);
        if(x >= size)return x;
    }
}

int main(){
    numero n1,n2,max,pot,sum;
    scanf("%s", &n1.num);
    scanf("%s", &n2.num);
    n1.sz = strlen(n1.num);
    n2.sz = strlen(n2.num);

    if(n1.sz > n2.sz)max.sz = n1.sz;
    else max.sz = n2.sz;

    printf("NUMEROS : %s + %s\n", n1.num, n2.num);
    printf("TAMANHO :%d %d\n", n1.sz, n2.sz);
    pot.sz = potencia(max.sz);
    igualando(n1.num,n1.sz,pot.sz);
    igualando(n2.num,n2.sz,pot.sz);
    soma(n1.num,n2.num,pot.sz,sum.num);

    //printf("NOVO : %s %s\n", n1.num,n2.num);
    printf("SOMA: %s\n", sum.num);


    return 0;
}