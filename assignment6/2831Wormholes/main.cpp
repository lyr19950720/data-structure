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
    //û�и�����·������n-1��
    for( j=1; j<n; j++)
    {
        bool flag = false;
        for(int k=0; k<Eg.size();k++)
        {
            int s = Eg[k].s;
            int e = Eg[k].e;
            int t = Eg[k].t;
            //û�и�����¸��ζ������һ�β�ִ��if�ڵ����
            if(dist[e] > dist[s] + t)
            {
                dist[e] = dist[s] + t;
                flag = true;
            }
        }
        if(!flag) return true;//û�и�����·
        }
        for(i=0; i<Eg.size(); i++)
        {
            if(dist[Eg[i].e] > dist[Eg[i].s] + Eg[i].t)//���ִ����n-1�κ��ܼ������¾�˵���и�����·
                return false; //�и�����·

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
