#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include<string>
using namespace std;
int j;
//定义结构体，包含棋子的坐标和字母名
struct node
{
  int x;char y;
  char letter;
};
node wn[16];//存放白棋的节点
node bn[16];//存放黑棋的节点
char output[6]={'K','Q','R','B','N','P'};//输出的顺序按outout数组中的顺序
//wk白棋的个数bk黑棋的个数wp白棋中P的个数bp黑棋中p的个数
int  wk=0,bk=0,wp=0,bp=0;
//行号相同的两个白棋，列小优先，行号不同的行小优先
bool cmpw(node n1,node n2)
{
    if(n1.x==n2.x)
      return n1.y<n2.y;
   return n1.x<n2.x;
}
//行号相同的两个黑棋，列小优先，行号不同的行大优先
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
             if(str[j]=='P')//统计白棋中P的个数
                wp++;
             wn[wk].x=i/2+1;  //将i转换成棋子的横坐标
             //wn[wk].y=static_cast<char>(j/4+'a');
             wn[wk].y=(char)(j/4+'a');//将j转换成棋子的字符型纵坐标
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
 int i;//表示行号
 int main()
 {
   string map[18],str;
   for( i=16 ;i>=0;i--) //按行逆序输入
       {
           cin>>str;
           if(i%2!=0)   //对奇数行进行处理
           {
               find(i,str);
           }
       }
       sort(wn,wn+wk,cmpw);
       sort(bn,bn+bk,cmpb);
       //控制输出
      cout<<"White: ";
      for(int j=0;j<6;j++)//按照output中的顺序输出
           {
             for(i=0;i<wk;i++)
               {
               if(wn[i].letter==output[j])
               {
                  if(wn[i].letter!='P')//K,Q,R,B,N
                        cout<<wn[i].letter<<wn[i].y<<wn[i].x<<',';
                  else if(--wp)//P的个数为0，不输出,
                  {
                        cout<<wn[i].y<<wn[i].x<<',';

                  } else
                  cout<<wn[i].y<<wn[i].x;
               }
           }
     }
     cout<<endl;
      cout<<"Black: ";
       for(int j=0;j<6;j++)//按照output中的顺序输出
           {
             for(i=0;i<bk;i++)
               {
               if(bn[i].letter==tolower(output[j]))
               {
                  if(bn[i].letter!='p')//注意需要转换成大写字母
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


























