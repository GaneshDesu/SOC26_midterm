#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
const int max_n = 1e5;
long long dp[max_n];
long long pref[max_n];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, k;
    cin >> t >> k;
    dp[0] = 1;
    for(int i = 1; i < max_n; i++) {
        dp[i] = dp[i-1];
        if(i >= k) dp[i] = (dp[i] + dp[i-k])%mod;
    }
    pref[0] = 0;
    for(int i = 1; i < max_n; i++) {
        pref[i] = (pref[i-1] + dp[i])%mod;
    }
    while(t--) {
        int a, b;
        cin >> a >> b;
        long long ans = (pref[b] - pref[a-1]+mod)%mod;
        cout << ans << '\n';
    }
    return 0;
}