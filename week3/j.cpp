#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a1, a2;
    cin >> a1 >> a2;
    int ans = 0;
    while(a1 > 0 && a2 > 0) {
        if(a1 == 1 && a2 == 1) break;
        ans++;
        if(a1 > a2) {
            a1 -= 2;
            a2++;
        }
        else {
            a1++;
            a2 -= 2;
        }
    }
    cout << ans << '\n';
    return 0;
}