#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000001],t[4000001];
void build(ll id, ll l,ll r)
{
    if(l == r)
    {
        t[id] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1 ,r);
    t[id] = t[id * 2] + t[id * 2 + 1];
}
void update(ll id,ll l,ll r, ll p, ll x)
{
    if(p < l || r < p)
    {
        return;
    }
    if(l == r)
    {
        t[id] = x;
        a[l] = x;
        return;
    }
    ll mid = (l + r) / 2;
    update(id * 2, l, mid, p, x);
    update(id * 2 + 1, mid + 1, r, p, x);
    t[id] = t[id * 2] + t[id * 2 + 1];
}
ll get(ll id, ll l, ll r, ll u,ll v)
{
    if(r < u || v < l) return 0;
    if(u <= l && r <= v) return t[id];
    ll mid = (l + r) / 2;
    ll t1 = get(id * 2, l, mid, u, v);
    ll t2 = get(id * 2 + 1, mid + 1, r, u, v);
    return t1 + t2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--)
    {
        int x;
        cin >> x;
        if(x == 2)
        {
            int a, b;
            cin >> a >> b;
            update(1, 1, n, a, b);
        }
        else if(x == 1)
        {
            int a, b;
            cin >> a >> b;
            cout << get(1, 1, n, a, b) << "\n";

        }
    }
}
