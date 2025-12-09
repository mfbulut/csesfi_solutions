#include <iostream>
#include <string>
#include <stack>
using namespace std;

typedef int i32;
typedef long long i64;
#define range(i,y,x) for(i64 i=(y);(i<(x));(i)++) // exclusive

char get_inverse(char c) {
    if(c == '{') return '}';
    if(c == '(') return ')';
    if(c == '[') return ']';
    return ' ';
}

int main() {
    string arr;
    getline(cin, arr);

    i64 len = arr.length();

    if(len == 0){
        printf("YES");
        return 0;
    }

    stack<char> st;

    range(i, 0, len) {
        if(arr[i] == '{') {
            st.push(arr[i]);
        }
        if(arr[i] == '(') {
            st.push(arr[i]);
        }
        if(arr[i] == '[') {
            st.push(arr[i]);
        }

        if (arr[i] == '}' || arr[i] == ')' || arr[i] == ']')
        {
            if(st.size() == 0) {
                printf("NO");
                return 0;
            }

            if(arr[i] == get_inverse(st.top())) {
                st.pop();
                continue;
            } else {
                printf("NO");
                return 0;
            }
        }
    }

    if(st.size() == 0) {
        printf("YES");
    } else {
        printf("NO");
    }
}