#include<bits/stdc++.h>
using namespace std;
bool check(int d, string& s) {
    int changes = 0;
    int n = s.size();
    for(int r = 0; r < d; r++) {
        vector<int> freq(26, 0);
        int cnt = 0;
        for(int i = r; i < n; i+=d) {
            freq[s[i]-'a']++;
            cnt++;
        }
        int mx = *max_element(freq.begin(), freq.end());
        changes += cnt-mx;
        if(changes > 1) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> divisors;
        for(int i = 1; i*i <= n; i++) {
            if(n%i == 0) {
                divisors.push_back(i);
                if(i*i != n) divisors.push_back(n/i);
            }
        }
        sort(divisors.begin(), divisors.end());
        for(int i = 0; i < divisors.size(); i++) {
            if(check(divisors[i], s)) {
                cout << divisors[i] << '\n';
                break;
            }
        }
    }
    return 0;
}