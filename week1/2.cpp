#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int best4 = -1, best7 = -1;
    int mn = 1e9;
    for(int b = 0; 7*b <= n; b++) {
        int rem = n - 7*b;
        if(rem % 4 == 0) {
            int a = rem/4;
            if(a + b < mn) {
                mn = a + b;
                best4 = a;
                best7 = b;
            }
        }
    }
    if(best4 == -1) {
        cout << "-1" << '\n';
        return 0;
    }
    cout << string(best4, '4') + string(best7, '7') << '\n';
    return 0;
}