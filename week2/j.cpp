#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    // Read matrix a
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    // Read matrix b and store the positions of each element
    // pos_b[value] = {row_in_b, col_in_b}
    vector<pair<int, int>> pos_b(n * m + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int val;
            cin >> val;
            pos_b[val] = {i, j};
        }
    }

    // Maps to track which row/col in 'a' goes to which row/col in 'b'
    vector<int> row_map(n, -1);
    vector<int> col_map(m, -1);

    bool possible = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int val = a[i][j];
            int r_b = pos_b[val].first;
            int c_b = pos_b[val].second;

            // Check row consistency
            if (row_map[i] != -1 && row_map[i] != r_b) {
                possible = false;
            }
            row_map[i] = r_b;

            // Check column consistency
            if (col_map[j] != -1 && col_map[j] != c_b) {
                possible = false;
            }
            col_map[j] = c_b;
        }
    }

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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