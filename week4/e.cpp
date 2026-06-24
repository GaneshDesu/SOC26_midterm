#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int rest = 0, sport = INT_MAX, contest = INT_MAX;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int next_rest = min({rest, sport, contest}) + 1;
        int next_contest = INT_MAX, next_sport = INT_MAX;
        if(a == 1 || a == 3) next_contest = min({rest, sport});
        if(a == 2 || a == 3) next_sport = min({rest, contest});
        sport = next_sport;
        rest = next_rest;
        contest = next_contest;
    }
    cout << min({rest, sport, contest}) << '\n';
    return 0;
}