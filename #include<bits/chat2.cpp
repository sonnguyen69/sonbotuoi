#include<bits/stdc++.h>
#define ll long long
#define MAXN 1000007
using namespace std;
ll a[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    ll t;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        if(binary_search(a+1, a+n+1, x))
        {
            cout<<"Y"<<"\n";
        }
        else cout<<"N"<<"\n";
    }
}
