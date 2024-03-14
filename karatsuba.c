#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 65536 


typedef struct{
    char num[MAX_SIZE];
    int size;
} str;

void PrintS(str n){
    int i = 0;
    while(n.num[i] == '0'){ i++; }
    if(i == n.size){ 
        printf("0\n"); return;
    }
    for(i; i < n.size; i++){
        printf("%c", n.num[i]);
    } printf("\n");
}

void igualando(char* str1, char* str2, int size){
    if(size == 1){ 
        return;
     }
    int p = 1;
    while(size > pow(2, p)){ 
        p++; 
    }
    int zeros = pow(2, p);
    str power1;
    str power2;
    memset(power1.num, '\0', sizeof(power1.num));
    memset(power2.num, '\0', sizeof(power2.num));
    memset(power1.num, '0', zeros - strlen(str1));
    memset(power2.num, '0', zeros - strlen(str2));
    strcat(power1.num, str1);
    strcat(power2.num, str2);
    strcpy(str1, power1.num);
    strcpy(str2, power2.num);
}

str Zeros(str str, int size, int n){
    for(int i = 0; i < size / n ; i++){
        str.num[i+str.size] = '0';
    }
    str.size += size / n;
    return str;
}

str halph(str n, int pos){
    str s; 
    memset(s.num, '\0', sizeof(s.num));
    s.size = n.size / 2;

    if(pos == 0){
        for(int i = 0; i < s.size; i++){
            s.num[i] = n.num[i];
        }
    }else{
        for(int i = 0; i < s.size; i++){
            s.num[i] = n.num[i + s.size];
        }
    }
    return s;
}

str soma(str a, str b){
    if(a.size > b.size){
        igualando(a.num, b.num, a.size);
        a.size = strlen(a.num);
        b.size = strlen(b.num); 
    }
    else if(a.size < b.size){
        igualando(a.num, b.num, b.size);
        a.size = strlen(a.num);
        b.size = strlen(b.num); 
    }
    int carry = 0;
    str r; 
    memset(r.num, '\0', sizeof(r));
    str result;
    memset(result.num, '\0', sizeof(result));
    for(int i = a.size-1; i >= 0; i--){
        int sum = (a.num[i] - '0') + (b.num[i] - '0');
        r.num[i] = ((sum + carry) % 10) + '0';
        carry = (sum + carry) / 10;
    }
    if(carry != 0){
        result.num[0] = '1';
        strcat(result.num, r.num);
        result.size = strlen(result.num);
    }else{
        strcpy(result.num, r.num);
        result.size = strlen(result.num);
    }
    return result;
}

str mult(str x, str y){
        str product; memset(product.num, '\0', sizeof(product.num));
        int r = (x.num[0] - '0') * (y.num[0] - '0');
        if(r >= 10){
            product.num[0] = r / 10 + '0';
            product.num[1] = r % 10 + '0';
        }else{
            product.num[0] = '0';
            product.num[1] = r + '0';
        }
        product.size = 2;
        return product;
}

str karatsuba(str x, str y){
    if(x.size == 1){
        str result = mult(x, y);
        return result;
    }
    str a, b, c, d;
    a = halph(x, 0); 
    b = halph(x, 1);
    c = halph(y, 0); 
    d = halph(y, 1);
    str ac = karatsuba(a, c); 
    str ad = karatsuba(a, d); 
    str bc = karatsuba(b, c); 
    str bd = karatsuba(b, d); 
    
    str adbc = Zeros(soma(ad, bc), x.size, 2); //10 elevado a N/2 
    str r1 = Zeros(ac, x.size, 1); // 10 elevado a N
    str r2 = soma(r1, adbc); 
    str r3 = soma(r2, bd);
    return r3;
}

int main(){
    str x; scanf("%s", x.num); 
    str y; scanf("%s", y.num); 
    x.size = strlen(x.num);
    y.size = strlen(y.num);
  
    printf("X = %s\n", x.num);
    printf("Y = %s\n", y.num);

    if(x.size > y.size){
        igualando(x.num, y.num, x.size);
    }else{
        igualando(x.num, y.num, y.size);
    }
    
    x.size = strlen(x.num);
    y.size = strlen(y.num);

    str result = karatsuba(x, y);
    printf("\nX * Y = "); PrintS(result); printf("\n");

    return 0;
}