/*#include <iostream>

using namespace std;
#define MAX 1000003
int map[3][MAX];
int fmax(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
   int T,N,i,j;
   cin>>T;
   while(T--)
   {
     cin>>N;
     for(i=1;i<=2;i++ )
     {
       for(j=1;j<=N;j++)
           cin>>map[i][j];
     }
     for(j=N-1;j>=1;j--)
            for(i=2;i>=1;i--)
            {
                if(i==1)
                    map[1][j]=fmax(map[2][j+1],map[1][j+1]+map[1][j]);
                if(i==2)
                    map[2][j]=fmax(map[1][j+1],map[2][j+1]+map[2][j]);
            }
    cout<<fmax(map[1][1],map[2][1])<<endl;
   }
    return 0;
}
int main()
{
   int T,N,i,j;
   cin>>T;
   while(T--)
   {
     cin>>N;
     for(i=1;i<=2;i++ )
     {
       for(j=1;j<=N;j++)
           cin>>map[i][j];
     }

     for(j=1;j<=N-1;j++)
            for(i=1;i<=2;i++)
            {
                if(i==1)
                   map[1][j+1]=map[2][j]>map[1][j+1]+map[1][j]?map[2][j]:map[1][j+1]+map[1][j];
                if(i==2)
                    map[2][j+1]=map[1][j]>map[2][j+1]+map[2][j]?map[1][j]:map[2][j+1]+map[2][j];
            }
          cout<<(map[1][N]>map[2][N]?map[1][N]:map[2][N])<<endl;
   }
    return 0;
}*/



