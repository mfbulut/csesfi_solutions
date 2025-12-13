#include <stdio.h>
#include <stdlib.h>

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)
i64 input() { i64 n; scanf("%lld", &n); return n; }

int main() {
    i64 n = input();
    i64 q = input();
    i64 arr[n];
    i64 right[n];
    
    range(i, 0, n) arr[i] = input();

    while (q--) {
        if(input() == 1) {
            i64 i = input();
            i64 val = input();
            arr[i] += val;
        } else {
            i64 s = input();
            i64 e = input();
            
            i64 max = 0;
            range(i, s, e + 1) 
                if(arr[i] > max)
                    max = arr[i];
            
            printf("%lld\n", max);
        }
    }
}