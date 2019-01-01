#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int INF = 65536;
const int MAXN = 550;
int dist[MAXN];
struct Edge
{
    int s,e;
    int t;
    Edge(int S=0,int E=0,int T=0):s(S),e(E),t(T){}
};
vector<Edge>Eg;
bool bellman_ford(int start,int n){
    int i,j;
    for( i=0; i<=n;i++)
        dist[i] = INF;
    dist[start] = 0;
    //没有负环回路最多更新n-1次
    for( j=1; j<n; j++)
    {
        bool flag = false;
        for(int k=0; k<Eg.size();k++)
        {
            int s = Eg[k].s;
            int e = Eg[k].e;
            int t = Eg[k].t;
            //没有负环贿赂意味着总有一次不执行if内的语句
            if(dist[e] > dist[s] + t)
            {
                dist[e] = dist[s] + t;
                flag = true;
            }
        }
        if(!flag) return true;//没有负环回路
        }
        for(i=0; i<Eg.size(); i++)
        {
            if(dist[Eg[i].e] > dist[Eg[i].s] + Eg[i].t)//如果执行了n-1次后还能继续更新就说明有负环回路
                return false; //有负环回路

        }
        return true;

}
int main()
{
    int t,N,M,W,S,E,T;
    cin >> t;
    while(t--)
    {
        Eg.clear();
        cin >> N >> M >> W;
        for(int i=1; i<=M; i++)
        {
              cin >> S >> E >> T;
              Eg.push_back(Edge(S,E,T));
              Eg.push_back(Edge(E,S,T));

        }
        while(W--)
        {
            cin >> S >> E >> T;
            Eg.push_back(Edge(S,E,-T));

        }

        if(bellman_ford(1,N))
            cout << "NO" << endl;
        else
            cout << "YES" <<endl;

    }

    return 0;
}
