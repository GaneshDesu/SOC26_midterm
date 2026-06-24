#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    
    // Sort the target array to process smaller elements first
    sort(c.begin(), c.end());
    
    // The initial array only has the number 1. 
    // If the smallest required number is not 1, we can't start.
    if (c[0] != 1) {
        cout << "NO\n";
        return;
    }
    
    long long current_sum = 1;
    
    // Check if each subsequent element can be formed
    for (int i = 1; i < n; ++i) {
        // If the current number is strictly greater than the sum of all 
        // available smaller numbers, it's impossible to form.
        if (c[i] > current_sum) {
            cout << "NO\n";
            return;
        }
        // Otherwise, we can form it, and we add it to our available sum pool.
        current_sum += c[i];
    }
    
    cout << "YES\n";
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