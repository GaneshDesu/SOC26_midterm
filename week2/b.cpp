#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, d;
    cin >> n >> d;
    vector<long long> pow(n);
    for(long long i = 0; i < n; i++) cin >> pow[i];
    sort(pow.begin(), pow.end(), greater<long long>());
    int ans = 0, i = 0, j = n-1;
    while(i <= j) {
        long long need = d/pow[i] + 1;
        if(i + need - 1 > j) break;
        ans++;
        i++;
        j -= (need-1);
    }
    cout << ans << '\n';
    return 0;
}