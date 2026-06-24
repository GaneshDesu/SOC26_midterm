#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fenwick Tree (Binary Indexed Tree) for O(log N) sum queries
struct FenwickTree {
    int n;
    vector<int> bit;
    
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    
    // Add value to index
    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }
    
    // Prefix sum up to index
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }
};

struct Person {
    int a, b;
    // Sort primarily by starting position 'a' ascending
    bool operator<(const Person& other) const {
        return a < other.a;
    }
};

void solve() {
    int n;
    cin >> n;
    
    vector<Person> p(n);
    vector<int> b_vals(n);
    
    for (int i = 0; i < n; i++) {
        cin >> p[i].a >> p[i].b;
        b_vals[i] = p[i].b;
    }
    
    // 1. Sort people by starting positions
    sort(p.begin(), p.end());
    
    // 2. Coordinate Compression for 'b' values
    sort(b_vals.begin(), b_vals.end());
    
    FenwickTree fenwick(n);
    long long greetings = 0; // Use long long as max pairs can be O(N^2)
    
    // 3. Process each person and count inversions in 'b'
    for (int i = 0; i < n; i++) {
        // Find the compressed rank (1-indexed) of the current person's destination
        int rank = lower_bound(b_vals.begin(), b_vals.end(), p[i].b) - b_vals.begin() + 1;
        
        // Count how many PREVIOUSLY processed elements have a LARGER 'b' value
        // These are the people whose intervals strictly contain the current person's interval
        greetings += fenwick.query(n) - fenwick.query(rank);
        
        // Add current person's 'b' value to the Fenwick Tree
        fenwick.add(rank, 1);
    }
    
    cout << greetings << "\n";
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}