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
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());
        long long alice_sum = 0, bob_sum = 0;
        for(int i = 0; i < n; i++) {
            if(i%2 == 0) {
                if(a[i]%2 == 0) alice_sum += a[i];
            }
            else {
                if(a[i] %2 == 1) bob_sum += a[i];
            }
        }
        if(alice_sum > bob_sum) cout << "Alice" << '\n';
        else if(alice_sum < bob_sum) cout << "Bob" << '\n';
        else cout << "Tie" << '\n';
    }
    return 0;
}