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
    strcat(n.num,c.carry);

    printf("%s\n", n.num);

    return 0;
}
