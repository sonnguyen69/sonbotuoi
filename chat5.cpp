#include<bits/stdc++.h>
#define ll long long
#define MAXN 1000007
using namespace std;
ll a[MAXN];
ll n, k;
bool check(ll a[], ll r, ll k)
{
    ll cnt=0;
    for (ll i=1; i<=n; i++)
    {
        cnt+=a[i]/r;
    }
    return cnt>=k;
}
int main()
{
    cin>>n>>k;
    ll res=0;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        res=max(res, a[i]);
    }
    ll l=1;
    ll r=res;
    ll ans=res;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(a, mid, k))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans<<"\n";
}
