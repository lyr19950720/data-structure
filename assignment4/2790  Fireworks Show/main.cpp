#include <iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
int Time[2000005];//ʱ����
int main()
{
    //C �̻���ĿN ��ʱ�� count ͳ�ƽ�� Can���ÿ���̻�ÿ���೤ʱ���
    //j �������������
    int i,j=1,C,N,count=0,Can[101];
    cin>>C>>N;
    memset(Time,0,N*sizeof(int));
    for( i=0;i<C;i++)
    {
        cin>>Can[i];
        while(Can[i]*j<=N) //��Cn[i]�ı���λ����1
        {
             Time[Can[i]*j]=1;
             j++;
        }
       j=1;
    }
    for(i=0;i<=N;i++) //ͳ��������1������
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
