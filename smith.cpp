#include<bits/stdc++.h>
using namespace std;
int tcs(long long n) {
    int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}
int main() {
    long long n;
    cin >> n;
    int tam = tcs(n);
    int tam2;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            tam2 += tcs(i);
            n = n / i;
        }
    }
    if (n > 1)
        tam2 += tcs(n);
    if (tam2 == tam)
        cout << "YES";
    else
        cout << "NO";
}

