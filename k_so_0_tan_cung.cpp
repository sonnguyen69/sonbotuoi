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
    i64 a, b, c, k, prod, cnt2 = 0, cnt5 = 0, ans = 1;
    //----------------------------------------
    //logic here
    cin >> a >> b >> k;
    prod = a * b;
    while (prod % 5 == 0) {
        cnt5++;
        prod /= 5;
    }
    while (prod % 2 == 0) {
        cnt2++;
        prod /= 2;
    }
    if (cnt2 < k) ans *= pow(2, k - cnt2);
    if (cnt5 < k) ans *= pow(5, k - cnt5);
    cout << ans;
    //----------------------------------------
    //return 0;
}
//--------------------------------------------
