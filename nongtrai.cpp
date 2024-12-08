#include<bits/stdc++.h>
using namespace std;
#define ll long long
char a[2001][2001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
ll demc = 0;
ll demf = 0;
ll n, m;
void bfs(int i, int j) {
    ll c = 0;
    ll f = 0;
    queue<pair<int, int>> q;
    if (a[i][j] == 'c') c++;
    if (a[i][j] == 'f') f++;
    a[i][j] = '#';
    q.push({i, j});
    while (!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        int x = top.first;
        int y = top.second;
        for (int k = 0; k < 4; k++) {
            int x1 = x + dx[k];
            int y1 = y + dy[k];
            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && a[x1][y1] != '#') {
                if (a[x1][y1] == 'c') {
                    c++;
                } else if (a[x1][y1] == 'f') {
                    f++;
                }
                a[x1][y1] = '#';
                q.push({x1, y1});
            }
        }
    }
    if (c <= f) {
        demf += f;
    } else {
        demc += c;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != '#') {
                bfs(i, j);
            }
        }
    }
    cout << demf << "\n";
    cout << demc;
}
