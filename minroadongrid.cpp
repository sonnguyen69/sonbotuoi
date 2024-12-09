#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
bool mark[1001][1001];
int n,m;
int dx[4]={0,-1,1,0};
int dy[4]={1,0,0,-1};
struct matrix
{
    int x,y,cnt;
};
bool check(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 1);
}
void dfs(int x1,int y1,int x2, int y2)
{
   queue<matrix> q;
   q.push({x1,y1,0});
   mark[x1][y1]=1;
   while(!q.empty())
   {
       matrix matrixs=q.front();
//       if(matrixs.x==x2&&matrixs.y==y2)
//       {
//           cout<<matrixs.cnt;
//           return ;
//       }
       cout<<matrixs.x<<' '<<matrixs.y;
       cout<<endl;
       q.pop();
       for(int i=0;i<4;i++)
        {
          int nx1=matrixs.x+dx[i];
          int ny1=matrixs.y+dy[i];
          if(check(nx1,ny1)&&!mark[nx1][ny1])
          {
              mark[nx1][ny1]=1;
              q.push({nx1,ny1,matrixs.cnt+1});
          }

        }
   }
   cout<<-1;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    int x1,x2,y1,y2;
   cin>>x1>>y1;
   cin>>x2>>y2;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
           cin>>a[i][j];
           mark[i][j]=0;
       }
   }
   dfs(x1+1,y1+1,x2+1,y2+1);
}
