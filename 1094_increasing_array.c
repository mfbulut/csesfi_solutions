#include <stdio.h>

typedef char* string;
typedef int i32;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
#define range(i,y,x) for(i64 i=(y);(i<=(x));(i)++)

int main() {
    i64 n;
    scanf("%lld", &n);

    i64 result = 0;
    i64 last = 0;

    range(i, 1, n) {
        i64 current;
        scanf("%lld", &current);

        if(current < last) {
            result += last - current;
        } else {
            last = current;
        }
    }

    printf("%lld\n", result);
}