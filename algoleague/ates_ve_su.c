#include <stdio.h>
#include <stdlib.h>

typedef long long i64;

typedef struct {
    i64 first;
    i64 second;
} Pair;

int cmp(const void *a, const void *b) {
    return ((Pair*)a)->first - ((Pair*)b)->first;
}

i64 input() { i64 n; scanf("%lld", &n); return n; }

int main() {
    i64 n = input();
    i64 m = input();

    Pair pairs[m];
    for (i64 i = 0; i < m; i++) {
        pairs[i].first = input();
        pairs[i].second = input();
    }

    qsort(pairs, m, sizeof(Pair), cmp); // TODO use topological sort

    for (i64 i = 1; i < n + 1; i++) {
        printf("%lld %lld\n", pairs[i].first, pairs[i].second);
    }
    
    printf("\n");

    Pair values[n + 1]; 
    for (i64 i = 0; i < n + 1; i++) { values[i] = (Pair){ 0 }; }
    values[1] = (Pair){1, 1};
    
    for (i64 i = 0; i < m; i++) {
        values[pairs[i].second].first += values[pairs[i].first].first + values[pairs[i].first].second;
        values[pairs[i].second].second += values[pairs[i].first].second;
    }

    for (i64 i = 1; i < n + 1; i++) {
        printf("%lld %lld\n", values[i].first, values[i].second);
    }
    
    // printf("%lld\n", values[n].first);
}
