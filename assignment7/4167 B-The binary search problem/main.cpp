#include <iostream>
using namespace std;
long long num[100861];
int main()
{
    int T;
    cin>>T;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        if(!b) {
        	cout<<"0"<<endl;
        	continue;
        }
        int m=c/b;
        if(!m) {
        	cout<<"-1"<<endl;
        	continue;
        }
        ++m;
        int ct=m;
        int sum=1;
        while(m<a) {
        	m*=ct;
        	++sum;
        }
        cout<<sum<<endl;
    }
    return 0;