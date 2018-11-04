/*#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
string common(string str1,string str2)
{
	string same="";
	
	for(int i=0;i<str1.size();i++)
		for(int j=0;j<str2.size();j++)
		{
			if(str1[i]==str2[j])
                 same=same+str1[i];
		}
		return same;

}
int main()
{
	int start,end,n;string company=" ";
	while(cin>>n&&n!=0)
	{
		string a[205][205];
		meset(a,0,sizeof(a));
		while(1){
			cin>>start>>end;
			if(start!=0&&end!=0)
			{
				cin>>company;
		        a[start-1][end-1]=company;

			}
			else
		    	break;
		}
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
				{	
				   string s=common(a[i][j],a[j][k]);
                   if(s!=" ")
					  a[i][k]+=s;	
				}

		//按字典输出输出互联的公司
		while(cin>>start>>end&&start!=0&&end!=0)
		{
			if(a[start-1][end-1]!=0)
			{
				string temp=a[start-1][end-1];
				sort(temp.begin(),temp.end());
				cout<<temp<<endl;
					
			}
			  
			else
				cout<<"-"<<endl;
		}
	
	}
	return 0;
}*/

#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	int start,end,n;string company=" ";
	while(cin>>n&&n!=0)
	{
		
		int a[205][205];
		memset(a,0,sizeof(a));
		while(1){
			cin>>start>>end;
			if(start!=0&&end!=0)
			{
				cin>>company;
				int i=0;
				while(company[i])
			      a[start-1][end-1] |=1<<(company[i++]-'a');//先1左移，然后和a做或，最后赋值给a
				//cout << a[start-1][end-1] << endl;

			}
			else
		    	break;
		}
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
				{	
					if(a[j][i]&a[i][k])//&逐位与
						 a[j][k]|=a[j][i]&a[i][k];   
				}

		//按字典输出输出互联的公司
		while(cin>>start>>end&&start!=0&&end!=0)
		{
			if(a[start-1][end-1]!=0)
			{
				int i=0,temp=a[start-1][end-1];
				while(temp)
				{
					if(temp&1)
				    	putchar(i+'a');
					temp>>=1;
					i++;
				}
			  cout<<endl;
			}	  
			else
				cout<<"-"<<endl;
		}
	cout<<endl;
	}

	return 0;
}