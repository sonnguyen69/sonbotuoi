#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll tknp(ll a[],ll l,ll r,ll k)
{
    ll res=-1;
    while(l<=r)
    {
        ll g=(l+r)/2;
        if(a[g]<=k)
        {
            res=a[g];
            l=g+1;
        }
        else r=g-1;
    }
    return res;
}
ll a[100001];
int main()
{
    ll n; cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll t; cin>>t;
    while(t--)
    {
        ll x; cin>>x;
        cout<<tknp(a,1,n,x)<<"\n";
    }
}
