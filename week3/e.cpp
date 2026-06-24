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
        string s;
        cin >> s;
        if(n == 1) {
            cout << 0 << '\n';
            continue;
        }
        int trans = 0;
        for(int i = 0; i < n-1; i++) {
            if(s[i] != s[i+1]) trans++;
        }
        if(s[0] == '1') cout << trans << '\n';
        else {
            if(trans == 0) cout << 0 << '\n';
            else cout << trans-1 << '\n';
        }
    }
    return 0;
}