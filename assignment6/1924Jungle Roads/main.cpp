#include <iostream>
#include <cstring>
using namespace std;
const int INF = 10000;
const int MAXN = 110;
int vis[MAXN];//是否被访问过
int lowc[MAXN];//保存相关顶点间的权值
int Prim(int cost[][MAXN],int n)
{
    int i,j,k;
    int sum = 0;
    memset(vis,0,sizeof(vis));
    memset(lowc,INF,sizeof(lowc));
    vis[0] = 1;
    for( i=1; i<n; i++){
        lowc[i] = cost[0][i];//读入第一行数据
    }
    for( j=1; j<n; j++)
    {
        int minc = INF;
        int p = -1;
        for( k=0; k<n; k++)
            if(vis[k]==0&&lowc[k]<minc)
            {

                minc = lowc[k];
                p = k;  //用来记录权值最小的点的下标
            }
        if(minc == INF)
            return -1;//说明原图不连通
        sum += minc;
        vis[p] = 1;
        for( i=0; i<n; i++ )
        {
            if(vis[i]==0 && cost[p][i] < lowc[i])
                lowc[i] = cost[p][i];
        }
        }
    return sum;
}
int main()
{
    int N;
    while(cin>>N && N)
    {
        int G[MAXN][MAXN];
        memset(G,INF,sizeof(G));
        for(int i=0; i<N-1; i++)
        {
            char s,e;int n,w;
            cin >> s >> n;
            for(int j=0; j< n; j++)
            {
                cin >> e >> w;
                G[s-'A'][e-'A'] = G[e-'A'][s-'A'] = w;
            }
        }
        cout << Prim(G,N) << endl;
    }

    return 0;
}
