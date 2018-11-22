#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[202][202];
struct Node
{
	int city;
	int d;
} road[202];

bool cmp(Node a, Node b)
{
	return a.d < b.d || (a.d == b.d && a.city < b.city);
}
int main()
{
	int N, M, num,c1,c2,dis,i,j,k;
	while (cin >> N, N)
	{
		cin >> M;
		for ( i = 0; i < N; i++)
		for ( j = 0; j < N; j++)
		{
			a[i][j] = 10000;
			if (i == j)
				a[i][j] = 0;
		}
		while(M--)
		{
			cin >> c1 >> c2 >> dis;
			a[c1][c2] = a[c2][c1]= dis;
		}
		cin >> num;
		for ( k = 0; k < N; k++)
			for ( i = 0; i < N; i++)
				for ( j = 0; j < N; j++)
				{
					if (a[i][k] + a[k][j] < a[i][j])
					{
						a[i][j] = a[i][k] + a[k][j];
						a[j][i] = a[i][j];
					}
				}

	for ( i = 1; i < N; i++)
		road[i - 1].city = i, road[i - 1].d = a[0][i];
	sort(road, road + (N - 1), cmp);
	cout << road[num - 1].city << endl;
	}
	return 0;
}
