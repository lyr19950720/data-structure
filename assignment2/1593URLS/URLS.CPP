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
			result=result+s[i];	//������Protocol���ַ���������	
		else
		{		
			cout<<"Protocol "<<"= "<<result<<endl;	//����ʽ���Protocol�Ľ��				
			break;	
		}
	}

	//���: /,Ѱ��Host����ʼ��ַ
	while(s[i]==':'||s[i]=='/')	
		i++;	
	
	
	result="";//����ʾ������ַ��������ÿ�
	for(k=i; k<=s.length()-1; k++)
	{		
		if(s[k]!=':'&&s[k]!='/')//�ж�Host����������	
			result=result+s[k];	//������Host���ַ���������	
		else						
			  break;	
			
	}
	cout<<"Host     "<<"= "<<result<<endl;	


	if(k==s.length())//�������Host�Ĳ��ֶ�ȡ��ϣ������ַ���Ҳ�����ˣ��Ͱ��ո�ʽ��Port,Path���ΪĬ��ֵ
	{		
		cout<<"Port     "<<"= "<<"<default>"<<endl;		
		cout<<"Path     "<<"= "<<"<default>"<<endl;		
		
	}	
	else//��ʾ��url����Port
	{	
		if(s[k]==':')
		{			
			result="";			
			for(i=k+1; i<=s.length()-1; i++)//Port�ַ�������ʼ��ַK+1��������/ʱPort��ȡ����
			{				
				if(s[i]!='/')					
					result=result+s[i];							
				else					
					break;				
						
			}
			cout<<"Port     "<<"= "<<result<<endl;
			

			if(i==s.length())//��ʾ�ַ��������ˣ�û��Path,���Ĭ��		
				cout<<"Path     "<<"= "<<"<default>"<<endl;	
			
			else    
			{				
				result="";		             	//��ʾ����Path,result�ÿ�	
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
				if(i==s.length())//��ʾ�ַ��������ˣ�û��Path,���Ĭ��		
			    	cout<<"Path     "<<"= "<<"<default>"<<endl;	
		    	else    
				{			
					result="";			
		   	      for(i=k+1; i<=s.length()-1; i++)//Port�ַ�������ʼ��ַK+1��������/ʱPort��ȡ����
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
	int n, m;//n��ʾ���������,m�Ǳ�ʾ�ڼ��У���������
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


