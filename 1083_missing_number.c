#include <stdio.h>

typedef char* string;
typedef int i32;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
#define range(i,y,x) for(i64 i=(y);(i<=(x));(i)++)

int main() {
    i64 n;
    scanf("%lld", &n);

    i64 result = n * (n + 1) / 2;

    range(i, 1, n - 1) {
        i64 num;
        scanf("%lld", &num);
        result -= num;
    }

    printf("%lld", result);
}