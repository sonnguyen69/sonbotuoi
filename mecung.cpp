#include<bits/stdc++.h>
using namespace std;
int n, m;
char a[2001][2001];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
vector<char>v;
char d[2001][2001];
void bt(int i, int j) {
    if ((d[i][j]) != 'X') {
        v.push_back(d[i][j]);
        char c = d[i][j];
        if (c == 'U') {
            bt(i + 1, j);
        } else if (c == 'D') {
            bt(i - 1, j);
        } else if (c == 'L') {
            bt(i, j + 1);
        } else if (c == 'R') {
            bt(i, j - 1);
        }
    }
}
void bfs(int i, int j) {
    d[i][j] = 'X';
    queue<pair<int, int>>q;
    q.push({i, j});
    a[i][j] = '#';
    while (!q.empty()) {
        pair<int, int>top = q.front();
        q.pop();
        int x = top.first;
        int y = top.second;
        for (int k = 0; k < 4; k++) {
            int i1 = x + dx[k];
            int j1 = y + dy[k];
            if (i1 <= n && i1 >= 1 && j1 <= m && j1 >= 1 && a[i1][j1] != '#') {
                if (dx[k] == -1) {
                    d[i1][j1] = 'U';
                } else if (dx[k] == 1) {
                    d[i1][j1] = 'D';
                } else if (dy[k] == -1) {
                    d[i1][j1] = 'L';
                } else {
                    d[i1][j1] = 'R';
                }
                if (a[i1][j1] == 'B') {
                    a[i1][j1] = '#';
                    bt(i1, j1);
                    return;
                }
                a[i1][j1] = '#';
                q.push({i1, j1});
            }

        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int e1, e2;
    int s1, s2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                s1 = i;
                s2 = j;
            } else if (a[i][j] == 'B') {
                e1 = i;
                e2 = j;
            }
        }
    }
    bfs(s1, s2);
    if (a[e1][e2] == 'B') {
        cout << "NO";
    } else {
        cout << "YES" << "\n";
        cout << v.size() << "\n";
        for (int i = v.size() - 1; i >= 0; i--)
            cout << v[i];

    }
}
