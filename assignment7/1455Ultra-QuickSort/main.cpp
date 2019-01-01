/*#include <iostream>
using namespace std;
int main()
{
    int n,a[500005],i,j;
    while(cin>>n&&n)
    {
        int cnt=0;
        for(i=0; i<n;i++)
            cin>>a[i];
       for( i= 0; i < n-1; i++)
	  {
		int tmp = 0;
		for ( j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j+1])
			{
				tmp = a[j+1];
				a[j+1] = a[j];
				a[j] = tmp;
				cnt++;
			}
		}
	}
            cout << cnt << endl;
        }

    return 0;
}*/
/*#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
int main(){

   int arr[500005],n;
   while(cin>>n&&n)
   {
       int start=0;//作为开始的索引
       int end=n-1;//作为结束的索引
       int cnt=0;
       for(int j=0; j<n;j++)
            cin>>arr[j];
       while(end-start>=1){
        //当开始的索引与结束的索引不重合的时候执行操作
        for(int i=start;i<end;i++){
            if(arr[i+1]<arr[i]){
                int temp=arr[i+1];
                  arr[i+1]=arr[i];
                  arr[i]=temp;
                     cnt++;

            }//这一次循环找出6个数中的最大数

        }
        end--;
        for(int k=end;k>start;k++){
             if(arr[k]<arr[k-1]){
                 int temp=arr[k-1];
                  arr[k-1]=arr[k];
                  arr[k]=temp;
                  cnt++;

            }
        }//这一次循环找出5个数中的最小数
        start++;
    }
       cout << cnt << endl;
   }

    return 0;
}*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500050],r[500050],ans;
void msort(int s,int t)
{
    if(s==t) return;
    int mid=(s+t)/2;
    msort(s,mid);
    msort(mid+1,t);
    int i=s,j=mid+1,k=s;
    while(i<=mid&&j<=t)
    {
        if(a[i]<a[j])
        {
            r[k]=a[i];
            k++;
            i++;
        }
        else
        {
            r[k]=a[j];
            k++;
            j++;
            ans+=mid-i+1;
        }
    }
    while(i<=mid)
    {
        r[k]=a[i];
        k++;
        i++;
    }
    while(j<=t)
    {
        r[k]=a[j];
        k++;
        j++;
    }
    for(int i=s; i<=t; i++)
        a[i]=r[i];
}
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
        {
            return 0;
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        msort(1,n);
        printf("%lld\n",ans);
    }
    return 0;

}

