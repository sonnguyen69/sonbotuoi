#include<bits/stdc++.h>
using namespace std;
long long n, m, a[100001];
bool check(long long t) {
    long long tam = 0;
    for (int i = 1; i <= m; i++) {
        tam += (a[i] + t - 1) / t;
        if (tam > n) return 0;
    }
    if (tam < n) return 1;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i];
    long long l = 1, r = *max_element(a + 1, a + m + 1), kq = r;
    while (l <= r) {
        long long m = (l + r) / 2;
        if (check(m)) {
            kq = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << kq;
}
