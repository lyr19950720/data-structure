#include <iostream>
#include<cmath>
#include<string.h>
using namespace std;
int cow[11],visit[11],que[11];
int N,K, count=0;
void dfs(int n)
{
    if(n==N)
    {
        count++;
        return ;
    }

    else{
        for(int i=0;i<N;i++)
        {
            if(abs(que[n-1]-cow[i])<=K&&visit[i]==0)
            {
                if(n==N-1&&abs(que[0]-cow[i])>K)
                    continue;
                que[n]=cow[i];
                visit[i]=1;
              dfs(n+1);
              visit[i]=0;
            }
        }
    }


}
int main()
{

    cin>>N>>K;;
    memset(visit,0,N*sizeof(int));
    for(int i=0;i<N;i++)
      cin>>cow[i];
    que[0]=cow[0];
    visit[0]=1;
    dfs(1);
     cout<<count<<endl;
    return 0;
}
/*#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int h[15],pos[15];
	int N, K;//the number of cows,the difference of height
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> h[i];
		pos[i] = i;
	}
	int num = 0;//the number of ways
	int cnt=0;
		do{
                cnt++;
			bool flag = true;
			for (int i = 0; i< N-1&&flag; i++) {
				if (abs(h[pos[i + 1]] - h[pos[i]]) > K) flag = false;
			}
			if (abs(h[pos[0]] - h[pos[N - 1]]) > K) flag = false;
			if (flag) num++;
		} while (next_permutation(pos + 1, pos + N ));//固定第一个位置
		cout << num << cnt << endl;
	return 0;
}*/