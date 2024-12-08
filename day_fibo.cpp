#include<bits/stdc++.h>
using namespace std;
long long f[100];
void fibonacci()
{
    f[1]=f[2]=1;
    for (int i=3;i<=100;i++) f[i]=f[i-1]+f[i-2];
}
// tính độ dài xâu theo công thức fibonacci
// f[g(1)]= 1 ('A'); f[g(2)]= 1 ('B')
char find_fibo(long long n,long long i)
{
    if (n==1) return 'A';
    if (n==2) return 'B';
    if (i<=f[n-2]) return find_fibo(n-2,i);
    else return find_fibo(n-1,i-f[n-2]);
}
// Xác định vị trí thứ i trong xâu
int main()
{
    fibonacci();
    int t; cin>>t;
    while (t--)
    {
        long long n,i; cin>>n>>i;
        cout<<find_fibo(n,i)<<'\n';
    }
}
/*
VD: 6 4
tìm vị trí thứ 4 trong xâu fibonacci thứ 6
Xâu fibo thứ 1: A
-------------2: B
-------------3: AB
-------------4: BAB
-------------5: ABBAB
-------------6: BABABBAB
vị trí thứ 4 trong xâu fibonacci thứ 6: A
*/
