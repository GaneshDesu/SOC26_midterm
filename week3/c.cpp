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
        vector<int> a(n);
        pair<int, vector<int>> maxi = {INT_MIN, {}};
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] > maxi.first) {
                maxi.first = a[i];
                maxi.second = {i};
            }
            else if(a[i] == maxi.first) maxi.second.push_back(i);
        }
        if( n%2 == 0) {
            int ans = maxi.first + n/2;
            cout << ans << '\n';
        }
        else {
            int ans = maxi.first;
            bool even = false, odd = false;
            for(int i = 0; i < maxi.second.size(); i++) {
                if(maxi.second[i]%2 == 0) odd = true;
                else even = true;
            }
            if(odd) ans += (n+2)/2;
            else ans += n/2;
            cout << ans << '\n';
        }
    }
    return 0;
}