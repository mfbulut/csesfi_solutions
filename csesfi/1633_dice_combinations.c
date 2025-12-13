#include <stdio.h>

#pragma GCC optimize("O3")
typedef long long i64;
#define range(i,y,x) for(i64 i=(y);(i<=(x));(i)++)
#define min(a, b) ((a) > (b) ? (b) : (a))

// since we know n <= 10^6
i64 memo[1000001];

i64 combinations(i64 n) {
    if(memo[n] != -1) {
        return memo[n];
    }

    i64 result = 0;

    if(n <= 6) { result = 1; }

    range(i, 1, min(n - 1, 6)) {
        result = (result + combinations(n - i)) % 1000000007;
    }

    memo[n] = result;
    return result;
}

int main() {
    for(int i = 0; i < 1000001; ++i) {
        memo[i] = -1;
    }

    memo[1] = 1;

    i64 n;
    scanf("%lld", &n);

    // printf("1: %lld \n", combinations(1));
    // printf("2: %lld \n", combinations(2));
    // printf("3: %lld \n", combinations(3));
    // printf("4: %lld \n", combinations(4));
    // printf("5: %lld \n", combinations(5));
    // printf("6: %lld \n", combinations(6));
    // printf("7: %lld \n", combinations(7));   // Answer: 63
    // printf("8: %lld \n", combinations(8));   // Answer: 125
    // printf("9: %lld \n", combinations(9));   // Answer: 248
    // printf("10: %lld \n", combinations(10)); // Answer: 492

    i64 result = combinations(n);
    printf("%lld", result);
}