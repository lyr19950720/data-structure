#include <iostream>
#include <list>
#include <string.h>
#include <algorithm>
using namespace std;

typedef list<pair<string,string> > LISTSTRING; //存储原word和排序后的word，相当于把两个list合成了一个

typedef list<pair<string,int> > LISTNUM;//存储相同单词数的group
char temp[30000][10][40];
int num[30000];
bool cmp(const pair<string,string> &p1,const pair<string,string> &p2){
    if(p1.second != p2.second)
        return p1.second < p2.second;
    else
        return p1.first<p2.first;
}
int main()
{
    LISTSTRING listword;
    string str;
    while (cin >> str){
        string tmp = str;
        sort(tmp.begin(),tmp.end());
        listword.push_back(pair<string,string>(str,tmp));
    }

    listword.sort(cmp);
    LISTSTRING::iterator it;
    int n=0;
    for(it=listword.begin(); it!=listword.end(); ){
        string str = it->second;
        int sizes=0;
        while(it->second == str){
            strcpy(temp[n][sizes++],it->first.c_str());
            it++;
        }
        num[n] = sizes;
        n++;
    }
    for(int i=0; i<5; ){
        int k = 0;
        int maxNum = 0;
        for (int j=0; j<n; j++){
            if(maxNum<num[j]){
                maxNum = num[j];
                k=j;
            }
        }
        if(num[k] == 0)
            break;
        LISTNUM listNum;
        for (int j=0; j<n; j++){
            if(num[j] == maxNum)
                listNum.push_back(make_pair(temp[j][0],j));
        }
        listNum.sort();
        list<pair <string,int> >::iterator it2;
        for(it2=listNum.begin(); it2!=listNum.end(); it2++){
            k = it2->second;
            cout << "Group of size " << num[k] << ": ";
            for (int m=0; m<num[k]; m++){
                if(m>0 && !strcmp(temp[k][m],temp[k][m-1])){

                }
                else{
                    cout << temp[k][m] <<" ";
                }
            }
            cout << "." << endl;
            num[k] = 0;
            i++;
            if(i>=5)
                break;
        }
    }
    return 0;
}
