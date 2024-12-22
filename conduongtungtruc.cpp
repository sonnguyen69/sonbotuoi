#include<bits/stdc++.h>
using namespace std;
struct tg {
    int u, v;
};
tg a[1000001];
int tu[1000001];
int tr[1000001];
bool cmp(tg x, tg y) {
    if (x.u < y.u)
        return 1;
    return 0;
}
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
        cin >> a[i].u >> a[i].v;
    sort(a + 1, a + n + 1, cmp);
    int tung = 0;
    int truc = 0;
    tu[0] = tr[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].v == 1) {
            tu[i] = tung + 1;
            tung++;
        } else
            tu[i] = tu[i - 1];
        if (a[i].v == 2) {
            tr[i] = truc + 1;
            truc++;
        } else
            tr[i] = tr[i - 1];
    }
    int j = 1;
    int t = 2e9;
    for (int i = 1; i <= n; i++) {
        while (tu[i] - tu[j - 1] >= x && tr[i] - tr[j - 1] >= y) {
            t = min(t, a[i].u - a[j].u);
            j++;
        }
    }
    if (t == 2e9)
        cout << -1;
    else
        cout << t;
}
