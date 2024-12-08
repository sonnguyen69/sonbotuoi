#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
void matran(long long f[2][2],long long m[2][2])
{
    long long x=(f[0][0]*m[0][0]+f[0][1]*m[1][0])%MOD;
    long long y=(f[0][0]*m[0][1]+f[0][1]*m[1][1])%MOD;
    long long a=(f[1][0]*m[0][0]+f[1][1]*m[1][0])%MOD;
    long long b=(f[1][0]*m[0][1]+f[1][1]*m[1][1])%MOD;
    f[0][0]=x;
    f[0][1]=y;
    f[1][0]=a;
    f[1][1]=b;
}
void luythuamt(long long f[2][2],long long n)
{
    if (n==0||n==1) return;
    long long m[2][2]={{1,1},{1,0}};
    luythuamt(f,n/2);
    matran(f,f);
    if (n%2!=0) matran(f,m);
}
long long fibo(long long n)
{
    if (n==0) return 0;
    long long f[2][2]={{1,1},{1,0}};
    luythuamt(f,n-1);
    return f[0][0];
}
int main()
{
    int t;cin>>t;
    while (t--)
    {
        long long x; cin>>x;
        cout<<fibo(x)<<'\n';
    }
}
