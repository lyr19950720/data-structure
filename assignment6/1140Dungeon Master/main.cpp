#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
char a[100][100][100];
int  vis[100][100][100];
int dir[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int L,R,C,sx,sy,sz,ex,ey,ez;
struct Node
{
    int x,y,z,step;
};
bool is_logical(Node t)
{
    return a[t.x][t.y][t.z]!='#' && t.x>=0 && t.x<L && t.y>=0 && t.y<R && t.z>=0 && t.z<C && vis[t.x][t.y][t.z]==0;
}
int BFS()
{
    queue<Node>q;
    Node ts,te;
    ts.x = sx, ts.y = sy, ts.z = sz, ts.step = 0;
    vis[ts.x][ts.y][ts.z] = 1;
    q.push(ts);
    while(!q.empty())
    {
        ts = q.front();
        q.pop();
        //cout << ts.x << ts.y << ts.z << " haha"<< endl;
        if(ts.x==ex && ts.y==ey && ts.z==ez)
            return ts.step;
        for(int i=0; i<6; i++)
        {
            te.x = ts.x + dir[i][0];
            te.y = ts.y + dir[i][1];
            te.z = ts.z + dir[i][2];
           // cout << te.x << te.y << te.z << endl;
            if(is_logical(te))
            {
                vis[te.x][te.y][te.z] = 1;
                te.step=ts.step+1;
                q.push(te);
            }
        }
    }
     return 0;
}
int main()
{

    while(cin>>L>>R>>C)
    {
        if(L==0&&R==0&&C==0)
            break;
        memset(a,' ',sizeof(a));
        memset(vis,0,sizeof(vis));
        for(int i=0; i<L; i++)
        {
            for(int j=0 ; j<R; j++)
            {
                cin>>a[i][j];
                for(int k=0; k<C; k++)
                {
                    if(a[i][j][k]=='S')
                    {
                        sx = i, sy = j, sz = k;
                    }
                    if(a[i][j][k]=='E')
                    {
                        ex = i, ey = j, ez = k;
                    }
                }

            }

        }
        //cout << ex << ey << ez << endl;
        int result = BFS();
        if(result!=0)
        {
            cout << "Escaped in " << result << " minute(s)." << endl;
        }else
            cout << "Trapped!" << endl;

    }
    return 0;
}
