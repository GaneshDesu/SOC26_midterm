#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while(true) {
        n++;
        int a = n/1000;
        int b = (n/100)%10;
        int c = (n/10)%10;
        int d = n%10;
        if(a != b && a != c && a != d && b != c && b != d && c != d) {
            cout << n << '\n';
            break;
        }
    }
    return 0;
}