/*#include<iostream>
#include<string>
#include<math.h>
typedef int Status;
typedef int ElemType;
using namespace std;
typedef struct LNode
{
	double x;//������
	double y;//������
	int f;//Ƶ�� 
	struct LNode *next;
}LNode,*LinkList;
Status Create_L_tail(LinkList &L,int n)//β�巨������λ��
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
  int x,y,f,d;//d:����֮��ľ���
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
	//n:����ĵ�����x,y:����ĵ�ĺ�����������ꣻfrequencies��Ƶ��ֵ
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


//����ڵ㣬����������Ϣ��x��y��
struct Node  
{
    double x;
    double y;
};
Node nd[15];//��Ŀ˵���ֻ��12����

//����ͼ�ṹ�����ڽӾ���ʽ���棬color���鱣����Ǹĵ��Ⱦɫ��color == 0 ��ʾû��Ⱦ��ɫ��
struct Graph
{
    int edges[15][15];
    int color[15];
}G;
//�������֮�����
double dis(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

//������С��20�ĵ㡰��������
void connect(int id)
{
    for (int i = 1; i < id; i++)
    {
        double distance = dis(nd[id].x, nd[id].y, nd[i].x, nd[i].y);
        if (distance <= 20.01)
            G.edges[id][i] = 1, G.edges[i][id] = 1;
    }
}

//ͼ�ĳ�ʼ��
void initial_graph()
{
    memset(G.color, 0, sizeof(G.color));
    memset(G.edges, 0, sizeof(G.edges));
}

//��ö�ͼȾɫ��������ɫ
int min_colors(int n)
{
    int used[10] = { 0 };//used[i] == 1 ��ʾ��ɫ��i�����ڽӵ��г��ֹ�
    int max_color = 0;//��ǰ���õ���ɫ����
    for (int i = 1; i <= n; i++)
    {
        memset(used, 0, sizeof(used));
        for (int j = 1; j <= n; j++)
        {
            if (i != j && G.edges[i][j]) //����ڵ� j �ǽڵ� i ���ڽӵ㣬��ô�ѽڵ�j����ɫ���Ϊused
                used[G.color[j]] = 1;
        }
        for (int k = 1; k <= max_color; k++)//�ڵ�ǰ���õ���ɫ��Ѱ����û���� i ���ڽӵ����ɫ��һ����
        {
            if (!used[k]) //����ҵ����Ͱ�i���Ϊ������ɫ
            {
                G.color[i] = k;
                break;
            }
        }
        if (!G.color[i])//����������õ���ɫ���� i ���ڽӵ��г����ˣ���û�취��ֻ�ܶ��һ����ɫ
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
