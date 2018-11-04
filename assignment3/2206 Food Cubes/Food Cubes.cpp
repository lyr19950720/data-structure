/*#include <iostream>  
#include <string>
using namespace std;  
bool G[105][105][105];//三维空间  
//每一个case的边界  
int minx,miny,minz;  
int maxx,maxy,maxz;  
int min(int a,int b)
{
  if(a<b)
	  b=a;
  return b;

}

int max(int a,int b)
{
  if(a>b)
	  b=a;
  return b;
}
void init(int m)  
{  
	int i,x,y,z;
    minx = miny = minz = 105;  
    maxx = maxy = maxz = 1;  
    memset(G,0,sizeof(G));
     
    for (i = 0;i < m;i ++)  
    {  
        cin >> x >> y >> z;  
        G[x][y][z] = 1;  
		//更新边界  
        minx = min(x,minx);   maxx = max(x,maxx);  
        miny = min(y,miny);   maxy = max(y,maxy);  
        minz = min(z,minz);   maxz = max(z,maxz);  
    } 
}  
  
bool bfs(int x,int y,int z)  
{  
    if (G[x][y][z] == 1) 
		return true;	//如果是food cube或者被处理过的"hole"点，返回true  
    if (x == minx || x == maxx || y == miny || y == maxy  || z == minz || z == maxz )
		return false;	//判断该点是否为边界点 ,如果是边界点，返回false  
      
    G[x][y][z] = 1;	//将hole点标记为1，表示已处理过  
    bool pd = true;  
	//遍历上下左右前后  
    pd &= bfs(x,y,z + 1);  
    pd &= bfs(x,y,z - 1);  
    pd &= bfs(x - 1,y,z);  
    pd &= bfs(x + 1,y,z);  
    pd &= bfs(x,y + 1,z);  
    pd &= bfs(x,y - 1,z);  
 
    return pd;   
}  
  
void find()  
{  
    int result = 0;  
    for (int i = minx;i <= maxx;i ++)  
        for (int j = miny;j <= maxy;j ++)  
            for (int k = minz;k <= maxz;k ++)  
            {  
                if (G[i][j][k] == 0 && bfs(i,j,k))  
                    result ++;  
            } 
   cout<<result<<endl;  
}    
int main()  
{  
    int cases,m;  
    cin >> cases;  
    while(cases --)  
    {  
        cin >> m;
        init(m); 
		find();
	}
	return 0;
}*/
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int data[105][105][105];
bool is_valid( int x, int y, int z ) {
    if ( x>=0&&x<=101&&y>=0&&y<=101&&z>=0&&z<=101 )
	    return true;
    return false; 
}
struct coor {
    int x;
    int y;
    int z;
};

int main()
{
    int t,m,x,y,z,i,j,k,ctr;
    queue<struct coor> temp;
    struct coor qq,pp;
    cin >> t;
    while ( t-- ) {
        cin >> m;
        ctr=0;
        memset(data,0,105*105*105*sizeof(int));
        for ( i=0;i<m;i++ ) {
            cin >> x >> y >> z;
            data[x][y][z]=1;
        }
        for ( x=1;x<=100;x++ ) {
            for ( y=1;y<=100;y++ ) {
                for ( z=1;z<=100;z++ ) {
                    if ( data[x][y][z]==0 ) {
                       ctr++;
                       qq.x=x;
                       qq.y=y;
                       qq.z=z;
                       temp.push(qq);
                        data[x][y][z]=1;
                        while (!temp.empty()) {
                            pp=temp.front();
                            i=pp.x;
                            j=pp.y;
                            k=pp.z;
                            temp.pop();
                          if ( is_valid(i+1,j,k)&&data[i+1][j][k]==0 ) {
                                data[i+1][j][k]=1;
                                qq.x=i+1;
                                qq.y=j;
                                qq.z=k;
                                temp.push(qq);
                            }
                            if ( is_valid(i,j+1,k)&&data[i][j+1][k]==0 ) {
                                data[i][j+1][k]=1;
                                qq.x=i;
                                qq.y=j+1;
                                qq.z=k;
                                temp.push(qq);
                            }
                            if ( is_valid(i,j,k+1)&&data[i][j][k+1]==0 ) {
                                data[i][j][k+1]=1;
                                qq.x=i;
                                qq.y=j;
                                qq.z=k+1;
                                temp.push(qq);
                            }
                           if ( is_valid(i-1,j,k)&&data[i-1][j][k]==0 ) {
                                data[i-1][j][k]=1;
                                qq.x=i-1;
                                qq.y=j;
                                qq.z=k;
                                temp.push(qq);
                            }
                            if ( is_valid(i,j-1,k)&&data[i][j-1][k]==0 ) {
                                data[i][j-1][k]=1;
                                qq.x=i;
                                qq.y=j-1;
                                qq.z=k;
                                temp.push(qq);
                            }
                            if ( is_valid(i,j,k-1)&&data[i][j][k-1]==0 ) {
                                data[i][j][k-1]=1;
                                qq.x=i;
                                qq.y=j;
                                qq.z=k-1;
                                temp.push(qq);
                            }
                        }
                    }
                }
            }
        }
        cout << ctr-1 << endl;
    }
//  system("pause"); 
    return 0;
} 
