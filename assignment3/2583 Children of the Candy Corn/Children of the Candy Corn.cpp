#include<iostream>
#include <queue>
using namespace std;
#define INF 100000
typedef pair<int,int> p;
queue<p> que;
int dist[45][45];
int visit[45][105];int mins;char a[45][105];
int dfs1(int row,int col,int inr,int inc,int outr,int outc,int step,int d)
{
    
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int tx,ty,k;
    if(inr==outr&&inc==outc)
	{
		return step;
    }

    for(k=0;k<4;k++)
	{
        tx=inr+next[(d+k+3)%4][0];
        ty=inc+next[(d+k+3)%4][1];
        if(tx<1||ty<1||tx>row||ty>col)
            continue;
        if(a[tx][ty]!='#')
		{
            visit[tx][ty]=1;
            return dfs1(row,col,tx,ty,outr,outc,step+1,(d+k+3)%4);
        }

    }
    return 0;
}
int dfs2(int row,int col,int inr,int inc,int outr,int outc,int step,int d)
{
    
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int tx,ty,k;
    if(inr==outr&&inc==outc)
	{
		return step;
    }

    for(k=3;k>=0;k--)
	{
        tx=inr+next[(d+k+2)%4][0];
        ty=inc+next[(d+k+2)%4][1];
        if(tx<1||ty<1||tx>row||ty>col)
            continue;
        if(a[tx][ty]!='#')
		{
            visit[tx][ty]=1;
            return dfs2(row,col,tx,ty,outr,outc,step+1,(d+k+2)%4);
        }

    }
    return 0;
}

int bfs (int inr, int inc,int row, int col,int outr, int outc){
    dist[inr][inc] = 0;
    que.push(p(inr,inc));
	  int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    while(que.size()){
        p cut = que.front();
        que.pop();
        for(int i=0; i<4; i++){
			
            int tx = cut.first + next[i][0];
            int ty = cut.second + next[i][1];
            if(tx>0 && tx<=row&& ty>0 && ty<=col && a[tx][ty]!='#' &&  dist[tx][ty] == INF){
                dist[tx][ty] = dist[cut.first][cut.second] + 1;
               que.push(p(tx,ty));
            }
        }
    }
    return dist[outr][outc];
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int row,col,inr,inc,outr,outc;
      cin>>col>>row;
	  if(col>=3&&row<=40)
	  {//初始化迷宫
		for(int i=1;i<=row;i++)
			for(int j=1;j<=col;j++)
			{
				cin>>a[i][j];
				visit[i][j]=0;
				dist[i][j]=INF;
			//获得起点和终点的横坐标和纵坐标
				if(a[i][j]=='S') inr=i,inc=j;
				if(a[i][j]=='E') outr=i,outc=j;
			}
		visit[inr][inc]=1;
        //dfs(row,col,inr,inc,outr,outc,1);dfs(row,col,inr,inc,outr,outc,1);
		cout<<dfs1(row,col,inr,inc,outr,outc,1,1)<<" ";
		cout<<dfs2(row,col,inr,inc,outr,outc,1,1)<<" ";
        //cout<<mins<<endl;
		cout<<bfs(inr,inc,row,col,outr,outc)+1 << endl;
		
	  }
	}
	return 0;
}