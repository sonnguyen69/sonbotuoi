#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll last(ll a, ll b, ll k) {
    if (b == 0) return 1;
    if (b == 1) return a % k;
    ll p = last(a, b / 2, k);
    if (b % 2 == 0) return ((p % k) * (p % k)) % k;
    else return ((p % k) * (p % k) * (a % k)) % k;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        cout << last(a, b, 10) << "\n";
    }
}
