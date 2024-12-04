#include<bits/stdc++.h>
using namespace std;
char a[107][107];
bool mark[107][107];
int dx[10], dy[10];
int n, m;
void abc()
{
    dx[1]=-1;
    dx[2]=-1;
    dx[3]=0;
    dx[4]=1;
    dx[5]=1;
    dx[6]=1;
    dx[7]=0;
    dx[8]=-1;
    dy[1]=0;
    dy[2]=1;
    dy[3]=1;
    dy[4]=1;
    dy[5]=0;
    dy[6]=-1;
    dy[7]=-1;
    dy[8]=-1;
}
void dfs(int i, int j)
{
    mark[i][j]=1;
    for (int k=1; k<=8; k++)
    {
        int i1=i+dx[k];
        int j1=j+dy[k];
        if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]=='W' && mark[i1][j1]==0)
        {
            dfs(i1, j1);
        }
    }
}
int main()
{
    abc();
    memset(mark, 0, sizeof(mark));
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            cin>>a[i][j];
        }
    }
    int dem=0;
   for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
           if(a[i][j]=='W' && mark[i][j]==0)
           {
               dfs(i, j);
               dem++;
           }
        }
    }
    cout<<dem;
}
