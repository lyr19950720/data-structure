#include <stdio.h>
#include<iostream>
#include <string.h>
#include <algorithm>
using namespace std; 
char s[10005]; 
int main()
{    
	int n; //��λ����   
	while(cin>>n&&n!=0)    
	{        
		int l=0,i,j,flag;     //l������ʧ����   
		cin>>s;               
		char z[25];//Z�������λ�Ƿ�����       
		memset(z,' ',sizeof(z));        
		for(i=0; i<strlen(s); i++)       
		{            
			flag=0;//flag=0��ʾ��ĳ�˽�������뿪            
			for(j=1; j<=n; j++) //�ж���λ����û�е�i���ַ����ϵ���                
				if(z[j]==s[i])      //�����λ�����ַ����ϵ��ˣ����������Ҫ�뿪������λ���          
				{                   
					z[j]=' ';                   
					flag=1; 
				
					break;                
				}            
			if(flag==0)                
				for(j=1; j<=n; j++) //�п�λ�þ��ù˿ͽ�ȥ                   
					if(z[j]==' ')                    
					{                       
						z[j]=s[i];                        
						break;                   
					}            
			if(j>n)//û�п�λ����ʧ������һ               
				l++;  
			

		}        
		if(l==0)           
			cout<<"All customers tanned successfully."<<endl;        
		else           
			cout<<l/2<<" customer(s) walked away."<<endl;   
 }   
	return 0;
}
