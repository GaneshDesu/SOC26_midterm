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
        vector<pair<long long, int>> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        vector<long long> prefix(n);
        prefix[0] = a[0].first;
        for(int i = 1; i < n; i++) prefix[i] = prefix[i-1]+a[i].first;
        vector<int> reach(n);
        reach[n-1] = n-1;
        for(int i = n-2; i >= 0; i--) {
            if(prefix[i] >= a[i+1].first) reach[i] = reach[i+1];
            else reach[i] = i;
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++) ans[a[i].second] = reach[i];
        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << '\n';
    }
}