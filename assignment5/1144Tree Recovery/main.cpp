#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

char post[30];  //��������������
int t = 0;

void solve(string pre, string in)
{
	if (pre.length() == 0) return;
	else if (pre.length() == 1)
	{
		post[t++] = pre[0];
		return;
	}
	else {
		int tt = in.find(pre[0]);//���������е�λ��
		solve(pre.substr(1, tt), in.substr(0, tt));  //�������ĺ������
		solve(pre.substr(tt + 1, pre.length() - tt - 1), in.substr(tt + 1, in.length() - tt - 1));   //�������ĺ������
		post[t++] = pre[0];
	}
}
int main()
{
	string pre, in;
	while (cin >> pre >> in)
	{
		int len = pre.length();
		t = 0;
		solve(pre, in);
		post[len] = '\0';
		cout << post << endl;
	}
	return 0;
}
