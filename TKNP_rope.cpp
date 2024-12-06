#include<bits/stdc++.h>
using namespace std;
long long a[100001],n,k;
bool check(long long m)
{
    long long tam=0;
    for (int i=1;i<=n;i++)
    {
        tam+=a[i]/m;
        if (tam>=k) return 1;
    }
    return 0;
}
int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    long long l=1,r=*max_element(a+1,a+n+1);
    long long kq=0;
    while (l<=r)
    {
        long long m=(l+r)/2;
        if (check(m))
        {
            kq=m;
            l=m+1;
        }
        else r=m-1;
    }
    cout<<kq;

}
