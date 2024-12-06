#include<bits/stdc++.h>
#define ll long long
#define MAXN 10000007
using namespace std;
ll a[MAXN], f[MAXN];
void snt()
{
    for (ll i=1; i<=MAXN; i++)
    {
        f[i]=1;
    }
    for (ll i=2; i*i<=MAXN; i++)
    {
        if(f[i])
        {
            ll j=i*i;
            while(j<MAXN)
            {
                f[j]=0;
                j+=i;
            }
        }
    }
}
bool check(ll x)
{
    ll cnt=0;
    if(f[x]==1) return 0;
    if(sqrt(x)==floor(sqrt(x)))
    {
        ll k=floor(sqrt(x));
        if(f[k]==1) return 1;
        else return 0;
    }
    for (ll i=2; i*i<=x; i++)
    {
        while(x%i==0)
        {
            cnt++;
            if(cnt>1)
            {
                return 0;
            }
            x=x/i;
        }
    }
    return 1;
}
int main()
{
    snt();
    ll ans=0;
    ll n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        ll x;
        cin>>x;
        if(check(x))
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
}
