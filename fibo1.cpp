#include<bits/stdc++.h>
using namespace std;
long long f[100];
int main()
{
    int t; cin>>t;
    f[1]=f[2]=1;
    for (int i=3;i<=100;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    while (t--)
    {
        int n; cin>>n;
        cout<<f[n]<<'\n';
    }
}
