#include <iostream>
#include <cstring>
using namespace std;

int out[101];
int topu(int a[101][101],int indu[],int n)
{
    int cnt= 0;

    for(int i = 1;i <= n;i ++ )
    {
        for(int j = 1;j <= n;j ++)
        {
            if(indu[j]==0)
            {
                out[cnt++]=j;
                indu[j]--;
                for(int k = 1;k <= n; k ++)
                {
                    if(a[j][k]!=0)
                    {
                        a[j][k] = 0;
                        indu[k]--;
                    }

                }
                break;
            }
        }
    }
    return cnt;
}
int main()
{
    int t,n,m,i,j;
    cin>>t;
    while(t--)
    {
        int a[101][101],indu[101];
        cin >> n >> m;//n个人M个条件
        for( i = 1; i <= n; i ++)
        {
            for(j = 1; j <= n; j ++)
                a[i][j] = 0;
        }
        memset(indu,0,sizeof(indu));
        while(m--)
        {
            cin >> i >> j;
            if(!a[i][j])
            {
                a[i][j] = 1;
                indu[j]++;
            }

        }
        int cnt = topu(a,indu,n);
        if(cnt < n-1)
            cout << "Low IQ" << endl;
        else
        {
            for(i = 0; i < n; i++ )
        {
            if(i < n - 1)
              cout << out[i] << " ";
            else
              cout << out[i] << " " << endl;
        }
        }

    }
    return 0;
}
