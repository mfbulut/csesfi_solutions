#include <stdio.h>

int memo[1000001]; 

int combinations(int n) {
    if(memo[n] != -1) return memo[n];
    
    int res = 0;

    for(int i = 1; i < n; ++i)
        if(n % i == 0)
            res += combinations(i);

    memo[n] = res;
    return res;
}

int main() {
    for(int i = 0; i < 1000001; ++i) 
        memo[i] = -1;
    memo[1] = 1;

    int n;
    scanf("%d", &n);
    printf("%d", combinations(n));
}


