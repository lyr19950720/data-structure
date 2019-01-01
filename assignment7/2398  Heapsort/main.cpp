#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int j,n,last,a[50005];
    while(cin >> n)
    {
        memset(a,0,sizeof(a));
        a[1] = 1;
        last = 1;
        for(int i=2; i<=n; i++)
        {
            j=last;
            while(j>1)
            {
               a[j] = a[j/2];
               j /= 2;
            }
            last++;
            a[last] = 1;
            a[1] = i;
        }
        for (int j=1; j<n; j++)
            cout << a[j] << " " ;
        cout << a[n] << endl;
    }
    return 0;
}
