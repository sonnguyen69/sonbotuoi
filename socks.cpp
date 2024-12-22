#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;
int a[100001], n, i;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    int x;
    cin >> x;
    mp[x]++;
  }
  int dem = 0;
  for (auto y : mp)
    dem += y.second / 2;
  cout << dem;
}
