#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

// Function to calculate (base^exp) % MOD in O(log exp) time
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    
    vector<long long> a(n);
    long long total_sum = 0;
    long long current_max = 0;
    long long max_so_far = 0;
    
    // Read array, calculate total sum, and find max subarray sum (Kadane's)
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];
        
        current_max += a[i];
        if (current_max < 0) {
            current_max = 0; // Empty subarray
        }
        if (current_max > max_so_far) {
            max_so_far = current_max;
        }
    }
    
    // M is the maximum contiguous subarray sum
    long long M = max_so_far % MOD;
    
    // P = (2^k - 1) mod MOD
    long long P = (power(2, k) - 1 + MOD) % MOD;
    
    // added_sum = M * (2^k - 1) mod MOD
    long long added_sum = (M * P) % MOD;
    
    // final_sum = (total_sum + added_sum) mod MOD
    long long final_sum = (total_sum % MOD + added_sum) % MOD;
    
    // Ensure the final modulo result is strictly non-negative
    final_sum = (final_sum + MOD) % MOD;
    
    cout << final_sum << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}