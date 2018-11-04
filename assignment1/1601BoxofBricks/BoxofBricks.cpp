#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int count=0;
	while(n!=0)
	{	int sum=0;
	    
		if(n>=1&&n<=50)
		{	int minumum=0;
			int *hi=new int[n];
		    int average=0;
			for(int i=0;i<n;i++)
			{  cin>>hi[i];
		    if(hi[i]>=1&&hi[i]<=100)
			    sum=sum+hi[i];
			else 
				return 0;
			}
            average=sum/n;

			for(int j=0;j<n;j++)
			{
				if(hi[j]>average)	
				minumum=minumum+(hi[j]-average);
			}
          
			count++;
		    cout<<"Set "<<"#"<<count<<endl;
			cout<<"The minimum number of moves is "<<minumum<<"."<<endl;
		}
		   
			cin>>n;
			cout<<endl;
	}
	return 0;
}