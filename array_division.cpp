#include<bits/stdc++.h>
#define ll long long
#define MAXN 200007
using namespace std;
ll ans=1e18;
ll res=-1e18;
ll n, k;
ll a[MAXN], f[MAXN];
bool div(ll a[], ll r, ll k)
{
    ll it=0;
    ll cnt=0;
    ll i=1;
    while(i<=n)
    {
        cnt++;
        it=i-1;
        while(i<=n && f[i]-f[it]<=r)
        {
            i++;
        }

    }
    if(cnt>k) return 0;
    return 1;

}
int main()
{
    cin>>n>>k;
    f[0]=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        f[i]=f[i-1]+a[i];
        res=max(a[i], res);
    }
    ll l=res;
    ll r=f[n];
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(div(a, mid, k))
        {
            ans=min(ans, mid);
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans<<"\n";
}
