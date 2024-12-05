#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h,w;
    int a[501][501];
    int s[501][501]={};
    cin>>h>>w;
    int i,j;
    for( i=1;i<=h;i++)
    {
        for(j=1;j<=w;j++)
        {
            cin>>a[i][j];
            s[i][j]=s[i-1][j]+s[i][j-1]+a[i][j]-s[i-1][j-1];
        }
    }
    ll maxx=INT_MIN;
    ll sum,minn;
    int k;
    for(i=1;i<=h;i++)
    {
        for(j=i;j<=h;j++)
        {
            minn=0;
            sum=0;
            for(k=1;k<=w;k++)
            {
                sum+=s[j][k]-s[i-1][k]-s[j][k-1]+s[i-1][k-1];
                if(sum-minn>maxx)
                {
                    maxx=sum-minn;
                }
                if(sum<=minn)
                {
                    minn=sum;
                }
            }
        }
    }
    cout<<maxx;
}
