#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        int ans = 0;
        bool prev = false;
        for(int i = 0; i < n; i++) {
            if(s[i] == '@') {
                ans++;
                prev = false;
            }
            else if(s[i] == '.') prev = false;
            else if(s[i] == '*') {
                if(prev) break;
                else prev = true;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}