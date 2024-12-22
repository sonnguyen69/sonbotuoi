#include<bits/stdc++.h>
using namespace std;
int a[200007];
vector<int> v;
int main() {
    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    v.push_back(a[1]);
    for (int i = 2; i <= n; i++) {
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), a[i]);
        if (it == v.end())
            v.push_back(a[i]);
        else
            v[it - v.begin()] = a[i];
    }
    cout << v.size();
}
