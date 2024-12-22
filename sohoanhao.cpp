#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long x;
    cin >> x;
    long long T = 1;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            T = T + i + (x / i);
    if (sqrt(x) == floor(sqrt(x)))
        T = T - floor(sqrt(x));
    if (T == x)
        cout << "YES";
    else cout << "NO";
}
