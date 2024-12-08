#include<bits/stdc++.h>
using namespace std;
vector<int> dske[1000001];
vector<int> dske1[1000001];
bool mark[1000001];
bool mark1[1000001];
stack<int>st;
void dfs(int i)
{
    mark[i]=1;
    for(auto x:dske[i])
    {
        if(mark[x]==0)
        {
            dfs(x);
        }
    }
    st.push(i);
}
void dfs1(int i)
{
    mark1[i]=1;
    for(auto x:dske1[i])
    {
        if(mark1[x]==0)
        {
            dfs1(x);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(mark,0,sizeof(mark));
        memset(mark1,0,sizeof(mark1));
        for(int i=1;i<=1e6;i++)
        {
            dske[i].clear();
            dske1[i].clear();
        }
       int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            dske[u].push_back(v);
            dske1[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            if(mark[i]==0)
                dfs(i);
        }
        int dem=0;
        while(!st.empty())
        {
            int t=st.top();
            st.pop();
            if(mark1[t]==0)
            {
                dem++;
                dfs1(t);
            }
        }
        if(dem!=1)
            {
                cout<<"YES"<<endl;
            }
        else cout<<"NO"<<endl;
    }

}
