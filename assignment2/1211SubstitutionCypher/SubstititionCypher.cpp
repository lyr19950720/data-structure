#include<stdio.h>
#include <iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{    
    
  char m[74];//m表示包含明文字母的行
  char t[74];//t表示替换的字符串
  char text[74];//输入的几行文本
  gets(m);    //获得明文字符串m和替换字符串t
  gets(t);
  cout<<t<<endl;//更换t和m的输出顺序
  cout<<m<<endl;
  int n1,n2;
while(gets(text))
{
	for( n1=0;n1<strlen(text);n1++)
	{
		//在名文中查找与text值相同的字符，进行替换输出
		for(n2=0;n2<strlen(m);n2++)
		{
			if(text[n1]==m[n2])
			{
               text[n1]==t[n2];
			   cout<<t[n2];
			   break;
			}

		}
		//为了保证替换后的字符串输出与输入时的格式一致
		if(n2==strlen(m))
		   cout<<text[n1];		
	}
	cout<<endl;
}

 return 0;
}




	
     	
