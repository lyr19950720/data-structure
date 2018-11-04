#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 20
using namespace std;
struct node{
    double x,y;
}s[N];
bool vis[N];
int fre[N];
vector <int> v[N];
int Ans,n;
double dis(node A, node B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
void dfs(int x,int num,int color) {
    int y;
    memset(vis,0,sizeof(vis));
    fre[x] = color;
    for(int i = 0; i < v[x].size(); i++) {
        y = v[x][i];
        if(fre[y] == fre[x]) {
            fre[x] = -1;
            return;
        }
    }
    for(int i = 0; i < v[x].size(); i++) {
        y = v[x][i];
        for(int j = 1; j <= num; j++) {
            if(fre[y] == -1 && j != color)
            dfs(y,num,j);
        }
    }
    return;
}
bool ok(int num) {
    memset(fre,-1,sizeof(fre));
    for(int i = 1; i <= n; i++) {
        if(fre[i] == -1)
        dfs(i,num,1);
    }
    for(int i = 1; i <= n; i++) {
        if(fre[i] == -1)
            return false;
    }
    return true;
}
int main() {
    int k = 0;
    while(cin >> n && n != 0) {
        for(int i = 1; i <= n; i++) {
            cin >> s[i].x >> s[i].y;
            v[i].clear();
        }
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if( dis(s[i],s[j]) <= 20.0 ) {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            if(ok(i)){
                printf("The towers in case %d can be covered in %d frequencies.\n",++k,i);
                break;
            }
        }
    }
}
