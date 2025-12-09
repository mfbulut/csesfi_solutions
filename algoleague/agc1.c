#include <stdio.h>
#include <stdlib.h>

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<=(b));(i)++)
i64 input() { i64 n; scanf("%lld", &n); return n; }

#define get(x,y) matrix[target + i * n] == '1'

void print_list(char* matrix, i64 n, i64 target) {   
    range(i, 0, n) {
        if(get(target, i)) {
            printf("%lld ", i); 
        }
    }
    
    printf("\n"); 
}

int main() {
    i64 n = input(); // node count
    i64 e = input(); // edge count
    
    char matrix[(n + 1) * (n + 1)];

    range(i, 1, n) {
        range(j, 1, n) {
            matrix[i + j * n] = '0';
        }
    }
    
    range(i, 1, e) {
        i64 a = input();
        i64 b = input();
        matrix[a + b * n] = '1';
        matrix[b + a * n] = '1';
    }
    
    range(i, 1, n) {
        print_list(matrix, n, i);
    }
    
    range(i, 1, n) {
        range(j, 1, n) {
            printf("%c ", matrix[i + j * n]);
        }
        printf("\n");
    }
}