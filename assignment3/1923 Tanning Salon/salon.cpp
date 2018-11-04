#include <stdio.h>
#include<iostream>
#include <string.h>
#include <algorithm>
using namespace std; 
char s[10005]; 
int main()
{    
	int n; //座位个数   
	while(cin>>n&&n!=0)    
	{        
		int l=0,i,j,flag;     //l代表流失人数   
		cin>>s;               
		char z[25];//Z数组存座位是否有人       
		memset(z,' ',sizeof(z));        
		for(i=0; i<strlen(s); i++)       
		{            
			flag=0;//flag=0表示让某人进入或者离开            
			for(j=1; j<=n; j++) //判断座位上有没有第i个字符串上的人                
				if(z[j]==s[i])      //如果座位上有字符串上的人，代表这个人要离开，将座位清空          
				{                   
					z[j]=' ';                   
					flag=1; 
				
					break;                
				}            
			if(flag==0)                
				for(j=1; j<=n; j++) //有空位置就让顾客进去                   
					if(z[j]==' ')                    
					{                       
						z[j]=s[i];                        
						break;                   
					}            
			if(j>n)//没有空位置流失人数加一               
				l++;  
			

		}        
		if(l==0)           
			cout<<"All customers tanned successfully."<<endl;        
		else           
			cout<<l/2<<" customer(s) walked away."<<endl;   
 }   
	return 0;
}
