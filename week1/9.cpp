#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    int ones = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) ones++;
    }
    int curr = 0, best = -1e9;
    for(int i = 0; i < n; i++) {
        int val;
        if(a[i] == 0) val = 1;
        else val = -1;
        curr = max(val, curr + val);
        best = max(best, curr);
    }
    cout << ones+best<<'\n';
    return 0;
}