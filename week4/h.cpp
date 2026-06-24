#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dp(n+1, vector<int>(h, -1));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < h; j++) {
            if(dp[i][j] != -1) {
                int t1 = (j + a[i])%h;
                int t2 = (j + a[i]-1)%h;
                int good1 = (l <= t1 && t1 <= r)? 1 : 0;
                int good2 = (l <= t2 && t2 <= r)? 1 : 0;
                dp[i+1][t1] = max(dp[i+1][t1], dp[i][j]+good1);
                dp[i+1][t2] = max(dp[i+1][t2], dp[i][j]+good2);
            }
        }
    }
    int max_good = 0;
    for(int j = 0; j < h; j++) max_good = max(max_good, dp[n][j]);
    cout << max_good << '\n';
    return 0;
}