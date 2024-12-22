#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
int main() {
    int n; cin >> n;
    vector<pair<int, int>> vp;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        vp.push_back({x, y});
    }
    sort(vp.begin(), vp.end(), cmp);
    int dem = 1;
    int tam = vp[0].second;
    for (int i = 1; i < n; i++) {
        if (vp[i].first >= tam) {
            dem++;
            tam = vp[i].second;
        }
    }
    cout << dem;
}
