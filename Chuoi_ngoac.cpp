#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool comma(char c)
{
    if (c=='{' || c=='[' || c=='(')
            return 1;
    else return 0;
}
bool check(char a, char b)
{
    if (a=='{' && b=='}') return 1;
    else if (a=='[' && b==']') return 1;
    else if (a=='(' && b==')') return 1;
    else return 0;

}
bool ktr(string s)
{
    stack<char> st;
    for (int i=0;i<s.size();i++)
    {
        if (comma(s[i]))
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return 0;
                break;
            }
            else if (check(st.top(),s[i]))
            {
                st.pop();
            }
        }
    }
    if (st.empty()) return 1;
    else return 0;
}
int main()
{
    int n; cin>>n;
    while (n--)
    {
        string s; cin>>s;
        if (ktr(s)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }


}
