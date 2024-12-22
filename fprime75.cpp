#include<bits/stdc++.h>
using namespace std;
using i64 = int64_t;
//global var here
bool prime[10000001];

//--------------------------------------------
//smol func here
void sieve() {
    int j;
    memset(prime, true, 10000001);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= 10000000; i++) {
        if (prime[i]) {
            j = i * i;
            while (j * i <= 10000000) {
                prime[j] = false;
                j += i;
            }
        }
    }
}

//--------------------------------------------
//main func here
main() {
    //ඞ fastio
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //var here
    int t, n;
    //----------------------------------------
    //logic here
    sieve();
    cin >> t;
    while (t--) {
        cin >> n;
        if (prime[n]) cout << "YES\n";
        else cout << "NO\n";
    }
    //----------------------------------------
    //return 0;
}
//--------------------------------------------