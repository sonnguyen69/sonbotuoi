#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100001], b[100001];
ll n, k;
bool kt(ll a[], ll b[], ll res) {
    ll dem = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < res) {
            dem += (res - a[i] + b[i] - 1) / b[i];
        }

        if (dem > k)   return 0;
    }
    return dem <= k;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    ll vtmax = 0, gtrimax = 0;
    for (int i = 1; i <= n; i++)   cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++) {
        if (b[i] > gtrimax) {
            gtrimax = b[i];
            vtmax = i;
        }
    }
    ll l = 1;
    ll r = a[vtmax] + gtrimax * k;
    ll res = 0;
    while (l <= r) {
        ll g = (l + r) / 2;
        if (kt(a, b, g)) {
            res = g;
            l = g + 1;
        } else r = g - 1;
    }
    cout << res;
}
