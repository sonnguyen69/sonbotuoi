#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin>>q;
    while(q--)
    {
        ll n;
        cin>>n;
        queue<string>q;
        q.push("9");
        while(!q.empty())
        {
            string x=q.front();
            q.pop();
            ll x1=stoll(x);
            if(x1%n==0)
            {
                cout<<x<<"\n";
                break;
            }
            q.push(x+"0");
            q.push(x+"9");
        }
    }
}
