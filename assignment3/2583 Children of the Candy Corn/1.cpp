#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#define N 202
using namespace std;
int n,m;
char s[N][N];
char ch[N];
int g[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
struct node {
    int x,y,dir,dist;
};
bool inmap(node A) {
    if(A.x < 0 || A.x >= n) return false;
    if(A.y < 0 || A.y >= m) return false;
    return true;
}
int LFS(node S) {
    queue<node>q;
    q.push(S);
    int dis = 1;
    node A,B;
    while(!q.empty()) {
        A = q.front();
        q.pop();
        if(inmap(A) && s[A.x][A.y] == 'E') return dis;
        int dir = A.dir;
        //printf("%d %d\n",A.x,A.y);
        B.x = A.x + g[(dir + 3) % 4][0];
        B.y = A.y + g[(dir + 3) % 4][1];
        if(inmap(B) && s[B.x][B.y] != '#') {
            B.dir = (dir + 3) % 4;
            q.push(B);
            dis++;
            continue;
        }
        B.x = A.x + g[dir][0];
        B.y = A.y + g[dir][1];
        if(inmap(B) && s[B.x][B.y] != '#') {
            B.dir = dir;
            q.push(B);
            dis++;
            continue;
        }
        B.x = A.x + g[(dir + 1) % 4][0];
        B.y = A.y + g[(dir + 1) % 4][1];
        if(inmap(B) && s[B.x][B.y] != '#') {
            B.dir = (dir + 1) % 4;
            q.push(B);
            dis++;
            continue;
        }
        B.x = A.x + g[(dir + 2) % 4][0];
        B.y = A.y + g[(dir + 2) % 4][1];
        if(inmap(B) && s[B.x][B.y] != '#') {
            B.dir = (dir + 2) % 4;
            q.push(B);
            dis++;
            continue;
        }

    }
    return -1;
}

int RFS(node S) {
    queue<node>q;
    q.push(S);
    int dis = 1;
    node A,B;
    while(!q.empty()) {
        A = q.front();
        q.pop();
        if(inmap(A) && s[A.x][A.y] == 'E') return dis;
        int dir = A.dir;
        //printf("%d %d\n",A.x,A.y);
        B.x = A.x + g[(dir + 1) % 4][0];
        B.y = A.y + g[(dir + 1) % 4][1];
        if(inmap(B) && s[B.x][B.y] != '#') {
            B.dir = (dir + 1) % 4;
            q.push(B);
            dis++;
            continue;
        }
        B.x = A.x + g[dir][0];
        B.y = A.y + g[dir][1];
        if(inmap(B) && s[B.x][B.y] != '#') {
            B.dir = dir;
            q.push(B);
            dis++;
            continue;
        }
        B.x = A.x + g[(dir + 3) % 4][0];
        B.y = A.y + g[(dir + 3) % 4][1];
        if(inmap(B) && s[B.x][B.y] != '#') {
            B.dir = (dir + 3) % 4;
            q.push(B);
            dis++;
            continue;
        }
        B.x = A.x + g[(dir + 2) % 4][0];
        B.y = A.y + g[(dir + 2) % 4][1];
        if(inmap(B) && s[B.x][B.y] != '#') {
            B.dir = (dir + 2) % 4;
            q.push(B);
            dis++;
            continue;
        }

    }
    return -1;
}

int BFS(node S,node T) {
    queue <node> q;
    node A,B;
    q.push(S);
    int dis[N][N];
    memset(dis,0x7f,sizeof(dis));
    dis[S.x][S.y] = 1;
    while( !q.empty() ) {
        A = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            B.x = A.x + g[i][0];
            B.y = A.y + g[i][1];
            B.dist = A.dist + 1;
            if( inmap(B) && s[B.x][B.y] != '#' && B.dist < dis[B.x][B.y]) {
                q.push(B);
                dis[B.x][B.y] = B.dist;
            }
        }
    }
    return dis[T.x][T.y];
}
int main() {
    int cas;
    cin >> cas;
    while(cas--) {
        scanf("%d %d",&m,&n);
        node S,T;
        getchar();
        for(int i = 0; i < n; i++) {
            gets(ch);
            for(int j = 0; j < m; j++) {
                s[i][j] = ch[j];
                if(s[i][j] == 'S') {
                    S.x = i;
                    S.y = j;
                    if(i == 0) {
                        S.dir = 2;
                    }
                    else if(j == 0) {
                        S.dir = 1;
                    }
                    else if(i == n - 1) {
                        S.dir = 0;
                    }
                    else if(j == m - 1) {
                        S.dir = 3;
                    }
                }
                if(s[i][j] == 'E') {
                    T.x = i;
                    T.y = j;
                }
            }
        }
        S.dist = 1;
        printf("%d %d %d\n",LFS(S),RFS(S),BFS(S,T));
    }
}
