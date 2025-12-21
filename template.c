#include <stdio.h>
#include <stdlib.h>

#pragma GCC optimize ("O3")
typedef long long i64;

#define fori(a, b) for(i64 i = a; i < b; i++)
#define forj(a, b) for(i64 j = a; j < b; j++)
#define fork(a, b) for(i64 k = a; k < b; k++)

i64 max(i64 a, i64 b) { return a > b ? a : b; }
i64 min(i64 a, i64 b) { return a > b ? b : a; }
i64 input() { i64 n; scanf("%lld", &n); return n; }

// Generic Dynamic Array
#define vec_push(V, VALUE) (vec_grow((void **)&(V), sizeof(*(V))), (V)[((i64 *)(V))[-1]++] = (VALUE))
#define vec_pop(V) ((void)(((i64 *)(V))[-1] -= 1))
#define vec_len(V) ((V) ? ((i64 *)(V))[-1] : 0)
void vec_grow(void **vector, i64 type_size) { if (!*vector) { i64 *meta = malloc(type_size * 2 + sizeof(i64) * 2); meta[0] = 2; meta[1] = 0; *vector = &meta[2]; } else { i64 *meta = &((i64 *)*vector)[-2]; if (meta[1] >= meta[0]) { i64 new_cap = meta[0] * 2; meta = realloc(meta, type_size * new_cap + sizeof(i64) * 2); meta[0] = new_cap; *vector = &meta[2];} } }

// Global int-int Hashmap
struct { i64 k, v, u; } t[2000003];
i64 map_get(i64 k) { for (i64 i = k % 2000003; t[i].u; i = (i + 1) % 2000003){ if (t[i].k == k) { return t[i].v; } } return -1; }
void map_set(i64 k, i64 v) { i64 i = k % 2000003; while (t[i].u && t[i].k != k) i = (i + 1) % 2000003; t[i].u = 1; t[i].k = k; t[i].v = v;}

int main() {
    i64 n = input();
    i64* arr = 0;

    fori(0, n) {
        vec_push(arr, input());
    }

    fori(0, n) {
        printf("%lld ", arr[i]);
    }
}