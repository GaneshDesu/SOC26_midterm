#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> ans;
    int curr_candy = 1;
    while(n > 0) {
        if(n - curr_candy > curr_candy) {
            ans.push_back(curr_candy);
            n -= curr_candy;
            curr_candy++;
        }
        else {
            ans.push_back(n);
            break;
        }
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size()-1; i++) cout << ans[i] << " ";
    cout << ans[ans.size()-1] << "";
    cout << '\n';
    return 0;
}