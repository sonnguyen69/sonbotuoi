#include<bits/stdc++.h>
#define ll long long
#define MAXN 100007
using namespace std;
ll n, m;
ll a[MAXN], b[MAXN];
bool check(ll a[], ll b[], ll k) {
    ll j = 1;
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res = a[i];
        while (j <= m && res < k) {
            res = a[i] + b[j];
            j++;
        }
        if (j == m + 1 && res < k) {
            return 0;
        }
    }
    return 1;
}
int main() {
    cin >> n;
    ll res1 = 0, res2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        res1 = max(res1, a[i]);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        res2 = max(res2, b[i]);
    }
    ll l = 1;
    ll r = res1 + res2;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(a, b, mid)) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";

}
