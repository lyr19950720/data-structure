#include<iostream>
using namespace std;
int main(){
      int t;
	  cin>>t;
	  while(t>0&&t<100)
	  {
          int n;
		  cin>>n;
		  if(n>0&&n<10)
		  {
			  int *vec1=new int[n];
			  int *vec2=new int[n];
     
			 int sum=0;
			 for(int i=0;i<n;i++)
			  cin>>vec1[i];
			 for(int j=0;j<n;j++)
		    	cin>>vec2[j];
			 for(int m=0;m<n;m++)
			 { 
				 sum=sum+vec1[m]*vec2[m];
				} 
			 cout<<sum<<endl;
		  }	  	 
       t--;
	  }
	return 0;
}