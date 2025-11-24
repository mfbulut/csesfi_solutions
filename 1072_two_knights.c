#include <stdio.h>

typedef char* string;
typedef int i32;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
#define range(i,y,x) for(i64 i=(y);(i<=(x));(i)++)

int main() {
    i64 input = 0;
    scanf("%lld", &input);

    range(n, 1, input) {
        // Assume n is larger than 4

        if(n < 5) {
            if(n == 1)      printf("%lld \n", 0);
            else if(n == 2) printf("%lld \n", 6);
            else if(n == 3) printf("%lld \n", 28);
            else if(n == 4) printf("%lld \n", 96);
            continue;
        }

        i64 num_squares =  n * n;
        i64 result = num_squares * (num_squares - 1); // All possible positions

        // xxaaaaxx
        // xxbbbbxx
        // ab    ba
        // ab    ba
        // ab    ba
        // ab    ba
        // xxbbbbxx
        // xxaaaaxx

        // Subtract unwanted cases

        // middle parts taht each can move to 8 diffrent places
        result -= (n - 4) * (n - 4) * 8;

        // 4 corners
        result -= (2 + 3 + 3 + 4) * 4;

        // a     4 edges of size (n - 4) that each can move to 4 diffrect places
        result -= (n - 4) * 4 * 4;

        // b     4 edges of size (n - 4) that each can move to 6 diffrect places
        result -= (n - 4) * 4 * 6;

        /*
        // naive version
        range(i, 1, n) {
            range(j, 1, n) {
                #define check(x, y) if(0 < x && x <= n &&  0 < y && y <= n)

                check(i + 1, j + 2) result--;
                check(i - 1, j + 2) result--;
                check(i + 1, j - 2) result--;
                check(i - 1, j - 2) result--;

                check(i + 2, j + 1) result--;
                check(i - 2, j + 1) result--;
                check(i + 2, j - 1) result--;
                check(i - 2, j - 1) result--;
            }
        }
        */

        printf("%lld \n", result / 2);
    }
}

