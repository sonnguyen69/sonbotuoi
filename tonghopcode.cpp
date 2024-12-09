//-------------Lí thuyết số-------------//
//1.Ước và bội
//Hợp số là số nhiều hơn hai ước
// Ước thực sự của một số là ước khác chính nó
//Kiểm tra số nguyên tố
bool snt(int n)
{
    if (n<2) return 0;
    for (int i=2;i<=sqrt(n);i++)
    {
        if (n%i==0) return 0;
    }
    return 1;
}
// Tổng ước
int tonguoc(int n)
{
    int tam=1+n;
    for (int i=2;i*i<=n;i++)
    {
        if (n%i==0) tam+=i+n/i;
    }
    if (floor(sqrt(n))==sqrt(n)) tam-=floor(sqrt(n));
    return tam;
}
// Số lượng ước
int sluoc(int n)
{
    int dem=2;
    for (int i=2;i*i<=n;i++)
    {
        if (n%i==0) dem+=2;
    }
    if (floor(sqrt(n))==sqrt(n)) dem--;
    return dem;
}
// thuasonguyento
void thuaso(int n)
{
    for (int i=2;i*i<=n;i++)
    {
        while (n%i==0)
        {
            cout<<i<<' ';
            n/=i;
        }
    }
    if (n>1) cout<<n;
}
//2.Số hoàn hảo
// Số có tổng các ước thực sự bằng chính nó là số hoàn hảo
// Tính chất:
// p là số nguyên tố
// 2^p - 1 là số nguyên tố
// --> 2^(p-1).(2^p - 1)
void shh(int n)
{
    long long tam=1;
    for (int i=2;i*i<=n;i++)
    {
        if (n%i==0) tam+=i+n/i;
    }
    if (floor(sqrt(n))==sqrt(n)) tam-=floor(sqrt(n));
    if (tam==n) cout<<1;
    else cout<<0;
}
//Sàng số hoàn hảo
long long a[33];
bool snt(int n)
{
    if (n<2) return 0;
    for (int i=2;i<=sqrt(n);i++)
    {
        if (n%i==0) return 0;
    }
    return 1;
}
void shh()
{
    int cnt=0;
    for (int p=2;p<=33;p++)
    {
        if (snt(p))
        {
            long long tmp=(long long)pow(2,p)-1;
            if (snt(tmp))
            {
                a[cnt]=(long long)pow(2,p-1)*(pow(2,p)-1);
                cnt++;
            }
        }

    }
}
//3.UCLN,BCNN,Nguyên tố cùng nhau
// Hai số nguyên tố cùng nhau khi UCLN=1;
// hai số nguyên liên tiếp thì là hai số nguyên tố cùng nhau
int gcd(int a,int b)
{
    if (a>b) swap(a,b);
    if (a==0) return b;
    else return gcd(a,b%a);
}
int lcm(int a,int b)
{
    if (a==b) return a;
    else return a*b/gcd(a,b);
}
//4.Số fibonacci
void fibonacci()
{
    f[1]=f[2]=1;
    for (int i=1;i<=n;i++)
{
    f[i]=f[i-1]+f[i-2];
    f[i]%=MOD;
}
}
//5.Sàng nguyên tố và biến thể
//sàng nguyên tố cơ bản
void sang()
{
    for (int i=1;i<=maxx;i++) p[i]=1;
    p[0]=p[1]=0;
    for (int i=2;i*i<=maxx;i++)
    {
        if (p[i])
        {
            for (int j=i*i;j<=maxx;j+=i)
                p[j]=0;
        }
    }
}
//sàng nguyên tố sử dụng bitset
bitset<200000001> p;
vector<int> v;
void sangbitset()
{
    p[0]=p[1]=1;
    for (int i=2; i*i<=200000000; i++)
        if (p[i]==0)
        {
            int j=i*i;
            while (j<=200000000)
            {
                p[j]=1; j=j+i;
            }
        }
}
//sàng nguyên tố trên đoạn
void sang(long long l,long long r)
{
    for (long long i=l;i<=r;i++)
    {
        if (i<2) p[i-l]=0;
        else p[i-l]=1;
    }
    for (long long i=2;i<=sqrt(r);i++)
    {
        for (int j=max(i*i,(l+i-1)/i*i);j<=r;j+=i)
            p[j-l]=0;
    }
    for (int i=l;i<=r;i++) if (p[i-l]==1) tam++;
}
// Sàng đoạn bitset
    sangbitset();
    v.push_back(2);
    for (int i=3;i<=maxx;i+=2)
    {
        if (p[i]==1) v.push_back(i);
    }
    cout<<upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l);
// sàng ước nguyên tố
long long p[maxx];
void sang()
{
    for (int i=1;i<=maxx;i++) p[i]=i;
    for (int i=2;i<=sqrt(maxx);i++)
    {
        if (p[i]==i)
        {
            for (int j=i*i;j<=maxx;j+=i)
            {
                if (p[j]==j) p[j]=i;
            }
        }
    }
}
// sàng số lượng ước
long long p[maxx];
void sang()
{
    for (int i=1;i<=maxx;i++) p[i]=1;
    p[1]=0;
    for (int i=2;i<=maxx;i++)
    {
        for (int j=i*2;j<=maxx;j+=i)
        {
            p[j]++;
        }
    }
    cout<<p[n]+1;
}
// sàng số lượng ước
long long p[maxx];
void sang()
{
    for (int i=1;i<=maxx;i++) p[i]=1;
    p[1]=0;
    for (int i=2;i<=maxx;i++)
    {
        for (int j=i*2;j<=maxx;j+=i)
            p[j]+=i;
    }
    cout<<p[n]+n;
}
//6.Số bạn bè
// Số bạn bè nếu tổng các ước thực sự của số này bằng số kia
//7.Phi hàm euler
// là số lượng số nguyên tố cùng nhau với n không vượt qua n. phi(n)
// Tập hợp các số nguyên tố của n là (p1,p2,...,pk)
// phi(n)=n*(1-1/p1)*(1-1/p2)*...*(1-1/pk)
// VD: 60=5.3.2^3 --> phi(60)=16
//code cơ bản
long long p[maxx];
int euler(int n)
{
    if (n==0) return 0;
    int tam=n;
    for (int i=2;i*i<=n;i++)
    {
        if (n%i==0)
        {
            tam-=tam/i;
            while (n%i==0) n/=i;
        }
    }
    if (n>1) tam-=tam/n;
    return tam;
}
// code phi hàm euler
void sangphi()
{
    for (int i=1;i<=maxx;i++) p[i]=i;
    for (int i=2;i<=maxx;i++)
    {
        if (p[i]==i)
        {
            p[i]=i-1;
            for (int j=i*2;j<=maxx;j+=i)
            {
                p[j]=p[j]-p[j]/i;
            }
        }
    }
}
//8.Cấp số cộng, cấp số nhân
//9.Giải thuật euclid mở rộng
// ax+by=gcd(a,b)
void ext(long long a,long long b)
{
    if (b==0)
    {
        x=1;
        y=0;
        g=a;
    }
    else
    {
        ext(b,a%b);
        long long x1=x,y1=y;
        x=y1;
        y=x1-a/b*y1;
    }
}
//10.Nghịch đảo modulo
long long modulo(long long b,long long m)
{
    ext(b,m);
    if (g!=1) return 0;
    long long x1=x;
    return (x1%m+m)%m;
}
long long b1=modulo(b,m);
long long kq=(a*b1)%m;
//11.Lí thuyết đồng dư
// (a+b)%m= (a%m+b%m)%m
// (a-b)%m= (a%m-b%m+m)%m
// (a*b)%m= (a%m*b%m)%m
//12.Nhân ấn độ, luỹ thừa nhị phân
//Nhân ấn độ
// a*b = a*b/2+a*b/2 (b chẵn)
// a*b = a*b/2+a*b/2+a (b lẻ)
//Luỹ thừa nhị phân
// a^b = a^b/2*a^b/2 (b chẵn)
// a^b = a^b/2*a^b/2*a (b lẻ)
#include<bits/stdc++.h>
using namespace std;
#define maxx 1000005
long long nhanad(long long a,long long b,long long m)
{
    if (b==0) return 0;
    if (b==1) return a%m;
    long long k=nhanad(a,b/2,m);
    k+=k;
    k%=m;
    if (b%2==0) return k;
    else return (k+a)%m;
}
long long luythua(long long a,long long b,long long m)
{
    if (b==0) return 1;
    if (b==1) return a%m;
    long long k=luythua(a,b/2,m)%m;
    k*=k;
    k%=m;
    if (b%2==0) return k%m;
    else return (k*(a%m))%m;
}
//13.Hoán vị, tổ hợp,chỉnh hợp
// Hoán vị
void hoanvi()
{
    long long s=1;
    for (int i=1;i<=maxx;i++)
    {
        s*=i;
        s%=mod;
        a[i]=s;
    }
}
void chinhhop(int n)
{
    long long s=1;
    for (int i=n;i>=1;i--)
    {
        s*=i;
        s%=mod;
        a[i]=s;
    }
    cout<<a[k];
}
void tohop1()
{
    for (int i=0;i<=1000;i++)
    {
        a[0][i]=1;
        a[i][i]=1;
    }
    for (int j=1;j<=1000;j++)
    {
        for (int i=1;i<j;i++)
        {
            a[i][j]=a[i-1][j-1]+a[i][j-1];
        }
    }
    cout<<a[k][n];
}
void tinh()
{
    long long n,k,s=1;
    for (int i=1;i<=k;i++)
    {
        s*=modulo(i,mod);
        s%=mod;
        s*=(n-k+i);
        s%=mod;
    }
}
//14.Công thức legendre
// Tìm k lớn nhất :n! % p^k (p là số nguyên tố)
void solve()
{
    int n,p; cin>>n>>p;
    int res=0;
    while (n>0)
    {
        res+=(n/p);
        n/=p;
    }
    cout<<res;
}
//15.Dãy catalan
//(2n)!/((n+1)!*n!)
// 1 1 2 5 14 42 132
long long a[33];
void catalan()
{
    a[0]=a[1]=1;
    for (int i=2;i<=33;i++)
    {
        a[i]=0;
        for (int j=0;j<i;j++)
        {
            a[i]+=a[j]*a[i-j-1];
        }
    }
}
//16.Định lí fermat nhỏ
//p là số nguyên tố thì mọi a: a^p - a là bội số nguyên của p
//vd: a=3,p=5 --> 3^5 - 5= 240 % 5 =0
//nếu a chia hết p --> a^(p-1) - 1 chia hết cho p
//vd: a=4, p=5 --> 4^4 - 1 = 256 - 1 =255 chia hết 5
long long fermat(long long a,long long p)
{
    if (p<=1) return 1;
    if (a%p==0) return 0;
    return luythua(a,p-1,p);
}
//-------------Xử lí mảng-------------//
//1.Xử lí xâu
// cin.ignore();
// getline(cin,s)
// s.size()
// s.substr(x,y): trích chuỗi độ dài là y từ vị trí x
// abcdefgh --> s.substr(2,3) --> cde
// s.find(r) . xâu r có trong s hay không
// stringsteam
//stringstream ss(s);
//while (ss>>s) cout<<s<<' ';
//isalpha() isdigit()
//'A': 65
//'a': 97
//từ hoa sang thường  s[i]+('a'-'A')
//từ thường sang hoa  s[i]-('a'-'A')
//bảng chữ cái: 26
//s[i]-'0'
//cho xâu s có độ dài n và xâu t có độ dài m. Đếm số lần s xuất hiện t
//vd: s="ab"
//    t="aabcabaab" --> 3 lần
//2.Mảng cộng dồn, mảng hiệu
Mảng cộng dồn của mảng hai chiều
for (int i=1;i<=n;i++)
{
    for (int j=1;j<=m;j++)
    {
        p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
    }
}
x1,y1,x2,y2  p[x2][y2]-p[x1-1][y2]-p[x2][y1-1]+p[x1-1][y1-1]
//3.Mảng đánh dấu
// Kiểm tra sự xuất hiện
// Tần suất
// Tìm kiếm
// Lọc dữ liệu
// Quản lí trạng thái
//4.Hai con trỏ
// Tìm cặp phần tử có tổng bằng k
// Kiểm tra chuỗi,mảng có đối xứng
// Tìm khoảng cách min,max giữa hai phần tử thoả mãn
//5.Cửa sổ trượt
// Liên tiếp k phần tử
for (int i=1;i<=k;i++) ... sum+=a[i];
for (int i=k;i<=n;i++)
{
    sum+=a[i]-a[i-k+1];
}
//6.Thuật toán sinh
//7.Quay lui,vét cạn,nhánh cận,tham lam
//8.Tìm kiếm nhị phân
// (x+y-1)/y
// (m-a+b-1)/y
