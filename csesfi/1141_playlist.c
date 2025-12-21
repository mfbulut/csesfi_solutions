#include <stdio.h>
#define fori(a, b) for(int i = a; i < b; i++)
int max(int a, int b) { return a > b ? a : b; }
int input() { int n; scanf("%d", &n); return n; }

// hashmap
struct { int k, v, u; } t[2000003];
int map_get(int k) { for (int i = k % 2000003; t[i].u; i = (i + 1) % 2000003){ if (t[i].k == k) { return t[i].v; } } return -1; }
void map_set(int k, int v) { int i = k % 2000003; while (t[i].u && t[i].k != k) i = (i + 1) % 2000003; t[i].u = 1; t[i].k = k; t[i].v = v;}

int main() {
    int n = input(), l = 0, r = 0;
    fori(0, n) {
        int num = input(), last = map_get(num);
        if (last != -1 && last >= l) l = last + 1;
        map_set(num, i);
        r = max(r, i - l + 1);
    }
    printf("%d\n", r);
}