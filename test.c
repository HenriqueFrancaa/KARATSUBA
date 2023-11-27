#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char num[1024];
    char carry[1];
}numero;

int main(){
    numero n,c;
    scanf("%s", &n.num);
    c.carry[0] = '7';
    printf("%s %s\n", n.num, c.carry);
    int k = atoi(c.carry);
    strcat(n.num,c.carry);
    //printf("%d\n", k);
    printf("%s\n", n.num);

    numero nome;
    scanf("%s", &nome.num);

    numero n2;
    strcpy(n2.num,nome.num[8/2]);

    printf("%s", n2.num);
    

    return 0;
}
