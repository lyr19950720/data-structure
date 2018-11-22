/*#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
struct Trie
{
    int cnt;//记录子串数量
    int num;//去重
    Trie *next[26];
    Trie()
    {
        num = 0;
        cnt = 0;
        for(int i = 0; i < 26; i ++)
            next[i] = 0;
    }
}root;

void insert(char *s, int i)
{
    Trie *p = &root;
    for(int k = 0;k<strlen(s);k++)
    {
        int id = s[k] - 'a';//获取字符的id
        if(p -> next[id] == 0)
            p -> next[id] = new Trie;
        p = p -> next[id];
        if(p -> num != i)
        {
            p -> num = i;
            p -> cnt ++;
        }
    }
}

int findstr(char *s)
{
    int k = 0;
    Trie *p = &root;
    for(int k = 0;k < strlen(s);k ++)
    {
        int id=s[k] - 'a';
        if(p->next[id]!=0)
            p = p -> next[id];
        else
            return 0;
    }
    return p -> cnt;
}

int main()
{

    char s[22];
    int n1, n2;
    cin >> n1;
    for(int i = 1; i <= n1; i ++)
    {
        cin >> s;
        int len = strlen(s);
        for(int j = 0; j < len; j ++)
        {
            insert(s + j, i);
        }
    }
    cin >> n2;
    for(int i = 0; i < n2; i ++)
    {
        cin>>s;
        cout << findstr(s)<<endl;
    }
    return 0;
}


#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define MAX 100
using namespace std;

void toposort(int map[MAX][MAX],int indegree[MAX],int n)
{
    int i,j,k;
    for(i=0;i<n;i++) //遍历n次
    {
        for(j=0;j<n;j++) //找出入度为0的节点
        {
            if(indegree[j]==0)
            {
                indegree[j]--;
                cout<<j<<endl;
                for(k=0;k<n;k++) //删除与该节点关联的边
                {
                    if(map[j][k]==1)
                    {
                        indegree[k]--;
                    }
                }
                break;
            }
        }
    }
}


int main(void)
{
    int n,m; //n:关联的边数，m:节点数
    while(scanf("%d %d",&n,&m)==2&&n!=0)
    {
        int i;
        int x,y;
        int map[MAX][MAX]; //邻接矩阵
        int indegree[MAX]; //入度
        memset(map,0,sizeof(map));
        memset(indegree,0,sizeof(indegree));
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            if(!map[x][y])
            {
                map[x][y]=1;
                indegree[y]++;
            }
        }
        toposort(map,indegree,m);
    }
    return ;
}
*/
#include <iostream>
#include <algorithm>
#include <set>
set<int> s;
/*int cnt=0,A[4005],B[160005];
int f_search(int temp,int left,int right)
{
    int mid=(left+right)/2;
    if(temp == B[mid]) //cnt++;
        cout<<temp<<endl;
    if(temp > b[mid]) f_search(temp,mid+1,right);
    if(temp < b[mid]) f_search(temp,left,mid-1);
    return 0;
}
int main()
{
    int M,N,i,j;
    for(i=0;i<M;i++)
        cin>>A[i];
    for(j=0;j<N;j++)
        cin>>B[j];
    sort(B,B+N);
    for(i=0;i<M;i++)
        f_search(A[i],0,N-1);
   // cout << cnt <<endl;
}
*/
int main()
{
    int M,N,i,j,num;
    for(i=0;i<M+N-1;i++)
	{
		cin>>num;s.insert(num);
	}
        
    cout<<(M+N)-s.size() <<endl;

   // cout << cnt <<endl;
}





















