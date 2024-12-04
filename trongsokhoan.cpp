#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll>leftmax(n),rightmax(n),leftmin(n),rightmin(n);
    stack<ll> s;
    for (ll i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        if(s.empty())
        {
            leftmax[i]=-1;
        }
        else{
            leftmax[i]=s.top();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (ll i = n - 1; i >= 0; i--) {
        while (!s.empty() && a[s.top()] < a[i]) s.pop();
        if(s.empty())
        {
            rightmax[i]=n;
        }
        else{
            rightmax[i]=s.top();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (ll i = 0; i < n; i++)
    {
        while (!s.empty()&&a[s.top()]>=a[i]) s.pop();
        if(s.empty())
        {
            leftmin[i]=-1;
        }
        else{
            leftmin[i]=s.top();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (ll i = n - 1; i >= 0; i--) {
        while (!s.empty()&& a[s.top()]>a[i]) s.pop();
        if(s.empty())
        {
            rightmin[i]=n;
        }
        else{
            rightmin[i]=s.top();
        }
        s.push(i);
    }
    ll kq=0;
    for (ll i=0;i<n; i++) {
        ll x=(i - leftmax[i])*(rightmax[i] - i)*a[i];
        ll y=(i - leftmin[i])*(rightmin[i] - i)*a[i];
        kq +=x-y;
    }
    cout<<kq;
}
