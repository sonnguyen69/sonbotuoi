#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll a[10000001];
bool check(ll g,ll k,ll a[])
{
    ll t=0;
    for(ll i=1;i<=n;i++)
    {
        if(a[i]>g)  t=t+(a[i]-g);
    }
    return t>=k;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>n;
    ll k;
    cin>>k;
    ll maxx=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        maxx+=a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    ll l=1;
    ll r=a[1];
    ll kq=maxx;
    while(l<=r)
    {
        ll g=(l+r)/2;
        if(check(g,k,a))
        {
            kq=g;
            l=g+1;
        }
        else{
            r=g-1;
        }
    }
    cout<<kq;

}
