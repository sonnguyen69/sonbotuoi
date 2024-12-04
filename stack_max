#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    stack<int> st;
    stack<int> maxt;
    int maxx=INT_MIN;
    while (n--)
    {
        int t; cin>>t;
        if (t==1)
        {
            long long x; cin>>x;
            st.push(x);
            if (maxt.empty()||x>=maxt.top())
            {
                maxt.push(x);
            }
        }
        if (t==2)
        {
           if (!st.empty())
            if (st.top()==maxt.top())
            {
                maxt.pop();
            }
           st.pop();
        }
        if (t==3) cout<<maxt.top()<<'\n';
    }
}
