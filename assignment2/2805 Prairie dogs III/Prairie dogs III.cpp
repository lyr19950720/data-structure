#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
char r[1005];
int op(int n)
{  
	   int len=(int) pow(3,n-1);   
		  if(n==0)	 
		  {
			  cout<<'@';
			  return 0;
		  }
		  else
		  {
			  op(n-1);
			for(int i=0;i<len;i++) 
			     cout<<" ";
			op(n-1);
		  }		  
	return 0;
}
int main()
{
	int n;
	while(cin>>n)
	{
		op(n);
	    cout<<r<<endl;
	}
	return 0;
}

