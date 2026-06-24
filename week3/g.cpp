#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        vector<char> a(n+2);
        a[0] = 'L';
        a[n+1] = 'L';
        for(int i = 1; i <= n; i++) a[i] = s[i-1];
        int i = 0;
        bool possible = true;
        while(i < n+1) {
            if(a[i] == 'L') {
                int next_pos = -1;
                for(int j = min(i+m, n+1); j > i; j--) {
                    if(a[j] == 'L') {
                        next_pos = j;
                        break;
                    }
                }
                if(next_pos == -1) {
                    for(int j = min(i+m, n+1); j > i; j--) {
                        if(a[j] == 'W') {
                            next_pos = j;
                            break;
                        }
                    }
                }
                if(next_pos == -1) {
                    possible = false;
                    break;
                }
                i = next_pos;
            }
            else if(a[i] == 'W') {
                i++;
                k--;
                if(k < 0 || a[i] == 'C') {
                    possible = false;
                    break;
                }
            }
        }
        if(possible) {
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }
    return 0;
}