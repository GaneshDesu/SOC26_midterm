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
        int maxi = 0;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            maxi = max(maxi, a);
            mini = min(mini, a);
        }
        cout << maxi-mini << '\n';
    }
    return 0;
}