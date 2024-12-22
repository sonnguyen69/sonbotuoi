#include<bits/stdc++.h>
#define ll long long
#define MAXN 1000007
using namespace std;
ll a[MAXN];
ll n;
ll check(ll a[], ll mid, ll k) {
    ll i = 1;
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] - mid > 0) {
            cnt += (a[i] - mid);
        }
    }
    if (cnt >= k) return 1;
    else return 0;
}
int main() {
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll l = a[1];
    ll r = a[n];
    ll ans = -1e18;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(a, mid, k)) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
}
