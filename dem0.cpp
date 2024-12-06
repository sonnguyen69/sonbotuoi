#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n; cin>>n;
    long long dem=0,p=5,tam=p;
    while (tam<=n)
    {
        dem+=n/tam;
        tam*=p;
    }
    cout<<dem;
}

