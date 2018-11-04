#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int Next[4][2]={{-1,0},{0,-1},{1,0},{0,1}};//�ϣ����£���
char map[101][101];
int visit[101][101][4];
int c,row,col,i,j,inx,iny,outx,outy;
struct node
{  
   int x,y,step,dir;
   //��ʼ��x,y,step,dir
    
   node(int inx,int iny,int step,int dir):x(inx),y(iny),step(step),dir(dir){ }
};

int bfs(int inx,int iny,int step,int dir)
{   
		int tx,ty,tf,i,j;
		queue<node>q;
        q.push(node(inx,iny,step,dir));
        while(!q.empty())
		{
             node next= q.front();//ȡ����ͷԪ��
			 //cout<<next.x<<" "<<next.y<<" "<<next.dir<<" "<<next.step<<endl;
             q.pop();//����
             if(next.x==outx&&next.y==outy)//�������յ�ʱ������step
                 return next.step;
                //go straight
                 tx=next.x+Next[next.dir][0];
                 ty=next.y+Next[next.dir][1];
                 tf=next.dir;
				 
                 if(tx>=0&&tx<row&&ty>=0&&ty<col&&map[tx][ty]!='#'&&!visit[tx][ty][tf])
                 { 
                     visit[tx][ty][tf]=1;
                     q.push(node(tx,ty,next.step+1,tf));
                 }
                 //turn left ,��ת��ת������겻��
                 tx=next.x;
                 ty=next.y;
                 tf=(next.dir+1)%4;
                 if(!visit[tx][ty][tf])
                 {
                  
                   visit[tx][ty][tf]=1;
                   q.push(node(tx,ty,next.step+1,tf));
                 }
                 //turn right
                 tx=next.x;
                 ty=next.y;
                 tf=(next.dir+3)%4;
                  if(!visit[tx][ty][tf])
                 {
                   visit[tx][ty][tf]=1;
                    q.push(node(tx,ty,next.step+1,tf));
                 }        
		 }
                         
		return -1;
}

int main()
{
    cin>>c;
    while(c--)
    {   
		memset(visit,0,sizeof(visit));//��ʼ��visit
		cin>>row>>col;
		   for(i=0;i<row;i++)
		     for(j=0;j<col;j++)
			 {
				 cin>>map[i][j];
				if(map[i][j]=='S')//�����������
				   inx=i,iny=j;

				if(map[i][j]=='T')//����յ������
					outx=i, outy=j;                               
			 }
			cout<<bfs(inx,iny,0,0)<<endl;			
     }
     return 0;
}

