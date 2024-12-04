#include<bits/stdc++.h>
using namespace std;
vector<int> vv[1007];
bool marked[1007];
bool mark[1007];
void ms()
{
    memset(marked, 0, sizeof(marked));
    memset(mark, 0, sizeof(mark));
}
void dfs(int i)
{
    marked[i]=1;
    mark[i]=1;
    for (auto x:vv[i])
    {
        if (!marked[x]) dfs(x);
    }
}
int main()
{
    ms();
    int n, m;
    cin>>n>>m;
    int res=n;
    while(m--)
    {
        int u, v;
        cin>>u>>v;
        vv[u].push_back(v);
        vv[v].push_back(u);
    }
    dfs(1);
    bool kt=1;
    for (int i=1; i<=n; i++)
    {
        if(!mark[i])
        {
            cout<<i<<"\n";
            kt=0;
        }
    }
    if(kt==1)
    {
        cout<<0;
    }


}

