#include<bits/stdc++.h>
using namespace std;
void sol() {
    vector<int> dp(10001, 1e9);
    bool used[10001][101];
    int n, k, a[101];
    cin >> n >> k;
    dp[0] = 0;
    memset(used, false, sizeof(used));
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j <= k; j++) {
            if (dp[j - a[i]] != 1e9 && dp[j - a[i]] + a[i] <= k && !used[j - a[i]][i]) {
                dp[j] = dp[j - a[i]] + a[i];
                used[j][i] = true;
            }
        }
    }
    if (dp[k] == 1e9) cout << "NO\n";
    else cout << "YES\n";
}
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) sol();
}