#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll catalan(int k) {
    ll kq = 1;
    for (int i = 0; i < k; i++) {
        kq = kq * (2 * k - i) / (i + 1); // Tính từng bước
    }
    return kq / (k + 1); 
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n % 2 != 0 || n < 2 || n > 30) {
        cout << "Invalid input" << endl;
        return 0;
    }
    cout << catalan(n / 2);
}
