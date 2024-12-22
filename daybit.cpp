#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    int maxx = INT_MIN;
    if (s.size() <= 1)
        cout << 0;
    else {
        s[s.size()] = '3';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != s[i + 1]) {
                int res = 2;
                int r = i - 1;
                int l = i + 2;
                while (s[r] != s[l] && (s[r] == s[r + 1]) && s[l] == s[l - 1]) {
                    res += 2;
                    r--;
                    l++;
                }
                if (res > maxx)
                    maxx = res;
            }
        }
        cout << maxx;
    }
}
