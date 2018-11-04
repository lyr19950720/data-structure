#include<stdio.h>
#include <iostream>
#include<string>
#include<cstring>
using namespace std;
int leftmove(char mge[],int len)
{
    char temp=mge[0];
    for(int i=0;i<len;i++)
    {
        mge[i]=mge[i+1];
    }
    mge[len-1]=temp;
    return 0;
}
int rightmove(char mge[],int len)
{
    char temp=mge[len-1];
    for(int i=len-2;i>=0;i--)
    {
        mge[i+1]=mge[i];
    }
    mge[0]=temp;
    return 0;
}
int exchange(char mge[],int len)
{
    int m,j;char temp;
    if(len%2==0)
    {
        for(m=0,j=len/2;m<len/2,j<len;j++,m++)
        {
            temp=mge[m];
            mge[m]=mge[j];
            mge[j]=temp;
            
        }
    }else
    {
        for(m=0,j=len/2+1;m<len/2,j<len;j++,m++)
        {
            temp=mge[m];
            mge[m]=mge[j];
            mge[j]=temp;
            
        }
    }
    //puts(mge);
    return 0;
}
int reverse(char mge[],int len)
{
    int m,j;char temp;
    for(m=0,j=len-1;m<=len/2,j>=len/2;j--,m++)
    {
        temp=mge[m];
        mge[m]=mge[j];
        mge[j]=temp;
        
    }
    return 0;
}
int add(char mge[],int len)
{
    for(int i=0;i<len;i++)
    {
        if(mge[i]>='0'&&mge[i]<'9')
            mge[i]=mge[i]+1;
        else {
            if(mge[i]=='9')
                mge[i]='0';
        }
    }
    return 0;
}
int sub(char mge[],int len)
{
    for(int i=0;i<len;i++)
    {
        if(mge[i]>'0'&&mge[i]<='9')
            mge[i]=mge[i]-1;
        else {
            if(mge[i]=='0')
                mge[i]='9';
        }
    }
    return 0;
}
int main()
{
    int n;cin>>n;
    getchar();
    while(n--)
    {
        char mer[26],mge[30];
        gets(mer);gets(mge);int len2=strlen(mge);
        //len1表示信息者的数目，len2表示数据集的个数
        int i=0,len1=strlen(mer);
        for(i=len1-1;i>=0;i--)
        {
            switch(mer[i])
            {
                case 'J': rightmove(mge,len2);break;			 
                case 'C': leftmove(mge,len2);break;
                case 'E': exchange(mge,len2);break;
                case 'A': reverse(mge,len2);break;
                case 'P': sub(mge,len2);break;
                case 'M': add(mge,len2);break;
                default:break;
            }
            
        }
        puts(mge);
    }
    
    return 0;
}