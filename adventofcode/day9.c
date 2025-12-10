#include <stdio.h>
#include <stdlib.h>

#define INF 10000000000
typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)

typedef struct {
    i64 x, y;
} Vec2;

i64 area(Vec2 a, Vec2 b) {
    i64 x = llabs(a.x - b.x) + 1;
    i64 y = llabs(a.y - b.y) + 1;
    return x*y;
}

Vec2 v[10000] = {0};

int main() {
    FILE *fp = fopen("adventofcode/day9.txt", "r");
    
    i64 x, y, n = 0;

    while (fscanf(fp, "%lld,%lld", &x, &y) == 2) {
        v[n++] = (Vec2){x, y};
    }

    i64 max = 0;
    range(i, 0, n) {
        range(j, i + 1, n) {
            i64 d = area(v[i], v[j]);
            printf("%lld,%lld - %lld,%lld dist = %lld\n", v[i].x, v[i].y,  v[j].x, v[j].y, d);

            if(d > max) max = d;
        }
    }
    
    printf("%lld\n", max);
}


