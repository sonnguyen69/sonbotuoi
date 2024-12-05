#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1000005];
struct sonbotuoi{
    ll w, v;
};
sonbotuoi a[1000005];
bool cmp(sonbotuoi x,sonbotuoi y)
{
    return y.w * x.v > x.w * y.v;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m, tam = 0;
    cin >> n >> m;
    for (ll x = 1; x <= n; x++) {
        cin >> a[x].w >> a[x].v;
    }
    sort(a + 1, a + 1 + n,cmp);
    for (ll x = 1; x <= n; x++) {
        ll w = a[x].w, v = a[x].v;
        tam = min(m, tam + w);
        for (ll y = tam; y >= max(tam - 10, w); y--) {
            dp[y] = max(dp[y], dp[y - w] + v);
        }
    }
    ll ans = *max_element(dp + 1, dp + 1 + m);
    cout << ans;
    return 0;
}
