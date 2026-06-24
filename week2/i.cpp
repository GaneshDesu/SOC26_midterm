#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array to easily find close elements
    sort(a.begin(), a.end());
    
    // Remove duplicates since identical original values require identical 
    // permutation values (which is impossible) to reach the same sum.
    a.erase(unique(a.begin(), a.end()), a.end());
    
    int ans = 0;
    int m = a.size();
    
    // Sliding window / Two pointers to find the max valid subset
    for (int L = 0, R = 0; L < m; ++L) {
        while (R < m && a[R] - a[L] < n) {
            R++;
        }
        ans = max(ans, R - L);
    }
    
    cout << ans << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}