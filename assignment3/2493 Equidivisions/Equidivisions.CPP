 #include <iostream>     
 #include <queue> 
 #include <string>
#include <cstring>         
 using namespace std;
  int map[101][101];//迷宫
  int vst[101][101];//表示点是否被访问过
  int n;
  int sum;
  int dir[4][2]={  0,1,  0,-1,  1,0,  -1,0};//四个方向
  
  typedef struct node
 {
      int x,y;
 }Node;
 
 bool check(node temp)//检查temp
 {  
         return   temp.x>=0&&temp.x<n&&temp.y>=0&&temp.y<n&&!vst[temp.x][temp.y];
     
 }
  
  void bfs(int x,int y)
 {
     int i;
     sum=1;
     node pre,next;//pre前一个访问的点，next目前正在访问的点
     queue<node>Que;
     vst[x][y]=1;
     pre.x=x;
     pre.y=y;
      Que.push(pre);
      while(!Que.empty())
      {
         pre=Que.front();
         Que.pop();
        for(i=0;i<4;i++)//依次访问目标点的四个方向
        {
              next.x=pre.x+dir[i][0];
              next.y=pre.y+dir[i][1];
              if(check(next)&&map[x][y]==map[next.x][next.y])
              {
                 sum++;
                 vst[next.x][next.y]=1;
                 Que.push(next);
                 if(sum==n)
                     return;
            } 
           }
    }
 }
  
  int main()
  {
      int i,j;
      int x,y;
      bool flag;
      while(cin>>n&&n!=0)
      {
         memset(vst,0,sizeof(vst));
         memset(map,0,sizeof(map));
         for(i=1;i<n;i++)
          {    for(j=0;j<n;j++)
             {
                 cin>>x>>y;
                 map[x-1][y-1]=i;
              }
          
          }
          for(i=0;i<n;i++)
          {
              for(j=0;j<n;j++)
              {
                  flag=true;//用来标记n个数字是否找全
                  if(!vst[i][j])
                  {
                      bfs(i,j);
                      if(sum!=n)
					  {
                        flag=false;
                         break;
					  }
                 }
             }
            if(!flag)
                 break;
         }
         if(flag)
             cout<<"good"<<endl;
         else
              cout<<"wrong"<<endl;

     }

     return 0;
}
/*#include <iostream>
#include <string.h>
using namespace std;
int maps[105][105];
int visit[105][105];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int cnt,n;
void dfs (int x, int y, int number){
    if (visit[x][y] == 1)
        return;
    if (x<0 || x>=n || y<0 || y>=n)
        return;
    if(number != maps[x][y])
        return;
    cnt++;
    visit[x][y] = 1;
    for(int i=0; i<4; i++){
        dfs(x+dir[i][0],y+dir[i][1],number);
    }
}
int main()
{
	int i,j,x,y;
    while(cin >>n){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                maps[i][j] = 0;
                visit[i][j] = 0;
            }
        }
        for(i=0; i<n*(n-1); i++){
            cin >> x >> y;
            maps[x-1][y-1] = i/n +1;
        }

      
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                cnt=0;
               if(visit[i][j] == 1)
                    continue;
                dfs(i,j,maps[i][j]);
                if (cnt!=n){
                     break; 
                }

            }
            if(j<n)
                break;
        }
        if(i<n)
            cout << "wrong" << endl;
        else
            cout << "good" << endl;
    }

    return 0;
}*/