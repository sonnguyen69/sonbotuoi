#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    map<int,int>mp;
    for(int i=1;i<=n;i++)
        mp[a[i]]++;
    for(auto x:mp)
    {
        if(x.second%2==1 && (x.first<=s.size()/2))
        {

            reverse(s.begin()+(x.first-1),s.begin()+(s.size()-(x.first)+1));
        }
        else if(x.second%2==1 &&(x.first>s.size()/2))
        {
            reverse(s.begin()+(s.size()-x.first),s.begin()+(x.first));
        }
    }
    cout<<s;
}
