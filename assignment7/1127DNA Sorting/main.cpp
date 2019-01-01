#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<vector>
using namespace std;

int main()
{
    int strn,strl;
    string str[110];
    scanf("%d%d",&strl,&strn);
    map<vector<int>,string> mp;
    for(int i=0;i<strn;i++)
    {
        int cnt=0;
        cin>>str[i];
        vector<int>vec;
        for(int j=0; j<strl; j++)
        {
           if(str[i][j]=='A')
                continue;
            for (int k = j+1; k<strl; k++)
            {
              if (str[i][j]>str[i][k])
                cnt++;
            }
        }
        vec.push_back(cnt);
        vec.push_back(i);//判断是否有重复数据。
        mp[vec]=str[i];
    }
    map<vector<int>,string>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
        cout<<it->second<<endl;
    return 0;
}

