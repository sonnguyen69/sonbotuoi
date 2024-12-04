#include <bits/stdc++.h>
using namespace std;
int a[25][25], n, m;
void hcnmax() {
    int kq = 0;
    vector<int> h(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                h[j]++;
            } else {
                h[j] = 0; 
            }
        }
        vector<int> l(m, -1), r(m, m);
        stack<int> s;
        for (int j = 0; j < m; j++) {
            while (!s.empty() && h[s.top()] >= h[j]) {
                s.pop();
            }
            if (!s.empty()) {
                l[j] = s.top();
            }
            s.push(j);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int j = m - 1; j >= 0; j--) {
            while (!s.empty() && h[s.top()] >= h[j]) {
                s.pop();
            }
            if (!s.empty()) {
                r[j] = s.top();
            }
            s.push(j);
        }
        for (int j = 0; j < m; j++) {
            int width = r[j] - l[j] - 1;
            int height = h[j];
            if (width > 0 && height > 0) {
                int perimeter = 2 * (width + height);
                kq = max(kq, perimeter);
            }
        }
    }

    cout << kq << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    hcnmax();
    return 0;
}
