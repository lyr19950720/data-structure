#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
char Map[1005][1005];
int main()
{
    int N,M,area;
    int countone[1005],temp[1005];
    while(cin >> N >> M)
    {
        area =0;
        memset(countone,0,sizeof(countone));
        memset(temp,0,sizeof(temp));
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                cin >> Map[i][j];
                if(Map[i][j] == '1')
                   countone[j]++;
                else
                    countone[j]=0;
                temp[j] = countone[j];
            }
            sort(temp+1,temp+1+M,cmp);
            for(int k=1; k<=M; k++)
                area=max(temp[k]*k,area);

        }
        cout << area << endl;
    }
    return 0;
}
