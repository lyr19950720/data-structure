#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
set<int> s;
int main()
{
    int M,N,i,j,num;
    while(cin>>M>>N)
    {
        for(i=0;i<M+N;i++)
    {
        cin>>num;
        s.insert(num);
    }

    cout<<(M+N)-s.size() <<endl;
    }


   // cout << cnt <<endl;
}
/*int cnt=0,A[4005],B[160005];
int f_search(int temp,int left,int right)
{
    int mid=(left+right)/2;
    if(temp == B[mid]) //cnt++;
        cout<<temp<<endl;
    if(temp > b[mid]) f_search(temp,mid+1,right);
    if(temp < b[mid]) f_search(temp,left,mid-1);
    return 0;
}
int main()
{
    int M,N,i,j;
    for(i=0;i<M;i++)
        cin>>A[i];
    for(j=0;j<N;j++)
        cin>>B[j];
    sort(B,B+N);
    for(i=0;i<M;i++)
        f_search(A[i],0,N-1);
   // cout << cnt <<endl;
}
*/
