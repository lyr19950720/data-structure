#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char a[105],x,b[105],ans[105];
int ansp;
char pan[10][5]= {"","","abc#","def#","ghi#","jkl#","mno#","pqrs","tuv#","wxyz"};
struct Trie
{
    int v;
    Trie *next[26];
}root;

int  cteate_Trie(int x)
{
    Trie *p=&root,*q;
    int len=strlen(a);
    for(int i=0; i<len; i++)
    {
        int di=a[i]-'a';
        if(p->next[di]==NULL)
        {
            q=new Trie;
            for(int i=0; i<26; i++)
            {
                q->next[i]=NULL;
            }
            q->v=0;
            p->next[di]=q;
        }
        p=p->next[di];
        (p->v)+=x;
    }
}
int  find_Trie(Trie *heat,char *ttx,int l)
{
    if(l>105)
        return 0;
    if(b[l]=='\0')
    {
        if(ansp<heat->v)
        {
            ttx[l]='\0';
            ansp=heat->v;
            strcpy(ans,ttx);
            return 0;
        }
    }
    if(b[l]<'2'||b[l]>'9')//不加这个判断就直接RE
        return 0;
    int pi=b[l]-'0';
    for(int i=0; i<4; i++)
    {
        if(pan[pi][i]!='#')
        {
            int di=pan[pi][i]-'a';
            if(heat->next[di]!=NULL)
            {
                ttx[l]=pan[pi][i];
                find_Trie(heat->next[di],ttx,l+1);
            }
        }

    }
}
int main()
{
    char ttx[105];
    int t,n,m,Case=1;
    cin>>t;
    while(t--)
    {
        for(int i=0; i<26; i++)
        {
            root.next[i]=NULL;
        }
        root.v=0;
        cin>>n;
        while(n--)
        {
            scanf("%s%d",a,&x);
            cteate_Trie(x);
        }
        printf("Scenario #%d:\n",Case++);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s",a);
            int len=strlen(a);
            for(int i=1; i<len; i++)
            {
                memset(ttx,0,sizeof(ttx));
                ansp=0;
                strncpy(b,a,i);
                b[i]='\0';
                find_Trie(&root,ttx,0);
                if(ansp==0)
                    printf("MANUALLY\n");
                else
                    printf("%s\n",ans);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

