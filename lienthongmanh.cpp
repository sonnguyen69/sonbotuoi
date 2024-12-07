#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
bool mrk[100001];
vector<int> dske[100001], rdske[100001];
stack<int> st;
void rdfs(int i){
    mrk[i]=1;
    for (int j: rdske[i])
        if (!mrk[j]) rdfs(j);
    st.push(i);
}
void dfs(int i){
    mrk[i]=1;
    for (int j: dske[i])
        if (!mrk[j]) dfs(j);
}
int main(){
    cin>>n>>m;
    while (m--){
        cin>>a>>b;
        dske[a].push_back(b);
        rdske[b].push_back(a);
    }
    for (int i=1; i<=n; i++) mrk[i]=0;
    for (int i=1; i<=n; i++){
        if (!mrk[i])
            rdfs(i);
    }
    for (int i=1; i<=n; i++) mrk[i]=0;
    bool kt=1;
    a=st.top(); dfs(a); st.pop();
    while (!st.empty()){
        b=st.top();
        if (!mrk[b]){
            kt=0; break;
        }
        st.pop();
    }
    if (!kt) cout<<"NO\n"<<a<<' '<<b;
    else cout<<"YES";
}
