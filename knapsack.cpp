#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, s;
    cin>>n>>s;

    int w[n+7], v[n+7];
    for (int i=1; i<=n; i++)
    {
        cin>>w[i]>>v[i];
    }
    int dp[n+7][s+7];
    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=s; j++)
        {
                dp[i][j]=0;
        }
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=s; j++)
        {
            dp[i][j]=dp[i-1][j];
            if (j-w[i]>=0)
            {
                dp[i][j]=max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[n][s];
}
