#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long cnt1, cnt2, cnt3, cnt4;
    cin >> cnt1 >> cnt2 >> cnt3 >> cnt4;
    if(cnt1 != cnt4) cout << 0 << '\n';
    else if(cnt3 != 0 && cnt1 == 0) cout << 0 << '\n';
    else cout << 1 << '\n';
    return 0;
}