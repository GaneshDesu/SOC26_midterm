#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int len = 1;
    int max_len = 1;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        if(a[i] >= a[i-1]) len++;
        else {
            max_len = max(max_len, len);
            len = 1;
        }
    }
    max_len = max(max_len, len);
    cout << max_len << '\n';
    return 0;
}