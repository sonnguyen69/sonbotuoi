#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll trvi=a[(n+2-1)/2];
    ll t=0;
    for(ll i=1;i<=n;i++)
    {
        t+=abs(trvi-a[i]);
    }
    cout<<t;
}
