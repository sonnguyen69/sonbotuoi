#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<char, int> mp;
    int cnt = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }
    string ans = "";
    for (auto x : mp) {
        if (x.second % 2 == 1) {
            cnt++;
            for (int i = 1; i <= x.second; i++) {
                ans += x.first;
            }
            mp[x.first] = 0;
        }
    }
    if (cnt > 1) {
        cout << "NO SOLUTION" << "\n";
    } else {
        for (auto x : mp) {
            for (int i = 1; i <= x.second / 2; i++) {
                ans += x.first;
            }
            for (int i = 1; i <= x.second / 2; i++) {
                ans = x.first + ans;
            }
            mp[x.first] = 0;
        }
        cout << ans << "\n";
    }
}
