#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while (t--)
    {
        long long n,p=5,res=0,tam=p;
        cin>>n;
        while (tam<=n)
        {
            res+=n/tam;
            tam*=p;
        }
        cout<<res<<'\n';
    }
}
