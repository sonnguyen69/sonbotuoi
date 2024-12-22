#include<bits/stdc++.h>
using namespace std;
int a[10007], f[100007];
int main() {
    int n;
    cin >> n;
    int ans = -1e8;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j <= i; j++) {
            if (a[j] < a[i]) {
                if (f[i] < f[j] + 1) {
                    f[i] = f[j] + 1;
                }
            }
        }
        ans = max(ans, f[i]);
    }
    cout << ans;
}
