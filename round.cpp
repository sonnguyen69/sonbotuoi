#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        ll res = 1;
        ll cnt = 0;
        stack<ll> q;
        while (x > 0) {
            ll k = x % 10;
            if (k != 0) {
                q.push(k * res);
                cnt++;
            }
            res *= 10;
            x /= 10;
        }
        cout << cnt << "\n";
        while (!q.empty()) {
            cout << q.top() << " ";
            q.pop();
        }
        cout << "\n";
    }
}

