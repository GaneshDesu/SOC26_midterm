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
        map<int, long long> freq;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }
        long long ans = 0;
        for(auto &[val, cnt] : freq) ans += cnt*(cnt-1)/2;
        ans += freq[1]*freq[2];
        cout << ans << '\n';
    }
    return 0;
}