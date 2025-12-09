#include <stdio.h>
#include <stdlib.h>

#pragma GCC optimize("O3")

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)
i64 max(i64 a, i64 b) { return a > b ? a : b; }
i64 input() { i64 n; scanf("%lld", &n); return n; }

i64 memo[100001] = {0};
i64 arr[100001] = {0};

int main() {
    i64 n = input();
    range(i, 0, n) { scanf("%lld", &arr[i]); }

    range(l, 0, n) {
        i64 min = 100000000000;

        range(i, 0, n - l) {
            i64 num = max(memo[i], arr[i + l]); // still n^2 :(
            if(num < min) min = num;
            memo[i] = num;
        }

        printf("%lld\n", min);
    }
}

















// #include <stdio.h>
// #include <stdlib.h>

// #define INF 2000000000

// int stack[100005];
// int top = -1;

// void reset() { top = -1; }
// void push(int idx) { stack[++top] = idx; }
// int pop() { return stack[top--]; }
// int peek() { return top == -1 ? -1 : stack[top]; }
// int is_empty() { return top == -1; }

// int main() {
//     int n;
//     scanf("%d", &n);

//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     int left[n];
//     int right[n];

//     for (int i = 0; i < n; i++) {
//         // Pop elements that are smaller or equal to current
//         while (!is_empty() && arr[peek()] <= arr[i]) {
//             pop();
//         }

//         // If stack empty, no greater element on left; boundary is -1
//         left[i] = is_empty() ? -1 : peek();
//         push(i);
//     }

//     reset()
//     for (int i = n - 1; i >= 0; i--) {
//         // Pop elements that are smaller to current
//         // Note: strictly smaller here to handle duplicates correctly
//         while (!is_empty() && arr[peek()] < arr[i]) {
//             pop();
//         }
//         // If stack empty, no greater element on right; boundary is n
//         right[i] = is_empty() ? n : peek();
//         push(i);
//     }

//     // 3. Initialize answer array with Infinity
//     // ans[i] stores the Minimum Max for a window of length i
//     int* ans = (int*)malloc((n + 2) * sizeof(int));
//     for (int i = 0; i <= n + 1; i++) ans[i] = INF;

//     // 4. Map the lengths to values
//     for (int i = 0; i < n; i++) {
//         // The length of the window where arr[i] is the maximum
//         int len = right[i] - left[i] - 1;

//         // Update the answer for this specific length
//         if (arr[i] < ans[len]) {
//             ans[len] = arr[i];
//         }
//     }

//     // 5. Fill in the gaps (Suffix Minimum)
//     // If a value X works for length L, it definitely works for length L-1.
//     // So we traverse backwards and carry the minimum down.
//     for (int i = n - 1; i >= 1; i--) {
//         if (ans[i+1] < ans[i]) {
//             ans[i] = ans[i+1];
//         }
//     }


//     for (int i = 1; i <= n; i++) {
//         printf("%d\n", ans[i]);
//     }
// }