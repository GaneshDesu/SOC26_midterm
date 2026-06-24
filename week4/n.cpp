#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    long long current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += h[i];
    }
    long long min_sum = current_sum;
    int min_index = 0;
    for (int i = 1; i <= n - k; i++) {
        current_sum = current_sum - h[i - 1] + h[i + k - 1];
        if (current_sum < min_sum) {
            min_sum = current_sum;
            min_index = i;
        }
    }
    cout << min_index + 1 << "\n";
    return 0;
}