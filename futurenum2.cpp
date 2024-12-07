#include<bits/stdc++.h>
#define gh 20000000
using namespace std;
int cnt=0,n;
int a[1000001];
vector<bool> p(gh+1,1), fn(gh+1,0);
vector<int> pr;
void sieve(){
    p[0]=p[1]=0;
    for (int i=2; i*i<=gh; i++)
        if (p[i]){
            pr.push_back(i);
            for (int j=i*i; j<=gh; j+=i)
                if (p[j]) p[j]=0;
        }
    for (int i: pr)
        for (int j=i; j<=gh; j+=i)
            if (p[j/i]) fn[j]=1;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++)
        if (fn[a[i]]) cnt++;
    cout<<cnt;
}
