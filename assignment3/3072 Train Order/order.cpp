#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int a[10];
int f(int *a,int n)//判断是不是合理的出栈顺序，是的话返回1否则返回0
{
	stack<int> s;	
	int k=0;
	for(int i=1;i<=n;i++)
	{	
		s.push(i);		
		if(i==a[k])
		{		
			while(!s.empty()&&s.top()==a[k])
			{				
				s.pop();				
				k++;			
			}		
		}	
	}		
		return s.empty();	

}
int main()
{	
	int m,n;	//m:测试的组数n:测试几个数的合理出栈
	cin>>m;	
	while(m--)
	{		
		cin>>n;		
		for(int i=0;i<n;i++)
		{			
			a[i]=i+1;		//将测试的除0外的自然数存入a数组		
		}				
		do
		{			
			if(f(a,n))
			{				
				for(int j=0;j<n;j++)					
					cout<<a[j];				
				cout<<endl;			
			}		
	}	while(next_permutation(a,a+n));
	
	}	
	return 0;
}


/*
对于next_permutation函数，其函数原型为：

     #include <algorithm>

     bool next_permutation(iterator start,iterator end)

当当前序列不存在下一个排列时，函数返回false，否则返回true
next_permutation(num,num+n)函数是对数组num中的前n个元素进行全排列，同时并改变num数组的值。
需要强调的是，next_permutation（）在使用前需要对欲排列数组按升序排序，否则只能找出该序列之后的全排列数。
*/