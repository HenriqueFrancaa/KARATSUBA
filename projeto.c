#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



void prints(char *r, int l){
    int i = 0;
    while(r[i] == '0'){
        i++;
    }
    if(i == l){
        printf("0\n");
    }
    else{
        for(int j = i; j < l; j++){
            printf("%c", r[j]);
        }printf("\n");
    }
}

void somando(char *x, char *y, char *r){
    char sum[1002];
    int sz = strlen(x)-1;
    int carry = 0,e = 0;
    for(int i = sz-1; i >= 0; i--){
        e = (x[i] - '0') + carry + (y[i] - '0');
        if(e >= 10){
            carry = e/10;
            sum[i] = (e%10)+'0';
        }
        else{
            carry = 0;
            sum[i] = e + '0';
        }
    }
    if(carry > 0){
        r[0] = '1';
        strcat(r,sum);
    }
    else{
        strcpy(r,sum);
    }

}

void igualando(char *n, int sz, int max){
    char z[1004];
    memset(z,'\0',1004);
    memset(z,'0', max - sz);
    strcat(z,n);
    strcpy(n,z);
}

int potencia(int max){
    int maxpot;
    for(int i = 1; i < 10; i++){
        int x = pow(2,i);
        if(x >= max){
           maxpot = x;
           break;
        }
    }
    return maxpot;
}

int main(){
    int p;
    int maxpot;
    char n1[1001];
    char n2[1001];
    fgets(n1,1001,stdin);
    fgets(n2,1001,stdin);
    
    int sz1 = strlen(n1)-1;
    int sz2 = strlen(n2)-1;
    int max; //tamanho do maior numero
    if(sz1 > sz2){
        max = sz1;    
    }
    else{
        max = sz2;
    }

    maxpot = potencia(max);
    //achando maior potencia, >= a quantidade de digitos do numero

    //igualando a quantidade de casas.
    igualando(n1,sz1,maxpot);
    igualando(n2,sz2,maxpot);

    char r[1004];
    somando(n1,n2,r);
    int l = strlen(r)-1;
    int z = 0;

    prints(r,l);

    
    return 0;
}