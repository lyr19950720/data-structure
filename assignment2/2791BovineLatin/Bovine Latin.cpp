#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
	string s=" aeiou";
    int n;
	cin>>n;
	getchar();
	if(n>=1&&n<=100)
	{
		while(n--)
	{
		string str;
		cin>>str;	
		int len=str.size();
		if(len>=3&&len<=40)
		{
			string::size_type idx=s.find(str[0]);
			if(idx!=string::npos)
			{
				cout<<str<<"cow"<<endl;
				 
			}else
			{
				char temp=str[0];
				for(int j=0;j<len;j++)
				{
					str[j]=str[j+1];
				}
				str[len-1]=temp;
				cout<<str<<"ow"<<endl;
			}
		}
		else
			return 0;	
	}
	}
	return 0;
}