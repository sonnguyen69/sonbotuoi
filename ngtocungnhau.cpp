#include<bits/stdc++.h>
#define gh 1000000
using namespace std;
int n,m;
int a[gh+1];
bool mrk[gh+1], p[gh+1];
set<int> pr;
void sieve(int m){
    p[0]=p[1]=0;
    int i;
    for (i=2; i<=m; i++) p[i]=1;
    for (i=2; i*i<=m; i++)
        if (p[i]){
            pr.insert(i);
            for (int j=i*i; j<=m; j+=i)
                if (p[j]) p[j]=0;
        }
    while (i<=m){
        if (p[i]) pr.insert(i);
        i++;
    }
}
set<int> ptich(int x){
    set<int> se;
    for (int i: pr){
        if (i*i>x) break;
        if (x%i==0) se.insert(i);
        while (x%i==0) x/=i;
    }
    if (x>1) se.insert(x);
    return se;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); //cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>a[i];
    sieve(m);
    set<int> se;
    for (int i=1; i<=n; i++){
        set<int> s=ptich(a[i]);
        for (int i: s) se.insert(i);
    }
    for (int i=1; i<=m; i++) mrk[i]=1;
    for (int i: se){
        if (i>m) break;
        for (int j=i; j<=m; j+=i)
            if (mrk[j]) mrk[j]=0;
    }
    vector<int> res;
    for (int i=1; i<=m; i++){
        if (mrk[i]) res.push_back(i);
    }
    cout<<res.size()<<"\n";
    for (int i: res) cout<<i<<"\n";
}
