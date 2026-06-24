#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, c0, d0;
    if (!(cin >> n >> m >> c0 >> d0)) return 0;

    // dp[j] stores the maximum tugriks we can earn using 'j' grams of dough
    vector<int> dp(n + 1, 0);

    // 1. Process buns WITHOUT stuffing (Unbounded Knapsack)
    // We iterate forward because taking one bun allows us to take another
    for (int j = c0; j <= n; j++) {
        dp[j] = max(dp[j], dp[j - c0] + d0);
    }

    // 2. Process buns WITH stuffing (Bounded 0/1 Knapsack)
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        // Calculate the maximum number of this specific bun we can make
        int max_buns = a / b;
        
        // Treat each bun we can make as a separate 0/1 knapsack item
        for (int k = 0; k < max_buns; k++) {
            // Iterate backwards to ensure we only use each specific bun once
            for (int j = n; j >= c; j--) {
                dp[j] = max(dp[j], dp[j - c] + d);
            }
        }
    }

    // The answer is the maximum value in the dp array
    // (It might not necessarily be at exactly dp[n] if we have leftover dough we can't use)
    int max_profit = 0;
    for (int j = 0; j <= n; j++) {
        max_profit = max(max_profit, dp[j]);
    }

    cout << max_profit << "\n";

    return 0;
}