#include<stdio.h>
#include <iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{    
    
  char m[74];//m��ʾ����������ĸ����
  char t[74];//t��ʾ�滻���ַ���
  char text[74];//����ļ����ı�
  gets(m);    //��������ַ���m���滻�ַ���t
  gets(t);
  cout<<t<<endl;//����t��m�����˳��
  cout<<m<<endl;
  int n1,n2;
while(gets(text))
{
	for( n1=0;n1<strlen(text);n1++)
	{
		//�������в�����textֵ��ͬ���ַ��������滻���
		for(n2=0;n2<strlen(m);n2++)
		{
			if(text[n1]==m[n2])
			{
               text[n1]==t[n2];
			   cout<<t[n2];
			   break;
			}

		}
		//Ϊ�˱�֤�滻����ַ������������ʱ�ĸ�ʽһ��
		if(n2==strlen(m))
		   cout<<text[n1];		
	}
	cout<<endl;
}

 return 0;
}




	
     	
