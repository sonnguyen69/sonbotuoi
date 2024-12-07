#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    while(n--)
    {
        ll a;
        cin>>a;
        queue<ll> q;
        q.push(9);
        ll x = 0;
        ll y = 9;
        bool kt=1;
        while(kt)
        {
            q.push(q.front()*10 + x);
            q.push(q.front()*10 + y);
            if(q.front()%a==0)
            {
                cout<<q.front()<<"\n";
                kt=0;
            }
            q.pop();
        }
    }
}
