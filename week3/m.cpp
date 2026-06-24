#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int left = 0, ans = 1;
    for(int right = 1; right < n; right++) {
        if(a[right] <= 2*a[right-1]) continue;
        else {
            ans = max(ans, right-left);
            left = right;
        }
    }
    ans = max(ans, n-left);
    cout << ans << '\n';
    return 0;
}