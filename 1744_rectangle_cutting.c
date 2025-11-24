#include <stdio.h>

typedef char* string;
typedef int i32;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
#define range(i,y,x) for(i64 i=(y);(i<=(x));(i)++)

// since we know a,b < 500
#define MAX_VALUE 501
i64 memo[MAX_VALUE][MAX_VALUE];

i64 min_cuts(i64 a, i64 b) {
    if(a == b) {
        return 0;
    }

    if(a > b) {
        i64 temp = a;
        a = b;
        b = temp;
    }

    if(memo[a][b] != -1) {
        return memo[a][b];
    }

    i64 smallest = 9999999;

    range(i, 1, a - 1) {
        i64 res = 1 + min_cuts(i, b) + min_cuts(a - i, b);
        if(res < smallest) smallest = res;
    }

    range(i, 1, b - 1) {
        i64 res = 1 + min_cuts(a, i) + min_cuts(a, b - i);
        if(res < smallest) smallest = res;
    }

    memo[a][b] = smallest;

    return smallest;
}

int main() {
    for(int i = 0; i < MAX_VALUE; ++i) {
        for(int j = 0; j < MAX_VALUE; ++j) {
            memo[i][j] = -1;
        }
    }

    i64 a, b;
    scanf("%lld", &a);
    scanf("%lld", &b);

    i64 result = min_cuts(a, b);
    printf("%lld", result);
}
