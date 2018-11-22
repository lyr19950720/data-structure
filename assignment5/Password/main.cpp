/*#include <iostream>
#include <string.h>
using namespace std;
int len; char post[100005];
string preo,ino;
void findpost(int spre,int epre,int sin,int ein,int spost,int epost)
{
    if(spre==epre)
    {
        post[epost]=preo[spre];
        return ;
    }
    int i;
    for(i=sin;i<=ein;i++)
    {
        if(preo[spre]==ino[i])
             break;
    }
    post[epost]=preo[spre];
    findpost(spre+1,spre+i,sin,sin+i-1,spost,spost+i-1);
    findpost(spre+i+1,epre,sin+i+1,ein,spost+i,epost-1);
}

int main()
{
    cin>>preo>>ino;
    len = preo.size();
    findpost(0,len-1,0,len-1,0,len-1);
    for(int i=0;i<len;i++)
         cout << post[i];
    cout<<endl;
    return 0;
}*/
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


