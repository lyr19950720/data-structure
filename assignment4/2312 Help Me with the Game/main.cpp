#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include<string>
using namespace std;
int j;
//����ṹ�壬�������ӵ��������ĸ��
struct node
{
  int x;char y;
  char letter;
};
node wn[16];//��Ű���Ľڵ�
node bn[16];//��ź���Ľڵ�
char output[6]={'K','Q','R','B','N','P'};//�����˳��outout�����е�˳��
//wk����ĸ���bk����ĸ���wp������P�ĸ���bp������p�ĸ���
int  wk=0,bk=0,wp=0,bp=0;
//�к���ͬ���������壬��С���ȣ��кŲ�ͬ����С����
bool cmpw(node n1,node n2)
{
    if(n1.x==n2.x)
      return n1.y<n2.y;
   return n1.x<n2.x;
}
//�к���ͬ���������壬��С���ȣ��кŲ�ͬ���д�����
bool cmpb(node n1,node n2)
{
    if(n1.x==n2.x)
      return n1.y<n2.y;
   return n1.x>n2.x;
}
void find (int i,string str)
{
    for(int j=0;j<str.length();j++)
    {//cout<<j<<isupper(str[j])<<str[j]<<endl;
        if(isupper(str[j]))
        {
             if(str[j]=='P')//ͳ�ư�����P�ĸ���
                wp++;
             wn[wk].x=i/2+1;  //��iת�������ӵĺ�����
             //wn[wk].y=static_cast<char>(j/4+'a');
             wn[wk].y=(char)(j/4+'a');//��jת�������ӵ��ַ���������
             wn[wk++].letter=str[j];

        }

          if(islower(str[j]))
          {
              if(str[j]=='p')
                bp++;
             bn[bk].x=i/2+1;
            // bn[bk].y=static_cast<char>(j/4+'a');
             bn[bk].y=(char)(j/4+'a');
             bn[bk++].letter=str[j];
           }

    }
}
 int i;//��ʾ�к�
 int main()
 {
   string map[18],str;
   for( i=16 ;i>=0;i--) //������������
       {
           cin>>str;
           if(i%2!=0)   //�������н��д���
           {
               find(i,str);
           }
       }
       sort(wn,wn+wk,cmpw);
       sort(bn,bn+bk,cmpb);
       //�������
      cout<<"White: ";
      for(int j=0;j<6;j++)//����output�е�˳�����
           {
             for(i=0;i<wk;i++)
               {
               if(wn[i].letter==output[j])
               {
                  if(wn[i].letter!='P')//K,Q,R,B,N
                        cout<<wn[i].letter<<wn[i].y<<wn[i].x<<',';
                  else if(--wp)//P�ĸ���Ϊ0�������,
                  {
                        cout<<wn[i].y<<wn[i].x<<',';

                  } else
                  cout<<wn[i].y<<wn[i].x;
               }
           }
     }
     cout<<endl;
      cout<<"Black: ";
       for(int j=0;j<6;j++)//����output�е�˳�����
           {
             for(i=0;i<bk;i++)
               {
               if(bn[i].letter==tolower(output[j]))
               {
                  if(bn[i].letter!='p')//ע����Ҫת���ɴ�д��ĸ
                     cout<<static_cast<char>(bn[i].letter-32)<<bn[i].y<<bn[i].x<<',';
                else if(--bp)
                  {
                        cout<<bn[i].y<<bn[i].x<<',';

                  }else
                        cout<<bn[i].y<<bn[i].x;
               }
           }
     }cout<<endl;
   return 0;

 }


























