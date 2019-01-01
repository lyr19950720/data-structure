#include <iostream>
#include <stack>
#include <cctype>
#include <set>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
stack<int> s;
int main()
{
    string str;
    while(getline(cin,str))
    {
        set<int> a[55];
        int n=0;int i,j;
        for( i=0;i<str.size();i++)
        {
            if(str[i]=='('||str[i]==' '){}
            else if(isdigit(str[i]))
            {
                 int num = str[i]-'0';
                 while(isdigit(str[i+1])){
                    num = 10 * num + (str[i+1]-'0');
                    i++;
                 }
                 s.push(num);
            }
            else if(str[i]==')')
            {
                if(!s.empty())
                {

                   int t=s.top();
                   s.pop();
                  if(!s.empty())//判断数字已经全部出栈
                   {
                       a[s.top()].insert(t);
                       a[t].insert(s.top());
                   }
                }
                n++;
            }
        }
        if(n==1)
		{
            cout << endl;
            continue;
        }
        for(j=0; j<n-1;j++)

		    for(i=1;i<=55;i++)
				{
					if(a[i].size()==1)
					{
						int c=*(a[i].begin());
						if (j<n-2)
							cout << c << " ";
						else
							cout << c << endl;
						a[i].clear();
						a[c].erase(i);
						break;
					}
				}


    }
    return 0;
}
