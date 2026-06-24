#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    vector<string> s(n);
    vector<string> rev(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        rev[i] = s[i];
        reverse(rev[i].begin(), rev[i].end());
    }
    vector<vector<long long>> dp(n, vector<long long>(2, 1e18));
    dp[0][0] = 0;
    dp[0][1] = c[0];
    for(int i = 1; i < n; i++) {
        if(s[i-1] <= s[i]) dp[i][0] = min(dp[i][0], dp[i-1][0]);
        if(rev[i-1] <= s[i]) dp[i][0] = min(dp[i][0], dp[i-1][1]);
        if(s[i-1] <= rev[i]) dp[i][1] = min(dp[i][1], dp[i-1][0]+c[i]);
        if(rev[i-1] <= rev[i]) dp[i][1] = min(dp[i][1], dp[i-1][1]+c[i]);
    }
    long long ans = min(dp[n-1][0], dp[n-1][1]);
    if(ans != 1e18) cout << ans << '\n';
    else cout << -1 << '\n';
    return 0;
}