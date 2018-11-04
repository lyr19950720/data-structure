#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#define N 201
using namespace std;
struct node {
    int x,y,z;
};
bool s[N][N][N];
int vis[N][N][N];
int maxx,maxy,maxz;
int g[6][3] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};
bool inmap(int x,int y,int z) {
    if(s[x][y][z]) return false;
    if(x < 0 || x > maxx + 1) return false;
    if(y < 0 || y > maxy + 1) return false;
    if(z < 0 || z > maxz + 1) return false;
    return true;
}
void BFS(node S,int n) {
    queue <node> q;
    node A,B;
    q.push(S);
    vis[S.x][S.y][S.z] = n;
    while(!q.empty()) {
        A = q.front();
        q.pop();
        for(int i = 0; i < 6; i++) {
            B.x = A.x + g[i][0];
            B.y = A.y + g[i][1];
            B.z = A.z + g[i][2];
            if(inmap(B.x,B.y,B.z) && vis[B.x][B.y][B.z] == 0) {
                q.push(B);
                vis[B.x][B.y][B.z] = n;
            }
        }
    }
}
int main() {
    int cas,n,a,b,c;
    cin >> cas;
    while(cas--) {
        cin >> n;
        memset(vis,0,sizeof(vis));
        memset(s,0,sizeof(s));
        maxx = 0;
        maxy = 0;
        maxz = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d %d %d",&a,&b,&c);
            s[a][b][c] = 1;
            maxx = max(maxx,a);
            maxy = max(maxy,b);
            maxz = max(maxz,c);
        }
        int ans = 0;
        node S;
        S.x = 0;
        S.y = 0;
        S.z = 0;
        int n = 0;
        BFS(S,++n);
        for(int i = 1; i <= maxx; i++) {
            for(int j = 1; j <= maxy; j++) {
                for(int k = 1; k <= maxz; k++) {
                    if(!s[i][j][k] && vis[i][j][k] == 0) {
                        S.x = i;
                        S.y = j;
                        S.z = k;
                        BFS(S,++n);
                    }
                }
            }
        }
        printf("%d\n",n-1);
    }
}
