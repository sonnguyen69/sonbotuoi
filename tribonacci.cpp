#include<bits/stdc++.h>
using namespace std;
using i64 = int64_t;
const i64 MOD = 1e15 + 7;
//global var here
struct matrix {
    i64 a[4][4];
} a, b;
int t, n;

i64 multiply(i64 a, i64 b) {
    i64 c = 0;
    while (b) {
        if (b & 1) {
            c += a;
            if (c >= MOD) c -= MOD;
        }
        a += a;
        if (a >= MOD) a -= MOD;
        b /= 2;
    }
    return c;
}

matrix operator * (matrix a, matrix b) {
    matrix c;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            c.a[i][j] = 0;
            for (int k = 0; k < 4; k++)
                c.a[i][j] = (c.a[i][j] + multiply(a.a[i][k], b.a[k][j])) % MOD;
        }
    return c;
}

matrix power_of_a(int p) {
    if (p == 1) return a;
    matrix x = power_of_a(p / 2);
    x = x * x;
    if (p & 1) x = x * a;
    return x;
}
//--------------------------------------------
//smol func here

//--------------------------------------------
//main func here
main() {
    //ඞ fastio
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //var here
    a.a[0][0] =
        a.a[0][1] =
        a.a[1][1] =
        a.a[1][2] =
        a.a[1][3] =
        a.a[2][1] =
        a.a[3][2] = 1;

    i64 F[5], T[5];
    F[1] = 1;
    F[2] = 3;
    F[3] = 6;
    T[1] = 1;
    T[2] = 2;
    T[3] = 3;

    int t, n;
    //----------------------------------------
    //logic here
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 3) cout << F[n] << '\n';
        else {
            b = power_of_a(n - 2);
            cout << (F[2] * b.a[0][0] + T[3] * b.a[0][1] + T[2] * b.a[0][2] + T[1] * b.a[0][3]) % MOD << '\n';
        }
    }

    //----------------------------------------
    //return 0;
}
//--------------------------------------------