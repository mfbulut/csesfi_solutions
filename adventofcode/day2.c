#include <stdio.h>
#include <stdlib.h>

// Not completed - in progress

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)
i64 max(i64 a, i64 b) { return a > b ? a : b; }
i64 min(i64 a, i64 b) { return a > b ? b : a; }
i64 input() { i64 n; scanf("%lld", &n); return n; }
i64* input_array(i64 n) { i64 *arr = (i64*)malloc(n * sizeof(i64)); range(i, 0, n) { scanf("%lld", &arr[i]); } return arr; }

int main() {
    i64 n = input();
    i64* arr = input_array(n);

    range(i, 0, n) {
        printf("%lld ", arr[i]);
    }

    printf("\n");
}