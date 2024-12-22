#include<bits/stdc++.h>
using namespace std;
using i64 = int64_t;
const int N = 1e6;
const int INF = 1e9;
//global var here
int n, s, t[101], dp[N + 1], ans;
//--------------------------------------------
//smol func here

//--------------------------------------------
//main func here
main() {
    //ඞ fastio
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //var here

    //----------------------------------------
    //logic here
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> t[i];
    sort(t + 1, t + n + 1);
    for (int i = 1; i <= N / n; i++) {
        dp[i] = INF;
        for (int j = 1; j <= n; j++) {
            if (t[j] <= i) {
                dp[i] = min(dp[i], dp[i - t[j]] + 1);
            } else break;
        }
    }

    if (s <= N / n) {
        cout << dp[s];
        return 0;
    }

    ans = INF;

    int time = 0;
    for (int i = s / t[n]; i > 0; i--) {
        int x = s - t[n] * i;
        if (x > N / n || time > N) break;
        ans = min(ans, i + dp[x]);
        time++;
    }

    cout << ans;
    //----------------------------------------
    //return 0;
}
//--------------------------------------------