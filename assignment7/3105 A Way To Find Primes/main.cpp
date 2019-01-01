#include<stdio.h>
#include<math.h>
#include <iostream>
using namespace std;
const int MAXN = 1000005;
int a[MAXN];
int prim[MAXN];
int i,j,k;
bool isprime(int a)
{
    for(int i=2;i<=sqrt(a);i++)
    if(a%i==0) return false;
    return true;
}
int main()
{
     int c,n;
     for(i=1;i<=MAXN;i++)
           a[i]=i;
     a[1]=0;
     for(i=2;i<=MAXN;i++)
     {
        if(isprime(a[i]))
            prim[k++] = a[i];

     }
     cin>>c;
     while(c--)
     {
         cin >> n;
        if(n == 1)
            cout << "2" << endl;
        else
            cout << prim[n-1] << endl;
    }
    return 0;
}
