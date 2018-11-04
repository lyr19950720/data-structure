#include <stdio.h>
#include<iostream>
using namespace std;
int mins;
int a[105][105],visit[105][105];
void dfs(int row,int col,int inr,int inc,int outr,int outc,int step)
{
    
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int tx,ty,k;
    if(inr==outr+1&&inc==outc+1){
        if(step<mins){         
            mins=step;
            return ;
        }
    }

    for(k=0;k<4;k++){
        tx=inr+next[k][0];
        ty=inc+next[k][1];
        if(tx<1||ty<1||tx>row||ty>col)
            continue;
        if(a[tx][ty]==0&&visit[tx][ty]==0){
            visit[tx][ty]=1;
            dfs(row,col,tx,ty,outr,outc,step+1);
        }

    }
    return ;
}

int main()
{
    int i,j,n;
    cin>>n;
    while(n--){
        int row,col,inr,inc,outr,outc;//输入探索图的列和行
        cin>>col>>row;//初始化探索图
        for(i=1;i<=row;i++){
            for(j=1;j<=col;j++){
                cin>>a[i][j];
                visit[i][j] = 0;
            }

        }
        //输入起点和终点

        cin>>inc>>inr>>outc>>outr;
        inc=inc+1;inr=inr+1;
        visit[inr][inc]=1;
        mins = 9999;
        dfs(row,col,inr,inc,outr,outc,1);
        cout<<mins<<endl;
    }
    return 0;
}