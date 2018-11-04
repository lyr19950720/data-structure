#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#define M 100000
#define N 500
using namespace std;
struct node{
    int v,next;
    string s;
}edge[M];
int head[M];
int num;
bool vis[N];
string Ans[N][N];
void Insert(int a,int b,string str) {
    edge[num].v = b;
    edge[num].s = str;
    edge[num].next = head[a];
    head[a] = num++;
}
void BFS(int S,char ch,int n) {
    queue<int>q;
    q.push(S);
    memset(vis,0,sizeof(vis));
    int x,y;
    string str;
    while(!q.empty()) {
        x = q.front();
        q.pop();
        for(int i = head[x]; i != -1; i = edge[i].next) {
            y = edge[i].v;
            str = edge[i].s;
            if(vis[y]) continue;
            if(str.find(ch) != string::npos) {
                q.push(y);
                vis[y] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        //cout << vis[i] << " " ;
        if(vis[i])
            Ans[S][i] += ch;
    }
    return;
}
int main() {
    int n,a,b;
    string str;
    while(cin >> n && n != 0) {
        memset(head,-1,sizeof(head));
        num = 0;
        while(cin >> a >> b) {
            if(a == 0 && b == 0) break;
            cin >> str;
            Insert(a,b,str);
        }
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                Ans[i][j] = "";
        for(int i = 0; i < 26; i++) {
            char ch = (char)('a' + i);
            for(int j = 1; j <= n; j++) {
                BFS(j,ch,n);
            }
        }
       /* for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                cout << Ans[i][j] << " " ;
            cout << endl;
        }*/
        while(cin >> a >> b) {
            if(a == 0 && b == 0) break;
            if(Ans[a][b] != "") {
                cout << Ans[a][b] << endl;
            }
            else {
                printf("-\n");
            }
        }
        printf("\n");
    }
}

