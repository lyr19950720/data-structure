#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,a[101];
    while(cin >> n)
    {
        for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a,a+n);
    for(int j=0; j<n-1;j++)
        cout << a[j] << " ";
    cout << a[n-1] <<endl;
    }

    return 0;
}
