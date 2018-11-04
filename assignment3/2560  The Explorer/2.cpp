#include <queue>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int s[201][201];
int g[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int dis[201][201];
int n,m;
struct node {
    int x,y,dis;
};
bool judge(node S) {
    if(S.x >= n || S.x < 0) return false;
    if(S.y >= m || S.y < 0) return false;
    if(s[S.x][S.y] == 1) return false;
    return true;
}
int BFS(node S,node T) {
    queue <node> q;
    node A,B;
    q.push(S);
    memset(dis,0x7f,sizeof(dis));
    dis[S.x][S.y] = 1;
    while( !q.empty() ) {
        A = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            B.x = A.x + g[i][0];
            B.y = A.y + g[i][1];
            B.dis = A.dis + 1;
            if( judge(B) && B.dis < dis[B.x][B.y]) {
                q.push(B);
                dis[B.x][B.y] = B.dis;
            }
        }
    }
    return dis[T.x][T.y];
}
int main() {
    int cas;
    scanf("%d",&cas);
    while(cas--) {
        scanf("%d %d",&m,&n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m ;j++)
                scanf("%d",&s[i][j]);
        }
        node S,T;
        scanf("%d %d",&S.y,&S.x);
        scanf("%d %d",&T.y,&T.x);
        S.dis = 1;
        printf( "%d\n",BFS(S,T) );
    }
}
