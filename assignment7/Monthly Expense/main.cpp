#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,a[100005];
bool judge(int num)
{
    int sum=0,c=1;
    for(int i=0;i<n;i++)
    {
        sum +=a[i];
        if(sum>num)
        {
            sum = a[i];
            c++;
        }
    }
    if(c>m) return false;
    return true;
}
int main()
{
    int maxn=0,value=0;
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            maxn=max(maxn,a[i]);
            value+=a[i];
        }//用二分查找找最小值
        int low=maxn,mid,high=value;
        while(low<high)
        {
            mid=(low+high)/2;
            if(judge(mid)) high = mid;
            else low = mid + 1;
        }
      cout << low << endl;
    }
    return 0;
}
