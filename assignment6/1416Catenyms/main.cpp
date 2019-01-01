/*#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define MAXN 1005
struct Edge{
    int to,next;
    int index;
    bool flage;
}edge[MAXN];
int head[30],tot;
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int index)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].index = index;
    head[u] = tot++;
}
string str[1010];
int in[30],out[30],ans[1010],cnt;
void dfs(int u)
{
    for(int i=head[u]; i!=-1;i=edge[i].next)
    {
        if(!edge[i].flage)
        {
            edge[i].flage = true;
            dfs(edge[i].to);
            ans[cnt++] = edge[i].index;
        }
    }
}
int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
              cin>>str[i];
        sort(str,str+n);
        init();
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        int start=100;
        for(int i=n-1;i>=0;i--)
        {
            int u=str[i][0]-'a';
            int v=str[i][str[i].length()-1]-'a';
            addedge(u,v,i);
            out[u]++;
            in[v]++;
            if(u<start) start=u;
            if(v<start) start=v;
        }
        int cc1=0,cc2=0;
        for(int i=0;i<26;i++)
        {
            if(out[i]-in[i]==1)
            {
                cc1++;
                start = i;
            }else if(in[i]-out[i]==1)
                cc2++;
            else if(out[i]-in[i]!=0)
                cc1=3;
        }
        if(!((cc1==0&&cc2==0)||(cc1==1||cc2==1)))
        {
            cout << "***" << endl;
            continue;
        }
        cnt=0;
        dfs(start);
        if(cnt!=n)
        {
            cout << "***" <<endl;
            continue;
        }
        for(int i=cnt-1;i>=0;i--)
        {
            cout << str[ans[i]];
            if(i>0)
                cout << ".";
            else
                cout << endl;
        }

    }
    return 0;
}*/
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int n,vis[1005],len[1005],k,in[27],out[27];
int ans[1005],cnt;
string s[1005];
struct node
{
    int u,m;
};
vector<node> g[27];
void euler(int x)
{
    for(int i=0; i<g[x].size(); i++)
    {
        int v=g[x][i].u;
        if(!vis[g[x][i].m])
        {
            vis[g[x][i].m]=1;
            euler(v);
            cnt++;
            ans[cnt]=g[x][i].m;//����¼·����ţ��Ӷ�����·��
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int start=100;
        cin >> n;
        cnt=k=0;
        memset(vis,0,sizeof(vis));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=1; i<=26; i++)
            g[i].clear();
        for(int i=1; i<=n; i++)
            cin >> s[i];
        sort(s+1,s+n+1);
        start=s[1][0]-'a'+1;
        for(int i=1; i<=n; i++)
            len[i]=s[i].size();
        for(int i=1; i<=n; i++)
        {
            node t;
            t.u=s[i][len[i]-1]-'a'+1;
            t.m=i;
            g[ s[i][0]-'a'+1 ].push_back( t );
            out[ s[i][0]-'a'+1 ]++;
            in[s[i][len[i]-1]-'a'+1]++;

        }
        //printf("%d\n",start);
        int fin=0,fout=0,flag=0;
        for(int i=1; i<=26; i++)//�ж��ܲ��ܹ���ŷ����·
        {
            if(in[i]+1==out[i])
            {
                start=i;    //һ��Ҫ���£���Ϊ��Ȼ�����ˣ������������ַ����п��ܲ��ܹ���ŷ����·�����磺
                            //bdsfda  asdjfdsuc csdfgfd dfdfewre efef,������֮��Ϊasdjfdsuc  bdsfda csdfgfd dfdfewre efef
                            //��Ȼ�����˳���ǲ��ܹ��ɻ�·�ģ�����Ҫ���¸���start
                fin++;      //����1 �Ļ���˵�����ʵ���β��ĸ����ͬ�ģ�����0��˵������ͬ��
                            //����������˵����β�Ѿ�����������,Ҳ�Ͳ��ܹ���ŷ����·��
            }                //�Ȱѵ��ʰ��ֵ�������Ȼ���ж���ŷ����·����ֻ��ŷ��ͨ·�������ŷ����·��ֱ�Ӵӵ�0�ŵ��ʿ�ʼ�ѣ�
                            //�����ҵ����ȱ���ȴ�1���Ǹ����ʿ�ʼ�ѡ�
            else if(in[i]==out[i]+1)
            {
                fout++;//ͬ��
            }
            else if(in[i]!=out[i]) flag=1;
        }

        if(flag==1)
        {
            printf("***\n");
            continue;
        }
        else if( (fin==1&&fout==1) || (fin==0&&fout==0) )
        {
            cnt=0;
            euler(start);
            if(cnt==n)
            {
                for(int i=cnt; i>=1; i--)
                {
                    if(i==cnt)
                        cout << s[ ans[i] ];
                    else
                        cout << "." << s[ ans[i] ];
                }

/*
5 ab ba ab ba ab,���������оͲ��ܹ���������������Ǵ��
*/
                printf("\n");
            }
            else
            {
                printf("***\n");
                continue;
            }
        }
        else
        {
            printf("***\n");
            continue;
        }
    }
    return 0;
}








