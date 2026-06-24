#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        vector<string> grid = {s1, s2};
        queue<pair<int, int>> q;
        q.push({0, 0});
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        vector<vector<int>> vis(2, vector<int>(n, 0));
        vis[0][0] = 1;
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr < 0 || nr > 1 || nc < 0 || nc >= n) continue;
                if(grid[nr][nc] == '>') nc++;
                else nc--;
                if(nc < 0 || nc >= n) continue;
                if(!vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        cout << (vis[1][n-1] == 1? "YES": "NO") << '\n';
    }
    return 0;
}