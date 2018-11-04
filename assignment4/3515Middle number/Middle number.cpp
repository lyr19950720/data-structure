/*#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<ctype.h>
#include<algorithm>
using namespace std;
int main()
{
	int T,N,M,temp;//T测试数目 N：输入的初始个数 M：输入的操作个数

	while(cin>>T)
	{
	   	int num[100005];
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>num[i];
		cin>>M;
		while(M--)
		{	string str;
		    cin>>str;
		
			if(str[0]=='a')
			{	
				cin>>temp;
				num[N++]=temp;
				
			}
			if(str[0]=='m')
			{
              sort(num,num+N);
			  if(N%2!=0)
				  cout<<num[N/2]<<endl;
			  else
				  cout<<num[(N-1)/2]<<endl;
			}

		}

	}
	return 0;
}*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
struct cmp1
{
 bool operator()(const int a, const int b) const
 {
       return a>b;
 }
};
struct cmp2
{
 bool operator()(const int a, const int b) const
 {
 return a<b;
 }
};
int main()
{
	int T, n, a[100005], m;
	cin >> T;
	while(T--)
	{  
		 int i, t;
		 priority_queue<int,vector<int>,cmp1>small;//堆顶值最小
		 priority_queue<int,vector<int>,cmp2>big;//堆顶值最大
		 cin >> n;
		 for( i=0; i<n; i++)
			cin >> a[i];
		 sort(a,a+n);
       //奇数的话存入大顶堆的数字比小顶堆的数字多一个
		if(n%2==1)
		{
			for(i=0; i<n/2+1; i++)
				big.push(a[i]);
		}else//输入的数据前一半入大顶堆
		{
			for(i=0; i<n/2; i++)
	    		big.push(a[i]);
		}
		//输入的数据后一半入小顶堆
		 for(;i<n; i++)
			small.push(a[i]);

		 cin >> m;//输入指令数目
		while(m--)
		{
			 string s;
			 cin >> s;//输入指令
			if(s[0] == 'a')//如果指令是add
			{
				cin >> t;   //获取添加的数字
				if(t < big.top()) //如果数字小于大顶堆的堆顶数字，入大顶堆
					big.push(t);
				else
					small.push(t); //如果数字大于大顶堆的堆顶数字，入小顶堆
               
				//以下这两部分是为了平衡大顶堆和小顶堆的数字个数，使得个数差小于2
				//同时 也是为了保证堆顶元素是序列的中间数字
				if(big.size()>small.size()+1)
				{
					int h = big.top();
					small.push(h);
					big.pop();
				}
				else if(big.size()<small.size())
				{
					int k = small.top();
					big.push(k);
					small.pop();
				}
			}else
				cout << big.top() << endl;
		}
	 }
 return 0;
}
