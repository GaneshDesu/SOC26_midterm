#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, k;
    cin >> n >> k;
    long long mid = (n+1)/2;
    if(k <= mid) cout << 2*k - 1 << '\n';
    else cout << 2*(k - mid) << '\n';
    return 0;
}