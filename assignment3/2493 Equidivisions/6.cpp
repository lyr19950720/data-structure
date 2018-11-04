#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define N 500
using namespace std;
int g[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n;
int s[N][N],vis[N][N];
struct node {
    int x,y;
};
bool inmap(node S) {
    if(S.x > n || S.x <= 0) return false;
    if(S.y > n || S.y <= 0) return false;
    return true;
}

void BFS(int x,int y,int num) {
    queue <node> q;
    node A,B;
    A.x = x;
    A.y = y;
    q.push(A);
    vis[x][y] = num;
    while( !q.empty() ) {
        A = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            B.x = A.x + g[i][0];
            B.y = A.y + g[i][1];
            if( inmap(B) && s[B.x][B.y] == s[A.x][A.y] && vis[B.x][B.y] == 0) {
                q.push(B);
                vis[B.x][B.y] = num;
            }
        }
    }
}
int main() {
    int a,b;
    while(cin >> n && n != 0) {
        memset(vis,0,sizeof(vis));
        memset(s,0,sizeof(s));
        for(int i = 1; i <= n - 1 ; i++) {
            for(int j = 1; j <= n ; j++){
                scanf("%d %d",&a,&b);
                s[a][b] = i;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++){
                if(s[i][j] == 0)
                s[i][j] = n;
            }
        }
        bool flag = false;
        int num = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(vis[i][j] == 0) {
                    BFS(i,j,++num);
                }
            }
        }
        if(num != n) {
            printf("wrong\n");
        }
        else printf("good\n");
    }
}
