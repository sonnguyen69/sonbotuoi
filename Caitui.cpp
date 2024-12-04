#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1000005];
struct node {
    ll w, v;
    bool operator < (const node &a) const {
        return v * a.w > w * a.v;
    }
} a[1000005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, m, tam = 0;
    cin >> n >> m;
    for (ll x = 1; x <= n; x++) {
        cin >> a[x].w >> a[x].v;
    }
    sort(a + 1, a + 1 + n);
    for (ll x = 1; x <= n; x++) {
        ll w = a[x].w, v = a[x].v;
        tam = min(m, tam + w);
        for (ll y = tam; y >= max(tam - 10, w); y--) {
            dp[y] = max(dp[y], dp[y - w] + v);
        }
    }
    ll ans = *max_element(dp + 1, dp + 1 + m);
    cout << ans << '\n';
    return 0;
}
