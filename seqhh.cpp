#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
// global var here

//--------------------------------------------
// smol func here

//--------------------------------------------
// main func here
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // var here
    int n, k, x;
    i64 sum = 0, ans = 0;
    map<int, int> f;
    //----------------------------------------
    // logic here
    cin >> n >> k;
    while (n--) {
        cin >> x;
        sum += x;
        if (sum == k) ans++;
        ans += f[sum - k];
        f[sum]++;
    }
    cout << ans;
    //----------------------------------------
    // return 0;
}
//--------------------------------------------