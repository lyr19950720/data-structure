#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <stdio.h>
using namespace std;
const int MAXN = 505;
int Map[MAXN][MAXN];
int visit[MAXN];
int match[MAXN];
int n;
struct node
{
    int a,b,c,d,stime,etime;
    node(int _a=0,int _b=0,int _c=0,int _d=0,int _stime=0,int _etime=0):
         a(_a),b(_b),c(_c),d(_d),stime(_stime),etime(_etime){}
}edge[MAXN];

int find(int s)
{
    for(int i=1;i<=n;i++)
    {
        if(!visit[i] && Map[s][i])
        {
            visit[i] = 1;
            if(match[i] == -1 || find(match[i]))
            {
                match[i] = s;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int T,hour,minu;
    cin >> T;
    while(T--)
    {
       cin >> n;
       memset(Map,0,sizeof(Map));
       int a,b,c,d,stime,etime;
       for(int i=1; i<=n; i++)
       {

           scanf("%d:%d%d%d%d%d",&hour,&minu,&a,&b,&c,&d);
           stime = 60*hour+minu;
           etime = abs(a-c)+abs(b-d)+stime;
           edge[i] = node(a,b,c,d,stime,etime);
           for(int j=1; j<=i;j++)
           {
               int temp1 = abs(edge[j].a-edge[i].c)+abs(edge[j].b-edge[i].d);//i-j��ʱ��
               int temp2 = abs(edge[i].a-edge[j].c)+abs(edge[i].b-edge[j].d);//j��i��ʱ��
               if(temp1+edge[i].etime < edge[j].stime)//i�Ľ���ʱ��+i��j���ѵ�ʱ�����С��j����ʼʱ�䣬˵��i-j���Բ����³�

                       Map[i][j] = 1;
               else if(temp2+edge[j].etime < edge[i].stime)//j�Ľ���ʱ��+j��i���ѵ�ʱ�����С��i����ʼʱ�䣬˵��i-j���Բ����³�
                 Map[j][i] = 1;

           }
       }
            memset(match,-1,sizeof(match));
            int taxi = 0;
            for(int i=1; i<=n; i++ )
            {
                memset(visit,0,sizeof(visit));
                if(find(i)){
                    taxi++;
                }

            }
            cout << n-taxi << endl;
            }
    return 0;
}
