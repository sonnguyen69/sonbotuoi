#include<bits/stdc++.h>
using namespace std;
using i64 = int64_t;
//global var here

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
    int n, ans = 0;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    //----------------------------------------
    //logic here
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (__gcd(a[i], a[j]) > 1) ans++;
        }
    }
    cout << ans;
    //----------------------------------------
    //return 0;
}
//--------------------------------------------      