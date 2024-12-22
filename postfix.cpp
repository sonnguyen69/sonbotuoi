#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<int> st;
    for (string s; getline(cin, s);) {
        int dem = 0, p1, p2;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') i++;
            else if (isdigit(s[i])) {
                int tam = 0;
                while (i < s.size() && isdigit(s[i])) {
                    tam = tam * 10 + (s[i] - '0');
                    i++;
                }
                st.push(tam);
                i++;
            } else {
                p2 = st.top();
                st.pop();
                p1 = st.top();
                st.pop();
                if (s[i] == '+') dem = p1 + p2;
                if (s[i] == '-') dem = p1 - p2;
                if (s[i] == '*') dem = p1 * p2;
                if (s[i] == '/') dem = p1 / p2;
                st.push(dem);
                i++;
            }
        }
        cout << st.top() << '\n';
    }

}
