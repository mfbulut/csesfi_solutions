#include <stdio.h>
#include <stdlib.h>

#define INF 10000000000
typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)

typedef struct {
    i64 x, y, z;
} Vec3;

Vec3 v[10000] = {0};

i64 dist(Vec3 a, Vec3 b) {
    i64 x = llabs(a.x - b.x);
    i64 y = llabs(a.y - b.y);
    i64 z = llabs(a.z - b.z);
    return x*x + y*y + z*z;
}

#define NUM_CONNECTIONS 1000
Vec3 pairs[NUM_CONNECTIONS] = {0};

i64 num_clusters(i64 i) {
    if (pairs[i].z < 0) return 0;
    if (v[pairs[i].x].x == -1 && v[pairs[i].y].x == -1) return 0;
    
    pairs[i].z = -1;
    v[pairs[i].x].x = -1;
    v[pairs[i].y].x = -1;

    // printf("%lld - %lld\n", pairs[i].x, pairs[i].y);
    
    i64 res = 1;

    range(j, 0, NUM_CONNECTIONS) {
        if (pairs[i].x == pairs[j].x || pairs[i].x == pairs[j].y || pairs[i].y == pairs[j].x || pairs[i].y == pairs[j].y) {
            res += num_clusters(j);
        }
    }

    return res;
}

int main() {
    FILE *fp = fopen("adventofcode/day8.txt", "r");
    
    i64 x, y, z, n = 0;

    while (fscanf(fp, "%lld,%lld,%lld", &x, &y, &z) == 3) {
        v[n++] = (Vec3){x, y, z};
    }

    range(i, 0, NUM_CONNECTIONS) { pairs[i] = (Vec3){INF, INF, INF}; }

    range(i, 0, n) {
        range(j, i + 1, n) {
            i64 d = dist(v[i], v[j]);

            if (d < pairs[NUM_CONNECTIONS - 1].z) {
                pairs[NUM_CONNECTIONS - 1].x = i;
                pairs[NUM_CONNECTIONS - 1].y = j;
                pairs[NUM_CONNECTIONS - 1].z = d;
            }

            // Swap with left until it finds its place
            for (int k = NUM_CONNECTIONS - 1; k > 0; k--) {
                if (pairs[k].z < pairs[k - 1].z) {
                    Vec3 tmp = pairs[k - 1];
                    pairs[k - 1] = pairs[k];
                    pairs[k] = tmp;
                } else {
                    break;
                }
            }
        }
    }
    
    // range(i, 0, NUM_CONNECTIONS) {
    //     printf("%lld - %lld  dist = %lld\n", pairs[i].x, pairs[i].y, pairs[i].z);
    // }
    
    i64 top[3] = {0,0,0};

    range(i, 0, NUM_CONNECTIONS) {
        i64 size = num_clusters(i) + 1;
    
        if (size > top[2]) {
            top[2] = size;
            for (int k = 2; k > 0; k--) {
                if (top[k] > top[k - 1]) {
                    i64 tmp = top[k - 1];
                    top[k - 1] = top[k];
                    top[k] = tmp;
                } else {
                    break;
                }
            }
        }
    
        // printf("\n");
    }
    
    printf("Biggest clusters: %lld, %lld, %lld\n", top[0], top[1], top[2]);
    printf("Result: %lld\n", top[0] * top[1] * top[2]);
}


