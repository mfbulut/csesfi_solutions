#include <stdio.h>
#include <stdlib.h>

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)
i64 max(i64 a, i64 b) { return a > b ? a : b; }
i64 min(i64 a, i64 b) { return a > b ? b : a; }

typedef struct { i64 x, y; } Vec2;
i64 area(Vec2 a, Vec2 b) { return (llabs(a.x - b.x) + 1) * (llabs(a.y - b.y) + 1); }

i64 n = 0;
Vec2 v[10000] = {0};

i64 is_valid(Vec2 a, Vec2 b) {
    i64 rx1 = min(a.x, b.x);
    i64 ry1 = min(a.y, b.y);
    i64 rx2 = max(a.x, b.x);
    i64 ry2 = max(a.y, b.y);

    i64 inside = 0;

    range(i, 0, n) {
        Vec2 s = v[i];
        Vec2 e = v[(i + 1) % n];
        
        if (s.x == e.x) {
            i64 min_y = min(s.y, e.y);
            i64 max_y = max(s.y, e.y);
            
            // Test vertical cuts
            if (s.x > rx1 && s.x < rx2 && max_y > ry1 && min_y < ry2) {
                return 0;
            }
            
            // Test if rect is inside or outside
            if (min_y <= ry1 && max_y > ry1 && s.x > rx1) {
                inside = !inside;
            }
            
        } else {
            i64 min_x = min(s.x, e.x);
            i64 max_x = max(s.x, e.x);
                
            // Test horizontal cuts
            if (s.y > ry1 && s.y < ry2 && max_x > rx1 && min_x < rx2) {
                return 0;
            }
        }
    }
    
    return inside;
}

int main() {
    FILE *fp = fopen("adventofcode/day9.txt", "r");
    
    i64 x, y;
    while (fscanf(fp, "%lld,%lld", &x, &y) == 2) {
        v[n++] = (Vec2){x, y};
    }
    
    i64 max = 0;
    range(i, 0, n) {
        range(j, i + 1, n) {
            i64 d = area(v[i], v[j]);
            if(d > max && is_valid(v[i], v[j])) max = d;
            printf("%lld,%lld - %lld,%lld ==> Area: %lld\n", v[i].x, v[i].y, v[j].x, v[j].y, d);
        }
    }
    
    printf("Max: %lld\n", max);
}


// ..............
// .......#XXX#..
// .......X...X..
// ..#XXXX#...X..
// ..X........X..
// ..#XXXXXX#.X..
// .........X.X..
// .........#X#..
// ..............