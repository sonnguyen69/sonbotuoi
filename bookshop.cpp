#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005],p[1000001];
int main()
{
    int n,x; cin>>n>>x;
    vector<pair<int,int>> v;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) v.push_back({a[i],b[i]});
    for (auto t:v)
    {
        int a=t.first,b=t.second;
        for (int i=x;i>=a;i--)
        {
            p[i]=max(p[i],p[i-a]+b);
        }
    }
    cout<<p[x];
}
