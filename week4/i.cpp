#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int color;
        cin >> color;
        if(a.empty() || a.back() != color) a.push_back(color);
    }
    int m = a.size();
    if(m <= 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<int> dp(m, 0);
    vector<int> next_dp(m, 0);
    for(int l = m-1; l >= 0; l--) {
        for(int r = l; r < m; r++) {
            if(l == r) next_dp[l] = 0;
            else if(a[l] == a[r]) next_dp[r] = dp[r-1]+1;
            else if(a[l] != a[r]) next_dp[r] = min(dp[r], next_dp[r-1]) + 1;
        }
        dp = next_dp;
    }
    cout << dp[m-1] << '\n';
    return 0;
}