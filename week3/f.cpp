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
        string s;
        cin >> s;
        int first_known = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] != '?') {
                first_known = i;
                break;
            }
        }
        if(first_known == -1){
            for(int i = 0; i < n; i++) s[i] = (i%2 == 0)? 'B':'R';
        }
        else {
            for(int i = first_known-1; i >= 0; i--) s[i] = (s[i+1] == 'B')? 'R':'B';
            for(int i = first_known+1; i < n; i++) {
                if(s[i] == '?') s[i] = (s[i-1] == 'B')? 'R':'B';
            }
        }
        cout << s << '\n';
    }
    return 0;
}