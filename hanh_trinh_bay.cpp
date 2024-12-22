#include<bits/stdc++.h>
using namespace std;
int main() {
    string s, s1;
    cin >> s >> s1;
    int i = 0, j = 0;
    while (i < s.size() && j < s1.size()) {
        if (s[i] == s1[j]) {
            i++;
            j++;
        } else i++;
    }
    if (j == s1.size()) cout << "YES";
    else cout << "NO";
}
