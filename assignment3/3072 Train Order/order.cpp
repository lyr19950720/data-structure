#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int a[10];
int f(int *a,int n)//�ж��ǲ��Ǻ���ĳ�ջ˳���ǵĻ�����1���򷵻�0
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
	int m,n;	//m:���Ե�����n:���Լ������ĺ����ջ
	cin>>m;	
	while(m--)
	{		
		cin>>n;		
		for(int i=0;i<n;i++)
		{			
			a[i]=i+1;		//�����Եĳ�0�����Ȼ������a����		
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
����next_permutation�������亯��ԭ��Ϊ��

     #include <algorithm>

     bool next_permutation(iterator start,iterator end)

����ǰ���в�������һ������ʱ����������false�����򷵻�true
next_permutation(num,num+n)�����Ƕ�����num�е�ǰn��Ԫ�ؽ���ȫ���У�ͬʱ���ı�num�����ֵ��
��Ҫǿ�����ǣ�next_permutation������ʹ��ǰ��Ҫ�����������鰴�������򣬷���ֻ���ҳ�������֮���ȫ��������
*/