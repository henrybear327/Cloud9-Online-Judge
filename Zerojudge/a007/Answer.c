#include <stdio.h>
#include <math.h>

#define MAXSIZE 46340

int prime[MAXSIZE+1] = {0};
int prime_table[MAXSIZE],prime_table_len=0;

int makeprime(){
    int i,j;
    
    for(i=3;i<=MAXSIZE;i+=2)
        if(!prime[i]){
            for(j=i+i;j<=MAXSIZE;j+=i)
                prime[j]=1;

            prime_table[prime_table_len++]=i;
        }
}

int isprime(int n){
    int i,temp;

    if(n==2) return 1;
    if(n%2==0) return 0;
    if(n<=MAXSIZE){
        return 1-prime[n];
    }

    for(i=0;i!=prime_table_len && prime_table[i]*prime_table[i]<=n;++i)
        if(n%prime_table[i]==0)
            return 0;

    return 1;
}

int main(){
    int x;

    makeprime();
    while(scanf("%d",&x)==1){
        if(isprime(x)) puts("質數");
        else puts("非質數");
    }

    return 0;
}