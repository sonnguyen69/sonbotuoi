#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> dp(k + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j] <= i && dp[i - a[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    if (dp[k] == INT_MAX) {
        cout << -1;
        return 0;
    }
    cout << dp[k];
    return 0;
}
