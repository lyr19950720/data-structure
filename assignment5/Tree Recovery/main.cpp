#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

char post[30];  //保存后序遍历序列
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
		int tt = in.find(pre[0]);//根在终须中的位置
		solve(pre.substr(1, tt), in.substr(0, tt));  //左子树的后序遍历
		solve(pre.substr(tt + 1, pre.length() - tt - 1), in.substr(tt + 1, in.length() - tt - 1));   //右子树的后序遍历
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
