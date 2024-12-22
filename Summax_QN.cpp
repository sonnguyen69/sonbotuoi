#include<bits/stdc++.h>
using namespace std;
long long a[501][501], t[501];
int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    long long kq = INT_MIN;
    for (int i = 1; i <= n; i++) {
        memset(t, 0, sizeof(t));
        for (int j = i; j <= n; j++) {
            long long sum = 0;
            long long tam = INT_MIN;
            for (int k = 1; k <= m; k++) {
                t[k] += a[j][k];
                sum = max(t[k], sum + t[k]);
                tam = max(tam, sum);
            }
            kq = max(kq, tam);
        }
    }
    cout << kq;
}
