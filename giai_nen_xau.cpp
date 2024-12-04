#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s; cin>>s;
    string ss;
    int i=0;
    while (i<s.size())
    {
        if (isdigit(s[i]))
        {
            int tam=(s[i]-'0');
            i++;
            while (i<s.size() && isdigit(s[i]))
            {
                tam=tam*10+(s[i]-'0');
                i++;
            }
            for (int j=1;j<=tam;j++)
                cout<<s[i];
            i++;
        }
        else
        {
            cout<<s[i];
            i++;
        }

    }
}
