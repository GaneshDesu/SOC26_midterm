#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
double dfs(int u, int parent) {
    double sum_expected_lengths = 0.0;
    int children_count = 0;
    for(int v : adj[u]) {
        if(v != parent) {
            children_count++;
            sum_expected_lengths += dfs(v, u);
        }
    }
    if(children_count == 0) return 0.0;
    return 1.0 + (sum_expected_lengths/children_count);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    adj.resize(n+1);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << fixed << setprecision(15);
    cout << dfs(1, 0) << '\n';
    return 0;
}