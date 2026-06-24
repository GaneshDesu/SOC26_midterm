#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long getways(int n, int max_edge) {
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <= max_edge; j++) {
            if(i-j >= 0) dp[i] = (dp[i] + dp[i-j])%mod;
        }
    }
    return dp[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, d;
    cin >> n >> k >> d;
    long long total_ways = getways(n, k);
    long long invalid_ways = getways(n, d-1);
    long long ans = (total_ways - invalid_ways + mod) % mod;
    cout << ans << '\n';
    return 0;
}