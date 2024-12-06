#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll modu(ll a, ll m) {
    ll res = 1, exp = m - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        exp /= 2;
    }
    return res;
}

ll dem(int x) {
    ll t = 1;
    for (int i = 1; i <= 9; i++) {
        t = (t * (x + i)) % mod;             
        t = (t * modu(i, mod)) % mod; 
    }
    return t;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << dem(x) << "\n";
    }
    return 0;
}
