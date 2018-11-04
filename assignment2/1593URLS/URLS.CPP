# include <iostream>
# include <string>
# include <iomanip>
using namespace std;
int k, i;
void operation(string s)
{
		
	string result;	result="";	
	for(i=0; i<=s.length()-1; i++)
	{	
		if(s[i]!=':')		
			result=result+s[i];	//把属于Protocol的字符连接起来	
		else
		{		
			cout<<"Protocol "<<"= "<<result<<endl;	//按格式输出Protocol的结果				
			break;	
		}
	}

	//浏览: /,寻找Host的起始地址
	while(s[i]==':'||s[i]=='/')	
		i++;	
	
	
	result="";//将表示结果的字符串重新置空
	for(k=i; k<=s.length()-1; k++)
	{		
		if(s[k]!=':'&&s[k]!='/')//判断Host结束的条件	
			result=result+s[k];	//把属于Host的字符连接起来	
		else						
			  break;	
			
	}
	cout<<"Host     "<<"= "<<result<<endl;	


	if(k==s.length())//如果属于Host的部分读取完毕，而且字符串也读完了，就按照格式将Port,Path输出为默认值
	{		
		cout<<"Port     "<<"= "<<"<default>"<<endl;		
		cout<<"Path     "<<"= "<<"<default>"<<endl;		
		
	}	
	else//表示该url存在Port
	{	
		if(s[k]==':')
		{			
			result="";			
			for(i=k+1; i<=s.length()-1; i++)//Port字符串的起始地址K+1，当遇到/时Port读取结束
			{				
				if(s[i]!='/')					
					result=result+s[i];							
				else					
					break;				
						
			}
			cout<<"Port     "<<"= "<<result<<endl;
			

			if(i==s.length())//表示字符串读完了，没有Path,输出默认		
				cout<<"Path     "<<"= "<<"<default>"<<endl;	
			
			else    
			{				
				result="";		             	//表示存在Path,result置空	
				for(k=i+1; k<=s.length()-1; k++)
				{					
					result=result+s[k];				
				}			
				cout<<"Path     "<<"= "<<result<<endl;			
						
			}	
		}	
		else{			
			cout<<"Port     "<<"= "<<"<default>"<<endl;	
		//	cout<<i<<k;
				if(i==s.length())//表示字符串读完了，没有Path,输出默认		
			    	cout<<"Path     "<<"= "<<"<default>"<<endl;	
		    	else    
				{			
					result="";			
		   	      for(i=k+1; i<=s.length()-1; i++)//Port字符串的起始地址K+1，当遇到/时Port读取结束
				  {											
					result=result+s[i];													
				  }
				cout<<"Path     "<<"= "<<result<<endl;			
						
			}	
		}
				
	}
}




int main()
{
	int n, m;//n表示输入多少行,m是表示第几行，用来计数
    string s;
	cin>>n;	m=0;	
	while(n--){	
		m++;		
		cin>>s;	
		cout<<"URL #"<<m<<endl;		
		operation(s);	
		cout<<endl;
	} 	
	return 0;
}



