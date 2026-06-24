#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    long long mn = 0; // Tracks the minimum possible value of c
    long long mx = 0; // Tracks the maximum possible value of c
    
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        
        // Calculate the next max and min based on the boundaries
        long long next_mx = max(abs(mx + x), abs(mn + x));
        long long next_mn = mn + x;
        
        mx = next_mx;
        mn = next_mn;
    }
    
    cout << mx << "\n";
}

int main() {
    // Fast standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}