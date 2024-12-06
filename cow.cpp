#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
long long n;
bool check(long long a[],long long k,long long res)
{
    long long dem=1;
    long long j=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[j]>=res)
        {
            j=i;
            dem++;
        }
    }
    if(dem<k)
        return 0;
    return 1;
}
int main()
{
    long long k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    long long l=1;
    long long r=a[n]-a[1];
    long long res=0;
    while(l<=r)
    {
        long long g=(l+r)/2;
        if(check(a,k,g))
        {
            res=g;
            l=g+1;
        }
        else
            r=g-1;
    }
    cout<<res;
}
