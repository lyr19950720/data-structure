#include<stdio.h>
#include<string.h>
#include<iostream>
#include<ctype.h>
using namespace std;
int main (){
	int k,e,d = 0;//k:�ؼ��ָ�����e:���������d:���#d
	char t[100];//��ʱ����
	char key[21][21];
    char exc[21][101];
	while(scanf("%d %d",&k,&e) != EOF){
		d++;
		getchar();
		int sum[100]={0};//�����洢ÿ����ڰ����Ĺؼ��ֵĸ���
    	int i,j,bad=0;
		//ѭ������ؼ���
		for(i = 0;i < k;i++)
			gets(key[i]);
		
		for(i = 0;i < e;i++){
			//��ý��
			gets(exc[i]);
			j=0;
			while(j < strlen(exc[i]))
			{
			   int 	m = 0;
			   //�����ת�浽��ʱ����t��
				while(isalpha( exc[i][j] ))
				{
					if(isupper( exc[i][j] ))
						t[m++] = tolower( exc[i][j] );
					else
						t[m++] = exc[i][j];
					j++;
				}
				t[m] = '\0';//ת����� 
				for(int c = 0;c < k;c++)
				{
					if(strcmp(t,key[c]) == 0)//���ַ���t��Ѱ�����ַ���key
						sum[i] ++;
				}
				if(sum[i]>bad)  //�ж�����ַ��������Ĺؼ��ָ�������bad,��ֵ��bad
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
 
	