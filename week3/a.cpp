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
        vector<int> a(n);
        int greatest = 0, least = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] > a[greatest]) greatest = i;
            if(a[i] < a[least]) least = i;
        }
        int moves = INT_MAX;
        moves = min(moves, (least+1 + n-greatest));
        moves = min(moves, (n-least + greatest+1));
        moves = min(moves, (max(greatest, least)+1));
        moves = min(moves, (n - min(greatest, least)));
        cout << moves << '\n';
    }
    return 0;
}