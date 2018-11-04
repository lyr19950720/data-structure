/*#include<stdio.h>
#include<iostream>
using namespace std;
int T,N;
bool isPrime(int b)        //确定一个数是素数
{
    for(int j=2;j<=b/2;j++)
    {
        if(b%j==0)
        return false;
    }
    return true;
}
int find(int N)
{
    int r =1;
    if(N==1)
       return 1;
    else if(isPrime(N))
       return N;
    else
    {
        for(int i=2;i<=N;)
        {
            if(N%i==0&&isPrime(i))//判断i是不是N的素因子
            {
                N/=i;
                r *= i;
                i++;
            }
             else
				 i++;
        }
	
        return r;//返回所有素因子的乘积
    }
}
 
int main()
{
   cin>>T; //T代表测试数据
   while(T--)
   {
      cin>>N;
      cout<<N/find(N)+1<<endl;
   }
   return 0;
}*/
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;
        int a = 2;
        int primes = 1;
        int n = N;
        int isfirst = true;
        while(a*a <= n)
        {
            if(n%(a*a)==0)
            {
                n/=(a*a);
                if(isfirst)
                {
                    primes*=a;
                    isfirst = false;
                }
            }
            else if(n%a==0)
            {
                n/=a;
                if(isfirst)
                {
                    primes*=a;
                }
                isfirst = true;
                a++;
            }
            else
            {
                a++;
                isfirst = true;
            }
            //cout << a << " " << n <<endl;
        }
        if(primes%n!=0)
            primes*=n;
        cout << N/primes + 1 <<endl;
    }
}