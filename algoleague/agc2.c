#include <stdio.h>

typedef char* string;
typedef int i32;
typedef long long i64;
#define range(i,y,x) for(i64 i=(y);(i<(x));(i)++) // exclusive

int main() {
    i64 n;
    scanf("%lld", &n);

    i64 k;
    scanf("%lld", &k);

    i64 arr[n];

    range(i, 0, n) {
        i64 num = 0;
        scanf("%lld", &num);
        arr[i] = num;
    }

    i64 max = 0;
    i64 current = 0;

    range(i, 0, k) {
        current += arr[i];
        max = current;
    }

    range(i, k, n) {
        current += arr[i];
        current -= arr[i - k];
        if(current > max) max = current;
    }

    printf("%lld", max);
}