#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
bool mark[1001][1001];
bool hill;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int n,m;
void bfs(int i,int j)
{
    mark[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty())
    {
        pair<int,int>top=q.front();
        q.pop();
        for(int k=0;k<8;k++)
        {
            int i1=top.first+dx[k];
            int j1=top.second+dy[k];
            if(i1>=1 && i1<=n && j1>=1 && j1<=m)
            {
                if(hill && a[i1][j1]>a[i][j])
                {
                    hill=0;
                }
                if(a[i1][j1]==a[i][j] && !mark[i1][j1])
                {
                    q.push({i1,j1});
                    mark[i1][j1]=1;
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>a[i][j];
            mark[i][j]=0;
        }
    }
    int dem=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(!mark[i][j])
            {
                hill=1;
                bfs(i,j);
                if(hill)    dem++;
            }
        }
    }
    cout<<dem;
}
