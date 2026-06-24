#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    for(int i = 0; i < (int)s1.size(); i++) {
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }

    if(s1 < s2) cout << -1 << '\n';
    else if(s1 == s2) cout << 0 << '\n';
    else cout << 1 << '\n';

    return 0;
}