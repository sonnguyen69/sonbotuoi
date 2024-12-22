#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(a, b % a);
}
bool daoso(string x) {
    long long tam1 = 0;
    for (int i = 0; i < x.size(); i++) {
        tam1 = tam1 * 10 + (x[i] - '0');
    }
    reverse(x.begin(), x.end());
    long long tam2 = 0;
    for (int i = 0; i < x.size(); i++) {
        tam2 = tam2 * 10 + (x[i] - '0');
    }
    if (gcd(tam1, tam2) == 1) return 1;
    else return 0;
}
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        if (daoso(s)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
