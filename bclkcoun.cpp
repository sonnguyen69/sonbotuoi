#include<bits/stdc++.h>
using namespace std;
bool mark[101][101];
char a[101][101];
int n,m;
bool check(int x,int y)
{
    if(x<1||x>n||y<1||y>m) return 0;
    if(a[x][y]=='.') return 0;
    return 1;
}
int d[8]={-1,1,0,0,1,-1,1,-1};
int f[8]={0,0,1,-1,1,-1,-1,1};
void dfs(int x,int y)
{
    mark[x][y]=1;
    cout<<x<<' '<<y<<' ';
    for(int i=0;i<8;i++)
    {
        int x1=x+d[i];
        int y1=y+f[i];
        if(check(x1,y1)==1&&mark[x1][y1]!=1) dfs(x1,y1);
    }
}
int main()
{
    int dem=0;
     cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            mark[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mark[i][j]==0&&a[i][j]!='.')
            {
              dfs(i,j);
              cout<<endl;
              dem++;
            }
        }
    }
    cout<<dem;
}
