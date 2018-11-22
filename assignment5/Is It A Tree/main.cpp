/*#include <iostream>
#include <set>
using namespace std;


set <int> root;
set <int> froot;


void findRoot(set<int> & r, set<int> &fr){
    set<int>::iterator itfr;
    set<int>::iterator itf;
    for(itfr = fr.begin(); itfr!= fr.end(); itfr++){
        itf = r.find(*itfr);
        if(itf!=r.end())
            r.erase(*itf);
    }
}
int main()
{
    int u,v;
    int num = 0;
    set<int>::iterator it;
    bool b = true;
    while(1){
        cin >> u >> v;
        if(u==-1 && v==-1)
            break;
        if(u==0 && v==0){
            num++;
            findRoot(root,froot);
            if(froot.size()==0){
                cout <<  "Case " << num << " is a tree." << endl;
            }
            else if(root.size() != 1){
                cout <<  "Case " << num << " is not a tree." << endl;
            }
            else{
                if(b)
                    cout <<  "Case " << num << " is a tree." << endl;
                else
                    cout <<  "Case " << num << " is not a tree." << endl;
            }
            root.clear();
            froot.clear();
            b = true;
        }
        else{
            root.insert(u);
            it = froot.begin();
            it = froot.find(v);
            if(it != froot.end()){
                b = false;
            }
            else
                froot.insert(v);
        }
    }
    return 0;
}*/
#include <iostream>
#include <set>
using namespace std;
set <int> root;
set <int> froot;
//���ڷǸ�set����root�еĽڵ㣬����ҵ���˵�����Ǹ�Ȼ��ɾ��
void findRoot(set<int> & r, set<int> &fr){
    set<int>::iterator itfr;
    set<int>::iterator itr;
    for(itfr = fr.begin(); itfr!= fr.end(); itfr++){
        itr = r.find(*itfr);
        if(itr!=r.end())
            r.erase(*itr);
    }
}
int main()
{
    int s,e;
    int Case = 0;
    set<int>::iterator it;
    bool b = true;
    while(cin >> s >> e){
        if(s==-1 && e==-1)
            break;
        if(s==0 && e==0){
            Case++;
            findRoot(root,froot);
            if(froot.size()==0){
                cout <<  "Case " << Case << " is a tree." << endl;
            }
            else if(root.size() != 1){
                cout <<  "Case " << Case << " is not a tree." << endl;
            }
            else{
                if(b)
                    cout <<  "Case " << Case << " is a tree." << endl;
                else
                    cout <<  "Case " << Case << " is not a tree." << endl;
            }
            root.clear();
            froot.clear();
            b = true;
        }
        else{
            root.insert(s); //��������root
            it = froot.begin();
            it = froot.find(e);//��froot�в��Ҳ���㣬����ҵ�˵���õ㲻��ֻ��һ��ǰ��
            if(it != froot.end())
			{
                b = false;
            }
            else
                froot.insert(e);//�յ����root
        }
    }
    return 0;
}
