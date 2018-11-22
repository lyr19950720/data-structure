/*#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int map[10002][10002];
double sum=0;
int n;
int SUM(int v)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(map[i][j]!=0)
            {
                sum=sum+map[i][j];
            }
            else if(map[i][j]==0)
            {
                for(int k=0;k<j;k++)
                {
                    if(map[k][j]!=0)
                       {
                          map[i][j]=map[i][k]+map[k][j];
                          break;
                       }
                }
                sum=sum+map[i][j];
            }
        }
    }
    return sum;
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        cin>>n;
        memset(map,0,sizeof(map));
        for (int i=0; i<n-1; i++)
        {
            int a,b,d;
            cin>>a>>b>>d;
            map[a][b]=map[b][a]=d;
        }
        cout<<(double)SUM(1)/(n*(n-1)/2)<<endl;
    }
    return 0;
}*/


#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int const MAX = 20002;
int n, cnt, head[MAX], num[MAX];
double sum;

struct EDGE
{
	int v, w, next;
}e[MAX];

void Add(int u, int v, int w)
{
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt ++;
}

void DFS(int u, int fa)
{
	num[u] = 1;
	for(int i = head[u]; i != -1; i = e[i].next)
	{
		int v = e[i].v;
		int w = e[i].w;
		if(v != fa)
		{
			DFS(v, u);
			num[u] += num[v];
			sum += 1.0 * num[v] * (n - num[v]) * w;
		}
	}
}

int main()
{
	int T;
	cin>>T;
	while(T --)
	{
		cnt = 0;
		sum = 0;
		memset(head, -1, sizeof(head));
		cin>>n;
		for(int i = 0; i < n - 1; i++)
		{
			int u, v, w;
			cin>>u>>v>>w;
			Add(u, v, w);
			Add(v, u, w);
		}
		DFS(0, -1);
		printf("%.7f\n", sum / ( n * (n - 1) / 2));
	}
}






















