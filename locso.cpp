#include<bits/stdc++.h>
#define ll long long
#define MAXN 1000007
using namespace std;

int main() {
    string s;
    getline(cin, s);
    string res = "";
    string ans = "";
    bool kt=1;
    bool ktres=0;
    for (ll i = 0; i <= s.size(); i++)
    {
        if (s[i]=='-') kt=0;
        if (i < s.size() && isdigit(s[i]))
        {
            res += s[i];
        }
        else
            {
            if (!res.empty())
            {
                while (res.size() > 1 && res[0] == '0')
                {
                    res.erase(0, 1);
                }
                if(res=="0" && ktres==0)
                {
                    ans="0";
                }
                else if ((res.size() > ans.size() || (res.size() == ans.size() && res > ans)) && kt>=ktres)
                {
                    ans = res;
                    if(kt)
                    {
                        ktres=1;
                    }
                    else ktres=0;
                }
                res = "";
            }
        }
    }

    cout << ans << "\n";
}
