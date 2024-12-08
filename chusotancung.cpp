#include<bits/stdc++.h>
using namespace std;
long long luythua(long long a,long long b)
{
    if (b==0) return 1;
    if (b==1) return a%10;
    long long k=luythua(a,b/2);
    k*=k;
    k%=10;
    if (b&1) return (k*(a%10))%10;
    else return k%10;
}
int main()
{
      string a,b; cin>>a>>b;
    long long s=0;
    for (int i=0;i<a.size();i++)
    {
        s=(s*10+a[i]-'0')%10;
    }
    long long tam=1,t=s;
    for (int i=b.size()-1;i>=0;i--)
    {
        tam=tam*luythua(t,b[i]-'0')%10;
        t=luythua(t,10);
    }
    cout<<tam;

}
