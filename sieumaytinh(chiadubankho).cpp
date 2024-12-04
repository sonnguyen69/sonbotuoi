#include<bits/stdc++.h>
using namespace std;
#define ll long long
// Hàm tính (a^b) % mod bằng lũy thừa nhanh
ll chiadu(ll a, ll b, ll mod) {
    ll result = 1;
    a = a % mod;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        b /= 2;
        a = (a * a) % mod;
    }
    return result;
}
// Hàm tính hàm phi Euler của số nguyên dương
ll eulerPhi(ll n) {
    ll result = n;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}
// Hàm chuyển số lớn (string) thành mod
ll modd(string a, ll mod) {
    ll result = 0;
    for (char x : a) {
        result = (result * 10 + (x - '0')) % mod;
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    ll c;
    cin >> a;
    cin >> b;
    cin >> c;
    ll a_mod_c = modd(a, c);
    // Tính phi(c)
    ll phi_c = eulerPhi(c);
    // Tính b mod phi(c)
    ll b_mod_phi = modd(b, phi_c);
    // Tính kết quả (a^b) % c
    ll result = chiadu(a_mod_c, b_mod_phi, c);
    cout << result;
}
