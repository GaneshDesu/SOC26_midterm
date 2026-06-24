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
        vector<int> points(2*n);
        for(int i = 0; i < 2*n; i++) cin >> points[i];
        sort(points.begin(), points.end());
        long long ans = (long long)(points[n-1]-points[0]) + (long long)(points[2*n-1]-points[n]);
        cout << ans <<'\n';
        for(int i = 0; i < n; i++) {
            cout << points[i] << " " << points[i+n] << '\n';
        }
    }
    return 0;
}