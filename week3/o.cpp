#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> count(n + 2, 0);
    vector<int> last_less(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        count[a[i]]++;
        last_less[a[i] + 1] = max(last_less[a[i] + 1], i);
    }
    for (int h = 1; h <= n; h++) {
        last_less[h] = max(last_less[h], last_less[h - 1]);
    }
    vector<int> s(n + 2, 0);
    for (int h = n; h >= 1; h--) {
        s[h] = s[h + 1] + count[h];
    }
    vector<int> R(n + 2, 0);
    long long base_moving = 0;
    for (int h = 1; h <= n; h++) {
        R[h] = n - last_less[h];
        base_moving += (s[h] - R[h]);
    }
    int max_delta = 0;
    for (int i = 1; i <= n; i++) {
        int h = a[i];
        if (h > 0) {
            if (i >= n - R[h] + 1) {
                int delta = R[h] - n + i - 1;
                max_delta = max(max_delta, delta);
            }
        }
    }
    cout << base_moving + max_delta << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}