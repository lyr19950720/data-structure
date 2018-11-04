/*#include<iostream>
#include<string>
#include<math.h>
typedef int Status;
typedef int ElemType;
using namespace std;
typedef struct LNode
{
	double x;//横坐标
	double y;//纵坐标
	int f;//频率 
	struct LNode *next;
}LNode,*LinkList;
Status Create_L_tail(LinkList &L,int n)//尾插法——正位序
{
	double x=0.0,y=0.0;int f=0;
	L=new LNode;
	L->next =NULL;
	LinkList p,s=L;
	for(int i=1;i<=n;i++)
	{
		p=new LNode;
		cin>>p->x>>p->y ;
		p->f=0;
		p->next =s->next ;
		s->next =p;
		s=p;
	}
	return 0;
}
Status calculate(LinkList &L,int n)
{
  int x,y,f,d;//d:两点之间的距离
  LinkList p,s;p=L->next;
  while(n--)
  {
	  s=p;
	//  s=p->next;
	for(int i=0;i<n;i++)
	{
	  d=sqrt(pow(s->x-p->x,2)+pow(s->y-p->y,2));
	 
	  if(d<20)
	  {
		  p->f++;
		  s->f++;
	  } 
	  s=s->next;
	}
	p=p->next;
  }
  
return 0;
}

int findmax(LinkList &L,int n)
{
	int max=0;
	LinkList p;p=L->next;
	for(int i=0;i<n;i++)
	{
		if(p->f>max)
			max=p->f;

	}
  cout<<" can be covered in "<<--max<<" frequencies."<<endl;
	return 0;
}
int main()
{
	//n:输入的点数，x,y:输入的点的横坐标和纵坐标；frequencies：频率值
	LinkList L;int n,x,y,f,c=0;
	while(cin>>n&&n!=0&&n<=12)
	{
		c++;
		Create_L_tail(L,n);
		calculate(L,n);
		cout<<"The towers in case "<<c;
		 findmax(L,n);
	}
	return 0;
}*/
//#include<stack>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;


//定义节点，包含坐标信息（x，y）
struct Node  
{
    double x;
    double y;
};
Node nd[15];//题目说最多只有12个塔

//定义图结构，以邻接矩阵方式储存，color数组保存的是改点的染色（color == 0 表示没有染过色）
struct Graph
{
    int edges[15][15];
    int color[15];
}G;
//获得两点之间距离
double dis(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

//将距离小于20的点“连起来”
void connect(int id)
{
    for (int i = 1; i < id; i++)
    {
        double distance = dis(nd[id].x, nd[id].y, nd[i].x, nd[i].y);
        if (distance <= 20.01)
            G.edges[id][i] = 1, G.edges[i][id] = 1;
    }
}

//图的初始化
void initial_graph()
{
    memset(G.color, 0, sizeof(G.color));
    memset(G.edges, 0, sizeof(G.edges));
}

//获得对图染色的最少颜色
int min_colors(int n)
{
    int used[10] = { 0 };//used[i] == 1 表示颜色“i”在邻接点中出现过
    int max_color = 0;//当前已用的颜色数量
    for (int i = 1; i <= n; i++)
    {
        memset(used, 0, sizeof(used));
        for (int j = 1; j <= n; j++)
        {
            if (i != j && G.edges[i][j]) //如果节点 j 是节点 i 的邻接点，那么把节点j的颜色标记为used
                used[G.color[j]] = 1;
        }
        for (int k = 1; k <= max_color; k++)//在当前已用的颜色中寻找有没有与 i 的邻接点的颜色不一样的
        {
            if (!used[k]) //如果找到，就把i标记为这种颜色
            {
                G.color[i] = k;
                break;
            }
        }
        if (!G.color[i])//如果所有已用的颜色都在 i 的邻接点中出现了，那没办法，只能多加一种颜色
            max_color += 1, G.color[i] = max_color;
    }
    return max_color;
}

int main()
{
    int n;
    int num = 1;
    while (cin >> n, n)
    {
        initial_graph();
        memset(nd, 0, sizeof(nd));
        for (int i = 1; i < n + 1; i++)
        {
            cin >> nd[i].x >> nd[i].y;
            connect(i);
        }
        int min_c = min_colors(n);
        cout << "The towers in case " << num++ << " can be covered in "<< min_c <<" frequencies." << endl;

    }

}
