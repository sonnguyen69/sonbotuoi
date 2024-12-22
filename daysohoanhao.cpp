#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, k;
int a[100001];
ll f[100001];
map<ll, ll> mp;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[0] = 0;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + a[i];
    ll cnt = 0;
    mp[0]++;
    for (int i = 1; i <= n; i++) {
        if (mp[f[i] - k] != 0) cnt += mp[f[i] - k];
        mp[f[i]]++;
    }
    cout << cnt;
}
