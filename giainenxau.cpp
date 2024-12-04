#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string ans="";
    cin>>s;
    int res;
    if(isdigit(s[0]))
    {
        res=0;
    }
    else res=1;
    for (int i=0; i<s.size(); i++)
    {
        if(isdigit(s[i]))
        {
            res=res*10+int(s[i])-48;
        }
        else
        {
            while(res--)
            {
                ans=ans+s[i];
            }
            if(isdigit(s[i+1]))
            {
                res=0;
            }
            else res=1;
        }
    }
    cout<<ans<<"\n";
}
