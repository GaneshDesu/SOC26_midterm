#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string s1, s2;
    cin >> s1 >> s2;
    
    // L and R track the contiguous range of optimal columns to turn down
    int L = 0, R = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        if (s1[i + 1] < s2[i]) {
            // Strictly better to move right. 
            // Any previous turn-down options are invalidated.
            L = i + 1;
            R = i + 1;
        } else if (s1[i + 1] == s2[i]) {
            // Tie. Turning down here or moving right gives the same result.
            // Extend the range of optimal turn points.
            R = i + 1;
        } else {
            // Strictly better to move down. 
            // We must turn down here, stopping any further rightward exploration.
            break;
        }
    }
    
    // Build the optimal string using the earliest optimal turn point L
    string optimal_string = s1.substr(0, L + 1) + s2.substr(L);
    
    // The number of paths yielding this string is the size of the valid turn range
    int ways = R - L + 1;
    
    cout << optimal_string << "\n" << ways << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}