#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        long long sum = 0;
        int ans = 0;
        int left = 0;
        for(int right = 0; right < n; right++) {
            sum += a[right];
            while(sum > r && left <= right) {
                sum -= a[left];
                left++;
            }
            if(sum >= l && sum <= r) {
                ans++;
                sum = 0;
                left = right+1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}