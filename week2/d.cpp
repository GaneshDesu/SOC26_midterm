#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr)
        int t;
        cin >> t;
        while(t--) {
            int n, k;
            cin >> n >> k;
            map<int, pair<int, int>> pos;
            for(int i = 0; i < n; i++) {
                int x;
                cin >> x;
                if(!pos.count(x)) pos[x] = {i, i};
                else pos[x].second = i;
            }
            while(k--) {
                int a, b;
                cin >> a >> b;
                if(!pos.count(a) || !pos.count(b)) cout << "NO" << '\n';
                else if(pos[a].first < pos[b].second) cout << "YES" << '\n';
                else cout << "NO" << '\n';
            }
        }
        return 0;
}