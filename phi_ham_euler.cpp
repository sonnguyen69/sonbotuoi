#include<bits/stdc++.h>
using namespace std;
#define faster ios::sync_with_stdio(0); cin.tie(0);
const int M = 1e6;
int p[M];
void sangphi()
{
    for (int i=1;i<=M;i++) p[i]=i;
    for (int i=2;i<=M;i++)
    {
        if (p[i]==i)
        {
            p[i]=i-1;
            for (int j=i*2;j<=M;j+=i)
            {
                p[j]=p[j]-p[j]/i;
            }
        }
    }
}
int main()
{
    faster
    sangphi();
    int t; cin>>t;
    while (t--)
    {
        int x; cin>>x;
        cout<<p[x]<<'\n';
    }
}
