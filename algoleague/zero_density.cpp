#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main() {
    i64 n;
    cin >> n;
    
    string arr;
    cin >> arr;

    i64 z_count = 0;
    i64 e_count = 0;
    i64 r_count = 0;
    i64 o_count = 0;
    
    vector<i64> combinations(n);
    
    for(i64 i = n - 1; i >= 0; --i) {
        if(arr[i] == 'z') z_count = (z_count + e_count) % 1000000007;
        else if(arr[i] == 'e') e_count = (e_count + r_count) % 1000000007;
        else if(arr[i] == 'r') r_count = (r_count + o_count) % 1000000007;
        else if(arr[i] == 'o') o_count = (o_count + 1)% 1000000007;
    }
    
    cout << z_count % 1000000007;
}
