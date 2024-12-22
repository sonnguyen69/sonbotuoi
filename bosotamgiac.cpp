#include <bits/stdc++.h>
using namespace std;
#define ll long long
int tknp(ll a[], int l, int r, ll t) {
    int res = l - 1;
    while (l <= r) {
        int g = (l + r) / 2;
        if (a[g] < t) {
            res = g;
            l = g + 1;
        } else {
            r = g - 1;
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    ll kq = 0;
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            ll t = a[i] + a[j];
            int k = tknp(a, j + 1, n, t);
            if (k > j) {
                kq += (k - j);
            }
        }
    }
    cout << kq;
}

