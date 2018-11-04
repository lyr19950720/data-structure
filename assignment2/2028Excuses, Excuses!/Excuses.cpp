#include<stdio.h>
#include<string.h>
#include<iostream>
#include<ctype.h>
using namespace std;
int main (){
	int k,e,d = 0;//k:关键字个数，e:借口条数，d:输出#d
	char t[100];//临时数组
	char key[21][21];
    char exc[21][101];
	while(scanf("%d %d",&k,&e) != EOF){
		d++;
		getchar();
		int sum[100]={0};//用来存储每个借口包含的关键字的个数
    	int i,j,bad=0;
		//循环输入关键词
		for(i = 0;i < k;i++)
			gets(key[i]);
		
		for(i = 0;i < e;i++){
			//获得借口
			gets(exc[i]);
			j=0;
			while(j < strlen(exc[i]))
			{
			   int 	m = 0;
			   //将借口转存到临时数组t中
				while(isalpha( exc[i][j] ))
				{
					if(isupper( exc[i][j] ))
						t[m++] = tolower( exc[i][j] );
					else
						t[m++] = exc[i][j];
					j++;
				}
				t[m] = '\0';//转存结束 
				for(int c = 0;c < k;c++)
				{
					if(strcmp(t,key[c]) == 0)//在字符串t中寻找子字符串key
						sum[i] ++;
				}
				if(sum[i]>bad)  //判断如果字符串包含的关键字个数大于bad,则赋值于bad
				{
					bad = sum[i];
				}
					
					j++;
			}
			
		}
		cout<<"Excuse Set #"<<d<<endl;

		for(i = 0;i < e;i++)
		{
			if(bad == sum[i])
			{
				puts(exc[i]);
			}
		}
		cout<<endl;
	}
	return 0;
}
 
	