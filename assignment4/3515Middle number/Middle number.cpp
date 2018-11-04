/*#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<ctype.h>
#include<algorithm>
using namespace std;
int main()
{
	int T,N,M,temp;//T������Ŀ N������ĳ�ʼ���� M������Ĳ�������

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
		 priority_queue<int,vector<int>,cmp1>small;//�Ѷ�ֵ��С
		 priority_queue<int,vector<int>,cmp2>big;//�Ѷ�ֵ���
		 cin >> n;
		 for( i=0; i<n; i++)
			cin >> a[i];
		 sort(a,a+n);
       //�����Ļ�����󶥶ѵ����ֱ�С���ѵ����ֶ�һ��
		if(n%2==1)
		{
			for(i=0; i<n/2+1; i++)
				big.push(a[i]);
		}else//���������ǰһ����󶥶�
		{
			for(i=0; i<n/2; i++)
	    		big.push(a[i]);
		}
		//��������ݺ�һ����С����
		 for(;i<n; i++)
			small.push(a[i]);

		 cin >> m;//����ָ����Ŀ
		while(m--)
		{
			 string s;
			 cin >> s;//����ָ��
			if(s[0] == 'a')//���ָ����add
			{
				cin >> t;   //��ȡ��ӵ�����
				if(t < big.top()) //�������С�ڴ󶥶ѵĶѶ����֣���󶥶�
					big.push(t);
				else
					small.push(t); //������ִ��ڴ󶥶ѵĶѶ����֣���С����
               
				//��������������Ϊ��ƽ��󶥶Ѻ�С���ѵ����ָ�����ʹ�ø�����С��2
				//ͬʱ Ҳ��Ϊ�˱�֤�Ѷ�Ԫ�������е��м�����
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
