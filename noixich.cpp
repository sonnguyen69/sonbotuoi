#include<bits/stdc++.h>
using namespace std;
int a[200001], i, n, tgian=0;
int main()
{
   cin>>n;
   for (i=1; i<=n; i++)
        cin>>a[i];
    sort (a+1, a+n+1);
    i=1;
   while (n>1)
   {
       a[i]--;
       n--;
       tgian++;

           if (a[i]==0)
           {n--;
            i++;

           }


   }
   cout<<tgian;
}

