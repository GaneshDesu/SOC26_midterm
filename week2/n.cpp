#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int n;
    long long k; // k can be up to 2 * 10^9
    cin >> n >> k;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // health_at_dist[d] stores the total health of all monsters starting at distance d
    vector<long long> health_at_dist(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int dist = abs(x);
        health_at_dist[dist] += a[i];
    }
    
    long long total_health = 0;
    bool possible = true;
    
    for (int i = 1; i <= n; ++i) {
        total_health += health_at_dist[i];
        
        // If the total health of monsters at distance <= i exceeds the bullets 
        // we can fire in i seconds, we lose.
        if (total_health > i * k) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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