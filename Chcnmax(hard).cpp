#include <bits/stdc++.h>
using namespace std;
int hcnmax(int n, int m, vector<vector<int>> &a) {
    int kq = 0;
    vector<int> h(m, 0);
    for (int i = 0; i< n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0) {
                h[j]++;
            } else {
                h[j] = 0;
            }
        }
        vector<int> l(m, -1), r(m, m);
        stack<int> s;
        for (int i = 0; i < m; ++i) {
            while (!s.empty() && h[s.top()] >= h[i]) {
                s.pop();
            }
            if (!s.empty()) {
                l[i] = s.top();
            }
            s.push(i);
        }

        while (!s.empty()) s.pop();
        for (int i = m - 1; i >= 0; --i) {
            while (!s.empty() && h[s.top()] >= h[i]) {
                s.pop();
            }
            if (!s.empty()) {
                r[i] = s.top();
            }
            s.push(i);
        }
        for (int i = 0; i < m; ++i) {
            int cr = r[i] - l[i] - 1;
            int cc = h[i];
            if (cr > 0 && cc > 0) {
                int tam = 2 * (cc+ cr);
                kq = max(kq, tam);
            }
        }
    }

    return kq;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[j] - '0';
        }
    }

    cout << hcnmax(n, m, a) << endl;

    return 0;
}
