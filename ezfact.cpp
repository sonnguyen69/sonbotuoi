#include<bits/stdc++.h>
using namespace std;
using i64 = int64_t;
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    i64 f[21] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880,
        3628800, 39916800, 479001600, 6227020800, 87178291200,
        1307674368000, 20922789888000, 355687428096000,
        6402373705728000, 121645100408832000, 2432902008176640000};
    int t;
    i64 x;
    cin >> t;
    while (t--) {
        cin >> x;
        int ans = 0;
        for (int i = 0; i <= 21; i++) {
            if (f[i] == x) ans++;
        }
        cout << ans << '\n';
    }
}