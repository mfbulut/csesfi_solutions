#include <stdio.h>

typedef char* string;
typedef int i32;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
#define range(i,y,x) for(i64 i=(y);(((x)>=(y))?(i<=(x)):(i>=x));(((x)>=(y))?((i)++):((i)--)))
#define foreach(i, A) for(int _keep=1, _count=0,_size=sizeof (A) / sizeof *(A); _keep && _count != _size; _keep = !_keep, _count++) for(i = (A)+_count; _keep; _keep = !_keep)
#define len(a) (sizeof(a) / sizeof((a)[0]))
#define log(x, fmt, ...) if(x){printf("%s@%d: " fmt "\n", __FILE__, __LINE__,__VA_ARGS__);}

int main() {
    i64 n;
    scanf("%lld", &n);

    range(i, 1, n) {
        i64 x;
        i64 y;
        scanf("%lld", &x);
        scanf("%lld", &y);

        // make x > y
        if (y > x) {
            int temp = x;
            x = y;
            y = temp;
        }

        i64 diff = x - y;
        i64 same = y;

        if(diff > same) {
            printf("NO\n");
            continue;
        }

        // remainer after equalizing
        i64 remainer = same - diff;

        if(remainer % 3 == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

}

// Input:
// 2 1   diff = 1 // same = 1  // remainer = 0
// 2 2   diff = 0 // same = 2  // remainer = 2
// 3 3   diff = 0 // same = 2  // remainer = 3

// Output:
// YES
// NO
// YES