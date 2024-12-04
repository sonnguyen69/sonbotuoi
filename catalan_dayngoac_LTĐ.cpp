#include<bits/stdc++.h>
using namespace std;
int a[31];
int main()
{
    int n; cin>>n;
    n/=2;
    a[0]=a[1]=1;
    for (int i=2;i<=30;i++)
    {
        a[i]=0;
        for (int j=0;j<i;j++)
            a[i]+=a[j]*a[i-j-1];
    }
    cout<<a[n];
}
