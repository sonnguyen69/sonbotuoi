#include <iostream>
using namespace std;
// ý tưởng là loang từ bên ngoài vào để tìm kiếm thành phân liên thông khi mà loang từ độ cao 0 -> hmax.
int n, m;
int seawater[102][102];
int Hmax=0;
void read ()
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			cin>>seawater[i][j];
			if (seawater[i][j]>Hmax) Hmax=seawater[i][j];
		}
	}
}

int check[102][102];
int check_connect[102][102];
void init ()
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			check[i][j]=0;
			check_connect[i][j]=0;
		}
	}
}

int extra;
int x_ar[]={+1, +0, -1, +0};
int y_ar[]={+0, -1, +0, +1};
void loang (int i, int j)
{
	check[i][j]=1;
	for (int k=0; k<4; k++)
	{
		int X=j+x_ar[k];
		int Y=i+y_ar[k];
		if (X>=1 && X<=m && Y>=1 && Y<=n)
		{
			if (check[Y][X]==0 && seawater[Y][X]<=extra) loang (Y, X);
		}
	}
}

void DFS (int i, int j)
{
	check_connect[i][j]=1;
	for (int k=0; k<4; k++)
	{
		int X=j+x_ar[k];
		int Y=i+y_ar[k];
		if (X>=1 && X<=m && Y>=1 && Y<=n)
		{
			if (check_connect[Y][X]==0 && check[Y][X]==check[i][j]) DFS (Y, X);
		}
	}
}

int main ()
{
	int t=0;
	while (1)
	{
		cin>>n>>m;
		if (n==0 && m==0) break;
		t++;
		read ();
		int kt=0;
		for (int k=0; k<=Hmax; k++)
		{
			extra=k;
			init ();
			for (int i=1; i<=n; i++)
			{
				for (int j=1; j<=m; j++)
				{
					if ((i==1 || i==n || j==1 || j==m) && seawater[i][j]<=k && check[i][j]==0) loang (i, j);
				}
			}
			//dem lien thong?
			int count_connect=0;
			for (int i=1; i<=n; i++)
			{
				for (int j=1; j<=m; j++)
				{
					if (check_connect[i][j]==0 && check[i][j]==0)
					{
						count_connect++;
						DFS (i, j);
					}
				}
			}
			if (count_connect>1)
			{
				kt=1;
				break;
			}
		}
		if (kt==1) cout<<"Case "<<t<<": Island splits when ocean rises "<<extra<<" feet."<<endl;
		else cout<<"Case "<<t<<": Island never splits."<<endl;
	}
	return 0;
}
