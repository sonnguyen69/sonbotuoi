#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
// global var here
int n, m, t = 0, island[102][102], check[102][102], check_connect[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
//--------------------------------------------
// smol func here
void loang(int y, int x, int k) {
    check[y][x] = 1;
    for (int o = 0; o < 4; o++) {
        int X = x + dx[o], Y = y + dy[o];
        if (X >= 1 && X <= m && Y >= 1 && Y <= n) {
            if (check[Y][X] == 0 && island[Y][X] <= k) loang(Y, X, k);
        }
    }
}

void dfs(int y, int x) {
    check_connect[y][x] = 1;
    for (int k = 0; k < 4; k++) {
        int X = x + dx[k], Y = y + dy[k];
        if (X >= 1 && X <= m && Y >= 1 && Y <= n) {
            if (check_connect[Y][X] == 0 && check[Y][X] == check[y][x]) dfs(Y, X);
        }
    }
}

void sol() {
    bool cut = false;
    int hMax = 0, ans = 0;

    // cin
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> island[i][j];
            hMax = max(hMax, island[i][j]);
        }
    }

    for (int k = 0; k <= hMax; k++) {
        // setup
        ans = k;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                check[i][j] = 0;
                check_connect[i][j] = 0;
            }
        }
        // loang nuoc bien
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if ((j == 1 || j == m || i == 1 || i == n) && island[i][j] <= k && check[i][j] == 0) {
                    loang(i, j, k);
                }
            }
        }
        // dem tplt la dat lien sau khi nuoc bien dang len k
        int cnt = 0;
        for (int x = 1; x <= m; x++) {
            for (int y = 1; y <= n; y++) {
                if (check_connect[y][x] == 0 && check[y][x] == 0) {
                    cnt++;
                    dfs(y, x);
                }
            }
        }
        if (cnt > 1) {
            cut = true;
            break;
        }
    }
    // cout
    if (cut) {
        cout << "Case " << t << ": Island splits when ocean rises " << ans << " feet." << '\n';
    } else {
        cout << "Case " << t << ": Island never splits.\n";
    }
}
//--------------------------------------------
// main func here
main() {
    // ඞ fastio
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    // var here

    //----------------------------------------
    // logic here
    while (1) {
        t++;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        else
            sol();
    }
    //----------------------------------------
    // return 0;
}
//--------------------------------------------