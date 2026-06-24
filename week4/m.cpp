#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int total_ones = 0;
    int max_gain = -1;
    int curr_gain = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(a == 1) {
            total_ones++;
            curr_gain -= 1;
        }
        else curr_gain += 1;
        if(curr_gain > max_gain) max_gain = curr_gain;
        if(curr_gain < 0) curr_gain = 0;
    }
    cout << total_ones + max_gain << '\n';
    return 0;
}