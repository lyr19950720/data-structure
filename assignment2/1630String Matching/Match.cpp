#include<stdio.h>
 #include<string.h>
#include<iostream>
using namespace std;
char str1[1005],str2[1005];
int common(int a, int b)
{
	int c = a % b;
	if (c == 0)
		return b;
	return common(b, c);
}
 int main()
  {
	  //i��j�ַ������±꣬k�����ַ���������
	  //n�����ַ���������ƥ����ַ���
     int i,j,k,n,max;
     while(1)
     {
		  cin>>str1>>str2;
         if(strcmp(str1,"-1")==0)break;
		   max=0;               //�ַ���ƥ�������ַ���
         int len1=strlen(str1);
         int len2=strlen(str2);
		 //��str2��str1����ƥ��
         for(k=0;k<len1;k++)
         {   
			 n=0;   
             for(i=k,j=0;i<len1 && j<len2;i++,j++)
			 {
				if(str1[i]==str2[j])
					 n++;
			 }      
             if(max<n) 
				 max=n;
            
        }
        //��str1��str2����ƥ��
         for(k=0;k<len2;k++)
         {
             n=0;
             for(i=k,j=0;i<len2 && j<len1;i++,j++)
			 {
				 if(str2[i]==str1[j])
					 n++;
			 }     
             if(max<n) 
				 max=n;  
         }
         //����������
        cout<<"appx("<<str1<<","<<str2<<") = ";
        int num1=max*2;    //��������
		int num2=len1+len2;//��ĸ����
		if(num1== num2) 
			 cout<<"1"<<endl;
		else if(num1==0) 
			  cout<<"0"<<endl;
	    else
			cout<<num1/ common(num1,num2)<<"/"<<num2/ common(num1,num2)<<endl;
			 
     }
     return 0;
 }