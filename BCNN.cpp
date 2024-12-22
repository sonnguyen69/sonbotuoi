#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int ucln(int a, int b) {
    if (b == 0)
        return a;
    return ucln(b, a % b);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<int>v;
        v.push_back(a[1]);
        for (int i = 1; i < n; i++) {
            int tam = (a[i] * a[i + 1]) / ucln(a[i], a[i + 1]);
            v.push_back(tam);
        }
        v.push_back(a[n]);
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << ' ';
        cout << endl;
    }
}
