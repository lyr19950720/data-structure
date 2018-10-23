#include<iostream>
using namespace std;
int main(){
	int n,T,a[21];
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		//i=0;
		while(n>0){
			for(int i=0;i<n-1;i++){
				a[i]=a[i+1]-a[i];
			}
			n--;
		}
		cout<<a[0]<<endl;
	}
	return 0;
}

