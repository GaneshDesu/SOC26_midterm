#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int sign = 1;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            long long a;
            cin >> a;
            sum += sign*a;
            sign *= -1;
        }
        if(n%2 == 1) {
            cout << "YES" << '\n';
            continue;
        }
        if(sum <= 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}