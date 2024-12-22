#include<bits/stdc++.h>
using namespace std;
int  n, m, q;
long long a[1001][1001], f[1001][1001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 0; i <= n; i++) f[i][0] = 0;
    for (int j = 0; j <= m; j++) f[0][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
    cin >> q;
    while (q--) {
//        tdo o batdau: a b
//        tdo o kthuc: x y
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        cout << f[x][y] - f[x][b - 1] - f[a - 1][y] + f[a - 1][b - 1];
        cout << "\n";
    }
}
