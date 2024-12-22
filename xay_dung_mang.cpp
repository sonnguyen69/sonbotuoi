#include<bits/stdc++.h>
using namespace std;
int a[100001], b[100001];
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    stack<int> st;
    st.push(n);

    for (int i = n - 1; i >= 1; i--) {
        if (st.empty()) st.push(i);
        while (!st.empty() && a[i] <= a[st.top()]) {
            b[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        b[st.top()] = 0;
        st.pop();
    }
    for (int i = 1; i <= n; i++) cout << b[i] << ' ';
}
