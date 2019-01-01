#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
    int n,i,j;
    int num[55];
    while(cin >> n && n)
    {
        for( i=0,j=0;i<n;i++,j++)
        {
            string number;

            cin >> number;
            int len = number.size();
            int a[len];
            for(j=0;j<len;j++)
                   a[j] = number[j] - '0';
            sort(a,a+len);
             char str[len];
            for(j=0;j<len;j++)
                {
                    str[j] = a[j]+'0';
                }
            int t;
            sscanf(str,"%d",&t);
            num[i]=t;
        }
        sort(num,num+n);
        cout << num[n-1] << endl;
    }

    return 0;
}
