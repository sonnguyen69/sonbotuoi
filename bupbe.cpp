#include<bits/stdc++.h>
using namespace std;
int a[100007];
bool b[100007];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = 1;
    }
    sort(a + 1, a + n + 1, greater<int>());
    long long tong = 0;
    int i = 1, j = 2;
    while (i <= n && j <= n) {
        if (a[i] - a[j] >= k) {
            if (b[i] == 1) tong += a[i];
            b[i] = 0;
            b[j] = 0;
            i++;
            j++;
        } else {
            j++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == 1) tong += a[i];
    }
    cout << tong;
}
