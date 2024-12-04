#include<bits/stdc++.h>
using namespace std;
int eulerPhi(int n) {
    if (n == 0) return 0;
    int ans = n;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            ans -= ans / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        int t;
        cin>>t;
        cout<<eulerPhi(t)<<"\n";
    }
}
