#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int map[2002][2002];
int sum[2002];
int visit[2002];
int Max,n;
int bfs(int v)
{
    memset(visit,0,sizeof(visit));
    Max=0;
    sum[v]=0;
    visit[v]=1;
    queue<int> q;
    q.push(v);
    int t,key=0;
    while (!q.empty())
    {
        t=q.front();//
        for (int i=1; i<=n; i++)
        {
            if(map[t][i]!=-1 && !visit[i])
            {
                visit[i]=1;
                q.push(i);
                sum[i]=sum[t]+map[t][i];
                if(sum[i]>Max)
                {
                    Max=sum[i];
                    key=i;
                }
            }
        }
        q.pop();
    }
    return key;

}
int main()
{
    int T,v;
    cin>>T;
    while (T--)
    {
        cin>>n;
        memset(map,-1,sizeof(map));
        for (int i=1; i<n; i++)
        {
            int a,b,d;
            cin>>a>>b>>d;
            map[a][b]=map[b][a]=d;
        }
        v=bfs(1);
        bfs(v);
        cout<<Max<<endl;
    }
    return 0;
}
























