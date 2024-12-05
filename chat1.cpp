#include<bits/stdc++.h>
#define ll long long
#define MAXN 1000007
using namespace std;
ll a[MAXN];
ll n, t;
void create()
{
    for (ll i=1; i<=n; i++)
    {
        a[i]=i*i+1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>t;
    create();
    while(t--)
    {
        ll x;
        cin>>x;
        ll *k=lower_bound(a+1, a+n+1, x);
        cout<<*k<<"\n";

    }
}
