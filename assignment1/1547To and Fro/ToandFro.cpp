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
                str2+= str.substr(i,n);//substr()���ƴ�i-n���ַ���
            }
            else{
                string temp = str.substr(i,n);
                str2+=string(temp.rbegin(),temp.rend());
//c.rbegin() ����һ���������������ָ������c�����һ��Ԫ��
//c.rend() ����һ���������������ָ������c�ĵ�һ��Ԫ��ǰ���λ��
            }
        }
        for(int i=0; i<n;i++){//��
            for(int j=0;j<str2.length()/n;j++){//��
                cout << str2[i+j*n];
            }

        }
        cout << endl;
    }

    return 0;
}