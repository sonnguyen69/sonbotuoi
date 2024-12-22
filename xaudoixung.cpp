#include<bits/stdc++.h>
using namespace std;
int main() {
    map<char, int> mp;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }
    int odd = 0;
    int ans = 0;
    bool kt = 0;
    for (auto x : mp) {
        if (x.second % 2 == 0) {
            ans += x.second;
        } else {
            odd = odd + (x.second / 2) * 2;
            kt = 1;
        }
    }
    if (kt == 1) {
        cout << ans + odd + 1 << "\n";
    } else {
        cout << ans + odd << "\n";
    }
}
