#include<iostream>
using namespace std;
int main(){
int count;
	int n;
	cin>>n;
	while(n>0)
	{  count=0;
		int num;
		cin>>num;
		int number;
	while(num>0)
	{
		cin>>number;
    	if(number==1)
		count++;
		num--;
	}
	cout<<count<<endl;
	n--;
	}
	}