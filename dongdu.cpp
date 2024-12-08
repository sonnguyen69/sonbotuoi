#include<bits/stdc++.h>
using namespace std;
#define MOD 5
long long tinh(string s,long long m)
{
    int tam=0;
    for (int i=0;i<s.size();i++) tam=(tam%10+s[i]-'0')%m;
    return tam;
}
int main()
{
    int t; cin>>t;
    while (t--)
    {
        string n; cin>>n;
        int c2[]={2,4,3,1};
        int c3[]={3,4,2,1};
        int c4[]={4,1};
        int m2=tinh(n,4);
        int m4=tinh(n,2);
        int kq=1;
        if (m2==0)
        {
            kq+=c2[3];
            kq+=c3[3];
        }
        else
        {
            kq+=c2[m2-1];
            kq+=c3[m2-1];
        }
        if (m4==0) kq+=c4[1];
        else kq+=c4[m4-1];
        kq%=5;
        cout<<kq<<'\n';
    }
}
