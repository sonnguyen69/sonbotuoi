#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
   {
     stack<int> st;
     int n; cin>>n;
     int a[n+1],maxR[n+1];
     for(int i=1;i<=n;i++) cin>>a[i];
     for(int i=n;i>=1;i--)
    {
        while(!st.empty()&&a[st.top()]<=a[i]) st.pop();
        if(st.empty()) maxR[i]=-1;
        else maxR[i]=a[st.top()];
        st.push(i);
    }
    for(int i=1;i<=n;i++) cout<<maxR[i]<<' ';
    cout<<endl;
}
}
