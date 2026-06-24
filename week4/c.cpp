#include<bits/stdc++.h>
using namespace std;
const int max_val = 1e5 + 5;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> count(max_val);
    int max_num = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count[x]++;
        max_num = max(max_num, x);
    }
    vector<long long> dp(max_val, 0);
    dp[0] = 0;
    dp[1] = count[1];
    for(int i = 2; i <= max_num; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + i*count[i]);
    }
    cout << dp[max_num] << '\n';
    return 0;
}