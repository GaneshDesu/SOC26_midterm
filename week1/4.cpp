#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> people(t, 0);
    vector<int> capacity(t, 0);
    for(int i = 0; i < t; i++) cin >> people[i] >> capacity[i];
    int count = 0;
    for(int i = 0; i < t; i++) {
        if(capacity[i] - people[i] >= 2) count++;
    }
    cout << count << '\n';
    return 0;
}