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
        vector<int> c(n+1, 0);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            c[x]++;
        }
        int D = 0;
        for(int v = n; v >= 1; v--) {
            int dif = c[v] - D;
            int ceil_div = (dif > 0)?(dif+1)/2:dif/2;
            int p_min = max(0, ceil_div);
            if(D > 0) p_min = max(p_min, 1);
            D = 2*p_min + D - c[v];
        }
        if(D == 0) cout << "YES" << '\n';
        else cout << "NO\n";
    }
    return 0;
}