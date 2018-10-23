#include <iostream>

using namespace std;

int main()
{
    int n;
    string str,str2;
    while(cin>>n && n){
        cin >> str;
        str2 = "";
        for(int i=0;i<str.length(); i+=n){
            if(i/n%2 == 0){
                str2+= str.substr(i,n);//substr()复制从i-n的字符串
            }
            else{
                string temp = str.substr(i,n);
                str2+=string(temp.rbegin(),temp.rend());
//c.rbegin() 返回一个逆序迭代器，它指向容器c的最后一个元素
//c.rend() 返回一个逆序迭代器，它指向容器c的第一个元素前面的位置
            }
        }
        for(int i=0; i<n;i++){//列
            for(int j=0;j<str2.length()/n;j++){//行
                cout << str2[i+j*n];
            }

        }
        cout << endl;
    }

    return 0;
}