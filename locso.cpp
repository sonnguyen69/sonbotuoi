#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<string>a;
    vector<string>b;
    string s;
    getline(cin, s);
    s = ' ' + s;
    s += ' ';
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            s.insert(i, " ");
            i++;

        }
        if (isdigit(s[i]) == 0 && s[i] != '-')
            s[i] = ' ';
        while (s[i] == '0' && s[i - 1] == ' ')
            s[i] = ' ';
    }

    string c;
    stringstream ss(s);
    while (ss >> c) {
        if (c[0] == '-') {
            c.erase(0, 1);
            b.push_back(c);
        } else {
            a.push_back(c);
        }
    }
    string res = "";

    for (int i = 0; i < a.size(); i++) {
        if (a[i].size() > res.size())
            res = a[i];
        else if (a[i].size() == res.size()) {
            if (a[i] > res)
                res = a[i];
        }
    }

    if (res != "")
        cout << res;
    else {
        string res1 = b[0];
        for (int i = 1; i < b.size(); i++) {
            if (b[i].size() < res1.size())
                res1 = b[i];
            else if (b[i].size() == res1.size()) {
                if (b[i] < res1)
                    res1 = b[i];
            }
        }
        if (res1 != "0")
            res1 = "-" + res1;
        cout << res1;
    }

}
