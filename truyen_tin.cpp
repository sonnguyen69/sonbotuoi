#include<bits/stdc++.h>
using namespace std;
vector<int> dske[100007], dske1[100007];
vector<bool> mark(100007, 0);
vector<bool> mark1(100007, 0);
int visited[100007];
stack<int> st;
int tplt[100007];
int cnt=0;
void dfs(int i)
{
    mark[i]=1;

    for (int x: dske[i])
    {
        if(!mark[x]) dfs(x);
    }
    st.push(i);
}
void dfs1(int i)
{
    mark1[i]=1;
    tplt[i]=cnt;
    for (int x: dske1[i])
    {
        if(!mark1[x]) dfs1(x);
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        dske[a].push_back(b);
        dske1[b].push_back(a);
    }
    for (int i=1; i<=n; i++)
    {
        if(!mark[i]) dfs(i);
    }
    while(!st.empty())
    {
        int x=st.top();
        if(!mark1[x])
        {
            cnt++;
            dfs1(x);
        }
        st.pop();
    }
    bool kt[cnt+7];
    memset(kt, 0, sizeof(kt));
    for(int i=1; i<=n; i++)
    {
        for (auto j: dske[i])
        {
            if(tplt[i] != tplt[j] && !kt[tplt[j]])
            {
                    cnt--;
                    kt[tplt[j]] = 1;
            }
        }
    }
    cout<<cnt;

}
