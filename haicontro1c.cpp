#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int b[1000001];
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,int>mp;
    map<int,int>mp1;
    for(int i=1;i<=n;i++)
       {
           cin>>a[i];
           mp[a[i]]++;
       }
    for(int i=1;i<=m;i++)
        {
            cin>>b[i];
            mp1[b[i]]++;
        }
    long long res=0;
    for(auto x:mp)
    {
        if(mp1[x.first]!=0)
            res+=x.second*mp1[x.first];
    }
    cout<<res;

}
