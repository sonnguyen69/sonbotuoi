/* tìm tổ hợp kế tiếp của mảng
vd1: 5 3
1 2 3
với n = 5, k = 3 có các tổ hợp(1 2 3), (1 2 4), (1 2 5), ...
tìm tổ hợp kế tiếp-- > (1, 2, 4)
vì người 3 không có trong tổ hợp kế tiếp-- > kq: 1
vd2 : 6 4
3 4 5 6
với n = 6, k = 4 thì(3, 4, 5, 6) là tổ hợp cuối cùng-- > cả 4 người đều được nghỉ-- > kq = 4
*/
#include<bits/stdc++.h>
using namespace std;
int a[40], b[40];
bool check(int n, int k) {
    for (int i = k - 1; i >= 0; i--) {
        if (b[i] < n - k + i + 1) {
            b[i]++;
            for (int j = i + 1; j < k; j++)
                b[j] = b[j - 1] + 1;
            return 1;
        }
    }
    return 0;
} // kiểm tra có tồn tại tổ hợp kế tiếp không. 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        if (check(n, k)) {
            set<int> s1(a, a + k);
            set<int> s2(b, b + k);
            int dem = 0;
            for (int x : s1) {
                if (s2.find(x) == s2.end()) {
                    dem++;
                }
            }
            cout << dem << endl;
        } else {
            cout << k << endl;
        }
    }
}
