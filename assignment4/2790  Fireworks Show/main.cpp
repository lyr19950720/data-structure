#include <iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
int Time[2000005];//时间轴
int main()
{
    //C 烟花数目N 总时间 count 统计结果 Can存放每个烟花每隔多长时间放
    //j 代表递增是数字
    int i,j=1,C,N,count=0,Can[101];
    cin>>C>>N;
    memset(Time,0,N*sizeof(int));
    for( i=0;i<C;i++)
    {
        cin>>Can[i];
        while(Can[i]*j<=N) //将Cn[i]的倍数位置置1
        {
             Time[Can[i]*j]=1;
             j++;
        }
       j=1;
    }
    for(i=0;i<=N;i++) //统计数组中1个个数
        if(Time[i]==1)
            count++;
      cout<<count<<endl;

    return 0;
}

/*int main()
{
    int i,C,N,Can[101],result=0;
    cin>>C>>N;
    for( i=0;i<C;i++)
        cin>>Can[i];

   // cout<<Can[C-1]<<endl;

        for(int j=2;j<=N;j++)
        {   int count=0;
            for(i=0;i<C;i++)
           {
             if(j%Can[i]==0)
             {
                 count++;
              if(count==1)
                result++;
             }
       }
    }
    cout << result << endl;
    return 0;
}*/
