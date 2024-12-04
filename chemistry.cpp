#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    map<char, int> mp;
    mp['C']=12;
    mp['H']=1;
    mp['O']=16;
    ll sum=1;
    ll sumr=1;
    ll ans=0;
    string s;
    cin>>s;
    stack<char> st;
    stack<int> so;
    for (int i=s.size()-1; i>=0; i--)
    {
        if(isdigit(s[i]) && s[i-1]==')')
        {
            sum=sum*(int(s[i])-48);
            so.push(int(s[i])-48);
        }
        else if(isdigit(s[i]) && s[i-1]!=')')
        {
            sumr=sumr*(int(s[i])-48);
        }
        else if(s[i]==')')
        {
            st.push(s[i]);
        }
        else if(isalpha(s[i]))
        {
            ans=ans+mp[s[i]]*sum*sumr;
            sumr=1;
        }
        else if(s[i]=='(')
        {
            st.pop();
            sum=sum/so.top();
            so.pop();
        }
    }
    cout<<ans<<"\n";
}
