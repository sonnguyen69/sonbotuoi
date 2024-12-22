#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t, i; cin >> n >> t;
    int a[n + 1];
    for (i = 1; i <= n; i++) cin >> a[i];
    int d = 1, c = 1, res = 0;
    int tong = a[1];
    for (c = 2; c <= n; c++) {
        tong += a[c];
        if (tong <= t && c + 1 - d > res) res = c + 1 - d;
        while (tong > t) {
            tong -= a[d];
            d++;
        }
    }
    cout << res;
}
